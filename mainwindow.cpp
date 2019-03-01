#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBitmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MaxSizeButton->setAutoFillBackground(true);
    ui->MaxSizeButton->setFlat(true);
    ui->MiniSizeButton->setAutoFillBackground(true);
    ui->MiniSizeButton->setFlat(true);
    ui->CloseButton->setAutoFillBackground(true);
    ui->CloseButton->setFlat(true);
    
    ui->startButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->stopButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->exportButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->clearButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->targetEdit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->reslutEdit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->portEdit->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->TimeOutBox->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->groupBox->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    
    connect(ui->startButton,&QPushButton::clicked,this,&MainWindow::start);
    connect(ui->stopButton,&QPushButton::clicked,this,&MainWindow::stop);
    connect(ui->exportButton,&QPushButton::clicked,this,&MainWindow::exportReslut);
    connect(ui->clearButton,&QPushButton::clicked,this,&MainWindow::clearEdit);
    
    
    connect(ui->MaxSizeButton,&QPushButton::clicked,this,[=]()
    {
            if(now == false)
                {
                    now =true;
                    showMaximized();
                }else
                {
                    now =false;
                    showNormal();
                }

        });
    connect(ui->MiniSizeButton,&QPushButton::clicked,this,[=]()
    {
            showMinimized();
        });
    connect(ui->CloseButton,&QPushButton::clicked,this,[=]()
    {
            this->close();
        });
 //   this->setWindowTitle(QString("雷锋专用 --轻量级扫描器").toLocal8Bit());
    
//    this->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
    this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口
//    this->setStyleSheet("QMainWindow{border-top-left-radius:20px;border-top-right-radius:20px;border-bottom-left-radius:20px;border-bottom-right-radius:20px}"); 
    
    m_areaMovable = geometry();
    m_bPressed = false;
    
    
    QBitmap bmp(this->size());

    bmp.fill();

    QPainter p(&bmp);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);

    p.setBrush(Qt::black);

    p.drawRoundedRect(bmp.rect(),20,20);

    setMask(bmp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    int timeout = ui->TimeOutBox->text().toInt();
    qDebug()<<"timeout "<<timeout;
    Scan *s;
    QString target = ui->targetEdit->text();
    
    if(ui->currentipRadio->isChecked())
        {
            qDebug()<<"is currenti ip";
           s= new Scan(timeout,target,0);
           processBarCode = 0;
        }
    else
        {
            if(ui->currentPort->isChecked())
                {
                    
                    if(ui->portEdit->text().indexOf(","))
                        {
                            s =new Scan(timeout,target,2,0,ui->portEdit->text());
                            processBarCode = 2;
                        }
                    else
                        {
                     //       int number = ui->portEdit->text().toInt();
                            s =new Scan(timeout,target,2,0,ui->portEdit->text());
                            processBarCode = 2;
                        }
                    
                }
            else
                {
                    processBarCode = 1;
                    s= new Scan(timeout,target,1);
                }
        }
    temp =s;
    connect(s,&Scan::exist,this,&MainWindow::returnResult);
    connect(s,&Scan::shutdown,this,&MainWindow::shutDown);
    connect(s,&Scan::process,this,&MainWindow::changeProcessBar);
//    s->go();
    s->start();
    scan = s;
}

void MainWindow::stop()
{
    shutDown();
    qDebug()<<"stop";
}

void MainWindow::exportReslut()
{
    QString saveFileName = QFileDialog::getSaveFileName(this, "Save Log",
                                                        QDir::current().absoluteFilePath("log.txt"),"文本(*.txt)",
                                                        0, QFileDialog::ShowDirsOnly);
    
    QFile file(saveFileName);
    file.open( QIODevice::ReadWrite | QIODevice::Text );  
    QTextStream data(&file);
    data << ui->reslutEdit->toPlainText();
    file.close();
    
}

void MainWindow::returnResult(QString ip, int port, int code)
{
    QString now = QString::number(port);
    if(code == 0)
        {
            QString Separate = "--------------------------------------------";
            QString New = "[*] "+ ip+"\n";
            QString tempPort = "      open  "+now+"\n";
            textEdit  = textEdit + Separate;
            textEdit  = textEdit + New;
            textEdit  = textEdit + tempPort;
            ui->reslutEdit->setText(textEdit);
        }
    if(code == 1)
        {
            QString tempPort = "      open  "+now+"\n";
            textEdit  = textEdit + tempPort;
            ui->reslutEdit->setText(textEdit);
        }
}

void MainWindow::shutDown()
{
    temp->pool = false;
    QThread::msleep(1000);
    temp->deleteLater();
    temp = NULL;
    qDebug()<<"shutdown ";
    if(temp == NULL)
        {
            qDebug()<<"shutdown finsh";
        }
}

void MainWindow::changeProcessBar(int port)
{
    if(processBarCode == 0)
        {
            processBar = processBar+0.0015;
            ui->progressBar->setValue(processBar);
            ui->currentScanLabel->setText(QString::number(port));
        }
    if(processBarCode == 2)
        {
            ui->progressBar->setValue(100);
        }
    if(processBarCode == 1)
        {
            processBar = processBar +0.392;
            ui->progressBar->setValue(100);
            ui->currentScanLabel->setText(QString::number(port));
        }
}

void MainWindow::clearEdit()
{
    ui->reslutEdit->clear();
    ui->progressBar->setValue(0);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
  //鼠标左键
  if(e->button() == Qt::LeftButton)
  {
  m_ptPress = e->pos();
  m_bPressed = m_areaMovable.contains(m_ptPress);
  }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
  if(m_bPressed)
  {
  move(pos() + e->pos() - m_ptPress);
  }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
  m_bPressed = false;
}

//设置鼠标按下的区域
void MainWindow::setAreaMovable(const QRect rt)
{
  if(m_areaMovable != rt)
  {
  m_areaMovable = rt;
  }
}
