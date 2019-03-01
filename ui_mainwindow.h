/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *exportButton;
    QRadioButton *currentipRadio;
    QLineEdit *targetEdit;
    QTextEdit *reslutEdit;
    QLineEdit *portEdit;
    QRadioButton *currentPort;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_3;
    QLabel *currentScanLabel;
    QSpinBox *TimeOutBox;
    QLabel *TimeOutLabel;
    QPushButton *clearButton;
    QGroupBox *groupBox;
    QPushButton *MiniSizeButton;
    QPushButton *MaxSizeButton;
    QPushButton *CloseButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(775, 538);
        MainWindow->setMinimumSize(QSize(775, 538));
        MainWindow->setMaximumSize(QSize(9999, 9999));
        QIcon icon;
        icon.addFile(QStringLiteral("ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(30, 70, 75, 23));
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(110, 70, 75, 23));
        exportButton = new QPushButton(centralWidget);
        exportButton->setObjectName(QStringLiteral("exportButton"));
        exportButton->setGeometry(QRect(190, 70, 75, 23));
        currentipRadio = new QRadioButton(centralWidget);
        currentipRadio->setObjectName(QStringLiteral("currentipRadio"));
        currentipRadio->setGeometry(QRect(450, 190, 121, 31));
        targetEdit = new QLineEdit(centralWidget);
        targetEdit->setObjectName(QStringLiteral("targetEdit"));
        targetEdit->setGeometry(QRect(480, 130, 171, 20));
        reslutEdit = new QTextEdit(centralWidget);
        reslutEdit->setObjectName(QStringLiteral("reslutEdit"));
        reslutEdit->setGeometry(QRect(10, 110, 421, 371));
        portEdit = new QLineEdit(centralWidget);
        portEdit->setObjectName(QStringLiteral("portEdit"));
        portEdit->setGeometry(QRect(500, 230, 171, 20));
        currentPort = new QRadioButton(centralWidget);
        currentPort->setObjectName(QStringLiteral("currentPort"));
        currentPort->setGeometry(QRect(450, 220, 121, 31));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 500, 671, 23));
        progressBar->setValue(0);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(440, 130, 31, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(460, 420, 131, 51));
        label_3->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";"));
        currentScanLabel = new QLabel(centralWidget);
        currentScanLabel->setObjectName(QStringLiteral("currentScanLabel"));
        currentScanLabel->setGeometry(QRect(610, 420, 41, 51));
        currentScanLabel->setStyleSheet(QString::fromUtf8("font: 13pt \"\351\273\221\344\275\223\";"));
        TimeOutBox = new QSpinBox(centralWidget);
        TimeOutBox->setObjectName(QStringLiteral("TimeOutBox"));
        TimeOutBox->setGeometry(QRect(520, 300, 81, 21));
        TimeOutBox->setMinimum(10);
        TimeOutBox->setMaximum(9999999);
        TimeOutBox->setValue(100);
        TimeOutLabel = new QLabel(centralWidget);
        TimeOutLabel->setObjectName(QStringLiteral("TimeOutLabel"));
        TimeOutLabel->setGeometry(QRect(450, 290, 61, 31));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(270, 70, 111, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(440, 170, 261, 91));
        MiniSizeButton = new QPushButton(centralWidget);
        MiniSizeButton->setObjectName(QStringLiteral("MiniSizeButton"));
        MiniSizeButton->setGeometry(QRect(490, 20, 51, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resizeApi.png"), QSize(), QIcon::Normal, QIcon::Off);
        MiniSizeButton->setIcon(icon1);
        MaxSizeButton = new QPushButton(centralWidget);
        MaxSizeButton->setObjectName(QStringLiteral("MaxSizeButton"));
        MaxSizeButton->setGeometry(QRect(550, 20, 51, 41));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/mini.png"), QSize(), QIcon::Normal, QIcon::Off);
        MaxSizeButton->setIcon(icon2);
        CloseButton = new QPushButton(centralWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(620, 20, 51, 41));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        CloseButton->setIcon(icon3);
        MainWindow->setCentralWidget(centralWidget);
        groupBox->raise();
        currentPort->raise();
        startButton->raise();
        stopButton->raise();
        exportButton->raise();
        currentipRadio->raise();
        targetEdit->raise();
        reslutEdit->raise();
        portEdit->raise();
        progressBar->raise();
        label->raise();
        label_3->raise();
        currentScanLabel->raise();
        TimeOutBox->raise();
        TimeOutLabel->raise();
        clearButton->raise();
        MiniSizeButton->raise();
        MaxSizeButton->raise();
        CloseButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ChunSource --\350\275\273\351\207\217\347\272\247\346\211\253\346\217\217\345\231\250", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        stopButton->setText(QApplication::translate("MainWindow", "stop", Q_NULLPTR));
        exportButton->setText(QApplication::translate("MainWindow", "export", Q_NULLPTR));
        currentipRadio->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215ip", Q_NULLPTR));
        currentPort->setText(QApplication::translate("MainWindow", "port", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ip", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\211\253\346\217\217\347\253\257\345\217\243:", Q_NULLPTR));
        currentScanLabel->setText(QString());
        TimeOutLabel->setText(QApplication::translate("MainWindow", "\350\266\205\346\227\266\346\227\266\351\227\264", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "clear reslut", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\274\217", Q_NULLPTR));
        MiniSizeButton->setText(QString());
        MaxSizeButton->setText(QString());
        CloseButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
