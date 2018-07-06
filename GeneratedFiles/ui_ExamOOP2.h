/********************************************************************************
** Form generated from reading UI file 'ExamOOP2.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMOOP2_H
#define UI_EXAMOOP2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamOOP2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ExamOOP2Class)
    {
        if (ExamOOP2Class->objectName().isEmpty())
            ExamOOP2Class->setObjectName(QStringLiteral("ExamOOP2Class"));
        ExamOOP2Class->resize(600, 400);
        menuBar = new QMenuBar(ExamOOP2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ExamOOP2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ExamOOP2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ExamOOP2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(ExamOOP2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ExamOOP2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ExamOOP2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ExamOOP2Class->setStatusBar(statusBar);

        retranslateUi(ExamOOP2Class);

        QMetaObject::connectSlotsByName(ExamOOP2Class);
    } // setupUi

    void retranslateUi(QMainWindow *ExamOOP2Class)
    {
        ExamOOP2Class->setWindowTitle(QApplication::translate("ExamOOP2Class", "ExamOOP2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExamOOP2Class: public Ui_ExamOOP2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMOOP2_H
