/********************************************************************************
** Form generated from reading UI file 'IssueTracker.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISSUETRACKER_H
#define UI_ISSUETRACKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IssueTracker
{
public:
    QListWidget *issueList;
    QPushButton *AddButton;
    QLabel *label;
    QPushButton *RemoveButton;
    QLabel *label_2;
    QPushButton *resolveButton;
    QLineEdit *descriptionBox;

    void setupUi(QWidget *IssueTracker)
    {
        if (IssueTracker->objectName().isEmpty())
            IssueTracker->setObjectName(QStringLiteral("IssueTracker"));
        IssueTracker->resize(508, 420);
        issueList = new QListWidget(IssueTracker);
        issueList->setObjectName(QStringLiteral("issueList"));
        issueList->setGeometry(QRect(30, 20, 241, 311));
        AddButton = new QPushButton(IssueTracker);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setGeometry(QRect(390, 90, 91, 31));
        label = new QLabel(IssueTracker);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 90, 91, 31));
        RemoveButton = new QPushButton(IssueTracker);
        RemoveButton->setObjectName(QStringLiteral("RemoveButton"));
        RemoveButton->setGeometry(QRect(390, 140, 91, 31));
        label_2 = new QLabel(IssueTracker);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 140, 81, 31));
        resolveButton = new QPushButton(IssueTracker);
        resolveButton->setObjectName(QStringLiteral("resolveButton"));
        resolveButton->setGeometry(QRect(100, 360, 101, 31));
        descriptionBox = new QLineEdit(IssueTracker);
        descriptionBox->setObjectName(QStringLiteral("descriptionBox"));
        descriptionBox->setGeometry(QRect(312, 19, 171, 51));

        retranslateUi(IssueTracker);

        QMetaObject::connectSlotsByName(IssueTracker);
    } // setupUi

    void retranslateUi(QWidget *IssueTracker)
    {
        IssueTracker->setWindowTitle(QApplication::translate("IssueTracker", "IssueTracker", nullptr));
        AddButton->setText(QApplication::translate("IssueTracker", "Add", nullptr));
        label->setText(QApplication::translate("IssueTracker", "Report Issue", nullptr));
        RemoveButton->setText(QApplication::translate("IssueTracker", "Remove", nullptr));
        label_2->setText(QApplication::translate("IssueTracker", "Remove Issue", nullptr));
        resolveButton->setText(QApplication::translate("IssueTracker", "Resolve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IssueTracker: public Ui_IssueTracker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISSUETRACKER_H
