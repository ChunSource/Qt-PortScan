#include "scan.h"
#include <QDebug>

Scan::Scan(int time, QString ip, int code, int port, QString much, QObject *parent) : QThread(parent)
{
    qDebug()<<"new Thread  ";//<<currentThreadId();

    this->myStatic = code;
    this->myPort = port;
    this->muchPort = much;
    this->timeOut = time;
    this->myIp = ip;
    qDebug()<<this->myIp;
    qDebug()<<this->myPort;
    qDebug()<<this->myStatic;
    qDebug()<<this->timeOut;

}

void Scan::go()
{
    QTcpSocket *client =new QTcpSocket();
    socket = client;
    connect(socket,&QTcpSocket::connected,this,&Scan::test);
    go();
}

void Scan::run()
{
    QTcpSocket *client =new QTcpSocket();
    socket = client;
    connect(socket,&QTcpSocket::connected,this,&Scan::test);
    
    qDebug()<<" start  ";
    if(this->myStatic == 0)
        {
            qDebug()<<"0";
            for(int i=1;i<65536;i++)
                {
                    if(pool == false)
                        {
                            return;
                        }
                    emit process(i);
                    socket->connectToHost(QHostAddress(this->myIp),i);
                    if(socket->waitForConnected(this->timeOut))
                        {
                            if(i==1)
                                {
                                    qDebug()<<"exist  "<<this->myIp<<"  port  "<<i<<" static  "<<0;
                                }
                            else
                                {
                                     qDebug()<<"exist  "<<this->myIp<<"  port  "<<i<<" static  "<<1;
                                }
                            emit exist(this->myIp,i,0);
                            socket->disconnectFromHost();
                        }
                    if(i == 65535)
                        {
                            emit shutdown();
                        }
                }
        }
    if(this->myStatic == 1)
        {
            qDebug()<<"1";
            int find = this->myIp.lastIndexOf(".");
            QString sum = this->myIp.mid(0,find-1);
            
            for(int ip =1;ip<255;ip++)
                {
                    QString temp = sum;
                    temp =temp+"."+QString::number(ip);
                    qDebug()<<"sum  "<<sum;
                    emit process(ip);
                    for(int i=1;i<65536;i++)
                        {
                            if(pool == false)
                                {
                                    return;
                                }
                            qDebug()<<"current ip"<<ip<<"current port "<<i;
                            socket->connectToHost(QHostAddress(temp),i);
                            if(socket->waitForConnected(this->timeOut))
                                {
                                    if(i==1)
                                        {
                                            qDebug()<<"exist  "<<temp<<"  port  "<<i<<" static  "<<0;
                                            emit exist(temp,i,0);
                                        }
                                    else
                                        {
                                            qDebug()<<"exist  "<<temp<<"  port  "<<i<<" static  "<<1;
                                            emit exist(temp,i);
                                        }
                                    socket->disconnectFromHost();
                                }
                            if(i == 65535)
                                {
                                    emit shutdown();
                                }
                            
                        }
                }
            
            
        }
    
    if(this->myStatic ==2)
        {
            if(this->muchPort.indexOf(",") != -1)
                {
                    list = this->muchPort.split(",");
                    for(int i=0;i<list.size();i++)
                        {
                            if(pool == false)
                                {
                                    return;
                                }
                            QString onePort = list.at(i);
                            socket->connectToHost(QHostAddress(this->myIp),onePort.toInt());
                            if(socket->waitForConnected(this->timeOut))
                                {
                                    qDebug()<<"exist  "<<this->myIp<<"  port  "<<onePort<<" static  "<<0;
                                    int pPort = onePort.toInt();
                                    emit exist(this->myIp,pPort,0);
                                    socket->disconnectFromHost();
                                }
                            emit process(onePort.toInt());
                        }
                    emit shutdown();
                    return;
                }
            else
                {
                    socket->connectToHost(QHostAddress(this->myIp),this->muchPort.toInt());
                    if(socket->waitForConnected(this->timeOut))
                        {
                            qDebug()<<"exist  "<<this->myIp<<"  port  "<<this->muchPort<<" static  "<<0;
                            emit exist(this->myIp,this->muchPort.toInt(),0);
                            socket->disconnectFromHost();
                        }
                    emit process(this->muchPort.toInt());
                    emit shutdown();
                }
            
            qDebug()<<"connect to   "<<this->myPort;
            socket->connectToHost(QHostAddress(this->myIp),this->myPort);
            if(socket->waitForConnected(this->timeOut))
                {
                    qDebug()<<"exist  "<<this->myIp<<"  port  "<<this->myPort<<" static  "<<0;
                    emit exist(this->myIp,this->myPort,0);
                    socket->disconnectFromHost();
                    emit shutdown();
                }
        }
}

void Scan::test()
{
    qDebug()<<"test";
}
