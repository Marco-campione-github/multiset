/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget_login;
    QLabel *welcome_label;
    QLabel *extra_label;
    QPushButton *pushButton;
    QLabel *mail_label;
    QLabel *date_label;
    QLabel *access_label;
    QLabel *gender_label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(632, 364);
        Dialog->setFixedSize(632, 364);
        widget_login = new QWidget(Dialog);
        widget_login->setObjectName(QString::fromUtf8("widget_login"));
        widget_login->setGeometry(QRect(10, 10, 611, 341));
        welcome_label = new QLabel(widget_login);
        welcome_label->setObjectName(QString::fromUtf8("welcome_label"));
        welcome_label->setGeometry(QRect(10, 60, 591, 101));
        QFont font;
        font.setPointSize(18);
        welcome_label->setFont(font);
        welcome_label->setTextFormat(Qt::AutoText);
        welcome_label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        welcome_label->setWordWrap(false);
        extra_label = new QLabel(widget_login);
        extra_label->setObjectName(QString::fromUtf8("extra_label"));
        extra_label->setEnabled(false);
        extra_label->setGeometry(QRect(6, 52, 591, 221));
        QFont font1;
        font1.setPointSize(16);
        extra_label->setFont(font1);
        extra_label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(widget_login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 290, 91, 31));
        mail_label = new QLabel(widget_login);
        mail_label->setObjectName(QString::fromUtf8("mail_label"));
        mail_label->setGeometry(QRect(10, 180, 251, 21));
        date_label = new QLabel(widget_login);
        date_label->setObjectName(QString::fromUtf8("date_label"));
        date_label->setGeometry(QRect(10, 210, 221, 21));
        access_label = new QLabel(widget_login);
        access_label->setObjectName(QString::fromUtf8("access_label"));
        access_label->setGeometry(QRect(30, 10, 541, 31));
        QFont font2;
        font2.setPointSize(14);
        access_label->setFont(font2);
        access_label->setAlignment(Qt::AlignCenter);
        gender_label = new QLabel(widget_login);
        gender_label->setObjectName(QString::fromUtf8("gender_label"));
        gender_label->setGeometry(QRect(10, 240, 221, 21));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        welcome_label->setText(QCoreApplication::translate("Dialog", "BENVENUTO", nullptr));
        extra_label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Dialog", "LOGOUT", nullptr));
        mail_label->setText(QCoreApplication::translate("Dialog", "e-mail:", nullptr));
        date_label->setText(QCoreApplication::translate("Dialog", "data di nascita:", nullptr));
        access_label->setText(QCoreApplication::translate("Dialog", "-", nullptr));
        gender_label->setText(QCoreApplication::translate("Dialog", "sesso:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
