#include "mainwindow.h"
#include <QApplication>
#include <windows.h>
#include <QProcess>
LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException){//程式异常捕获

    //这里弹出一个错误对话框并退出程序
    EXCEPTION_RECORD* record = pException->ExceptionRecord;
    QString errCode(QString::number(record->ExceptionCode,16)),errAdr(QString::number((uint)record->ExceptionAddress,16)),errMod;
  //  QMessageBox::critical(NULL,"程式崩溃","<FONT size=4><div><b>对于发生的错误，表示诚挚的歉意</b><br/></div>"+
   //     QString("<div>错误代码：%1</div><div>错误地址：%2</div></FONT>").arg(errCode).arg(errAdr),
  //      QMessageBox::Ok);
    qApp->exit();
    
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    return EXCEPTION_EXECUTE_HANDLER;
}
int main(int argc, char *argv[])
{
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
