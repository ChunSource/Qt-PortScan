#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scan.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>
#include <QPainter>
#include <QMouseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setAreaMovable(const QRect rt);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    
private:
    Ui::MainWindow *ui;
    QString textEdit;
    Scan *scan;
    Scan *temp;
    
    float processBar = 0;
    int processBarCode;
    bool now = false;
    
    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
    bool m_bPressed;//鼠标按下标志（不分左右键）
    QPoint m_ptPress;//鼠标按下的初始位置
private slots:
    void start();
    void stop();
    void exportReslut();
    void returnResult(QString ip, int port, int code);
    void shutDown();
    void changeProcessBar(int port);
    void clearEdit();
   /* 
 void paintEvent(QPaintEvent *event)
 {
     QPainter painter(this);
     painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
     painter.setBrush(QBrush(Qt::white));
     painter.setPen(Qt::transparent);
     QRect rect = this->rect();
     rect.setWidth(rect.width() - 1);
     rect.setHeight(rect.height() - 1);
     painter.drawRoundedRect(rect, 15, 15);
     QMainWindow::paintEvent(event);
     QWidget::paintEvent(event);
 }
 */
};

#endif // MAINWINDOW_H
