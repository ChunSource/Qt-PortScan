#ifndef SCAN_H
#define SCAN_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QTimer>
#include <QHostAddress>
#include <QStringList>

class Scan : public QThread
    {
        Q_OBJECT
    public:
        explicit Scan(int time,QString ip, int code, int port=0, QString much="",QObject *parent = nullptr);
        bool pool =  true;
    signals:
        void exist(QString,int,int now = 1);
        void shutdown();
        void process(int);
    public slots:
        void run();
        void go();
        void test();
    private:
       QTcpSocket *socket;
       
       QString myIp;
       int timeOut = 500;
        int myStatic;
        int myPort;
        QString muchPort;
        QStringList list;
    };

#endif // SCAN_H
