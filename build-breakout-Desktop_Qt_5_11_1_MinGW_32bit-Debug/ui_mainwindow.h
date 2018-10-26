/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <breakout.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Breakout *breakout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *positp1;
    QLabel *label_5;
    QLabel *positball;
    QLabel *label_9;
    QLabel *positp2;
    QLabel *label_3;
    QLabel *scrp1;
    QLabel *label;
    QLabel *nballs;
    QLabel *label_10;
    QLabel *scrp2;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(541, 638);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        breakout = new Breakout(centralwidget);
        breakout->setObjectName(QStringLiteral("breakout"));
        breakout->setGeometry(QRect(20, 10, 500, 400));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(breakout->sizePolicy().hasHeightForWidth());
        breakout->setSizePolicy(sizePolicy1);
        breakout->setFocusPolicy(Qt::StrongFocus);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 470, 500, 65));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        positp1 = new QLabel(groupBox);
        positp1->setObjectName(QStringLiteral("positp1"));

        gridLayout->addWidget(positp1, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        positball = new QLabel(groupBox);
        positball->setObjectName(QStringLiteral("positball"));

        gridLayout->addWidget(positball, 0, 3, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 4, 1, 1);

        positp2 = new QLabel(groupBox);
        positp2->setObjectName(QStringLiteral("positp2"));

        gridLayout->addWidget(positp2, 0, 5, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        scrp1 = new QLabel(groupBox);
        scrp1->setObjectName(QStringLiteral("scrp1"));

        gridLayout->addWidget(scrp1, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        nballs = new QLabel(groupBox);
        nballs->setObjectName(QStringLiteral("nballs"));

        gridLayout->addWidget(nballs, 1, 3, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 1, 4, 1, 1);

        scrp2 = new QLabel(groupBox);
        scrp2->setObjectName(QStringLiteral("scrp2"));

        gridLayout->addWidget(scrp2, 1, 5, 1, 1);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 430, 500, 22));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 541, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Status", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Posi\303\247\303\243o P1:", nullptr));
        positp1->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Posi\303\247\303\243o da Bola:", nullptr));
        positball->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Posi\303\247\303\243o P2:", nullptr));
        positp2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Pontos P1:", nullptr));
        scrp1->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Bolas:", nullptr));
        nballs->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Pontos P2:", nullptr));
        scrp2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
