/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *main_layout;
    QWidget *verticalWidget_2;
    QVBoxLayout *login_lay;
    QHBoxLayout *login_sublay;
    QSpacerItem *login_spacer3_5;
    QVBoxLayout *email_lay;
    QLabel *email_label_9;
    QLineEdit *email_lineEdit_Login;
    QSpacerItem *login_spacer1_5;
    QVBoxLayout *email_layout_10;
    QLabel *email_label_10;
    QLineEdit *password_lineEdit_Login;
    QSpacerItem *login_spacer2_5;
    QVBoxLayout *verticalLayout_2;
    QPushButton *login_button;
    QSpacerItem *login_spacer4_5;
    QPushButton *recovery_button;
    QVBoxLayout *register_lay;
    QHBoxLayout *horizontalLayout;
    QLineEdit *name_lineEdit;
    QLineEdit *surname_lineEdit;
    QLineEdit *mail_lineEdit;
    QLineEdit *password_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *day_spin;
    QSpinBox *month_spin;
    QSpinBox *year_spin;
    QSpacerItem *horizontalSpacer;
    QRadioButton *woman_radio;
    QRadioButton *man_radio;
    QPushButton *register_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setFixedSize(600, 280);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 622, 254));
        main_layout = new QVBoxLayout(layoutWidget);
        main_layout->setObjectName(QString::fromUtf8("main_layout"));
        main_layout->setSizeConstraint(QLayout::SetFixedSize);
        main_layout->setContentsMargins(0, 0, 0, 0);
        verticalWidget_2 = new QWidget(layoutWidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(85, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(170, 127, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(127, 63, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 0, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(57, 0, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush8(QColor(0, 0, 0, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        verticalWidget_2->setPalette(palette);
        verticalWidget_2->setAutoFillBackground(true);
        login_lay = new QVBoxLayout(verticalWidget_2);
        login_lay->setSpacing(0);
        login_lay->setObjectName(QString::fromUtf8("login_lay"));
        login_lay->setSizeConstraint(QLayout::SetMinimumSize);
        login_sublay = new QHBoxLayout();
        login_sublay->setObjectName(QString::fromUtf8("login_sublay"));
        login_sublay->setSizeConstraint(QLayout::SetFixedSize);
        login_spacer3_5 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        login_sublay->addItem(login_spacer3_5);

        email_lay = new QVBoxLayout();
        email_lay->setSpacing(0);
        email_lay->setObjectName(QString::fromUtf8("email_lay"));
        email_lay->setSizeConstraint(QLayout::SetDefaultConstraint);
        email_lay->setContentsMargins(-1, 10, -1, 10);
        email_label_9 = new QLabel(verticalWidget_2);
        email_label_9->setObjectName(QString::fromUtf8("email_label_9"));
        email_label_9->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(email_label_9->sizePolicy().hasHeightForWidth());
        email_label_9->setSizePolicy(sizePolicy1);
        email_label_9->setMinimumSize(QSize(220, 20));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush9(QColor(255, 255, 255, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QBrush brush10(QColor(255, 255, 255, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QBrush brush11(QColor(255, 255, 255, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        email_label_9->setPalette(palette1);
        email_label_9->setLayoutDirection(Qt::LeftToRight);
        email_label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        email_label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        email_lay->addWidget(email_label_9);

        email_lineEdit_Login = new QLineEdit(verticalWidget_2);
        email_lineEdit_Login->setObjectName(QString::fromUtf8("email_lineEdit_Login"));
        sizePolicy1.setHeightForWidth(email_lineEdit_Login->sizePolicy().hasHeightForWidth());
        email_lineEdit_Login->setSizePolicy(sizePolicy1);
        email_lineEdit_Login->setMinimumSize(QSize(220, 30));

        email_lay->addWidget(email_lineEdit_Login);


        login_sublay->addLayout(email_lay);

        login_spacer1_5 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        login_sublay->addItem(login_spacer1_5);

        email_layout_10 = new QVBoxLayout();
        email_layout_10->setSpacing(0);
        email_layout_10->setObjectName(QString::fromUtf8("email_layout_10"));
        email_layout_10->setSizeConstraint(QLayout::SetDefaultConstraint);
        email_layout_10->setContentsMargins(-1, 10, -1, 10);
        email_label_10 = new QLabel(verticalWidget_2);
        email_label_10->setObjectName(QString::fromUtf8("email_label_10"));
        email_label_10->setEnabled(true);
        sizePolicy1.setHeightForWidth(email_label_10->sizePolicy().hasHeightForWidth());
        email_label_10->setSizePolicy(sizePolicy1);
        email_label_10->setMinimumSize(QSize(220, 20));
        email_label_10->setLayoutDirection(Qt::LeftToRight);
        email_label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        email_label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        email_layout_10->addWidget(email_label_10);

        password_lineEdit_Login = new QLineEdit(verticalWidget_2);
        password_lineEdit_Login->setObjectName(QString::fromUtf8("password_lineEdit_Login"));
        sizePolicy1.setHeightForWidth(password_lineEdit_Login->sizePolicy().hasHeightForWidth());
        password_lineEdit_Login->setSizePolicy(sizePolicy1);
        password_lineEdit_Login->setMinimumSize(QSize(220, 30));
        password_lineEdit_Login->setStyleSheet(QString::fromUtf8(""));
        password_lineEdit_Login->setEchoMode(QLineEdit::Password);

        email_layout_10->addWidget(password_lineEdit_Login);


        login_sublay->addLayout(email_layout_10);

        login_spacer2_5 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        login_sublay->addItem(login_spacer2_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 30, -1, 10);
        login_button = new QPushButton(verticalWidget_2);
        login_button->setObjectName(QString::fromUtf8("login_button"));
        login_button->setAutoFillBackground(true);

        verticalLayout_2->addWidget(login_button);


        login_sublay->addLayout(verticalLayout_2);

        login_spacer4_5 = new QSpacerItem(13, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        login_sublay->addItem(login_spacer4_5);


        login_lay->addLayout(login_sublay);

        recovery_button = new QPushButton(verticalWidget_2);
        recovery_button->setObjectName(QString::fromUtf8("recovery_button"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(recovery_button->sizePolicy().hasHeightForWidth());
        recovery_button->setSizePolicy(sizePolicy2);
        recovery_button->setStyleSheet(QString::fromUtf8(""));

        login_lay->addWidget(recovery_button, 0, Qt::AlignLeft);

        login_lay->setStretch(0, 20);

        main_layout->addWidget(verticalWidget_2);

        register_lay = new QVBoxLayout();
        register_lay->setObjectName(QString::fromUtf8("register_lay"));
        register_lay->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        name_lineEdit = new QLineEdit(layoutWidget);
        name_lineEdit->setObjectName(QString::fromUtf8("name_lineEdit"));
        name_lineEdit->setReadOnly(false);

        horizontalLayout->addWidget(name_lineEdit);

        surname_lineEdit = new QLineEdit(layoutWidget);
        surname_lineEdit->setObjectName(QString::fromUtf8("surname_lineEdit"));

        horizontalLayout->addWidget(surname_lineEdit);


        register_lay->addLayout(horizontalLayout);

        mail_lineEdit = new QLineEdit(layoutWidget);
        mail_lineEdit->setObjectName(QString::fromUtf8("mail_lineEdit"));

        register_lay->addWidget(mail_lineEdit);

        password_lineEdit = new QLineEdit(layoutWidget);
        password_lineEdit->setObjectName(QString::fromUtf8("password_lineEdit"));
        password_lineEdit->setStyleSheet(QString::fromUtf8(""));
        password_lineEdit->setEchoMode(QLineEdit::Password);

        register_lay->addWidget(password_lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        day_spin = new QSpinBox(layoutWidget);
        day_spin->setObjectName(QString::fromUtf8("day_spin"));
        day_spin->setMinimum(1);
        day_spin->setMaximum(31);

        horizontalLayout_2->addWidget(day_spin);

        month_spin = new QSpinBox(layoutWidget);
        month_spin->setObjectName(QString::fromUtf8("month_spin"));
        month_spin->setMinimum(1);
        month_spin->setMaximum(12);

        horizontalLayout_2->addWidget(month_spin);

        year_spin = new QSpinBox(layoutWidget);
        year_spin->setObjectName(QString::fromUtf8("year_spin"));
        year_spin->setMinimum(1900);
        year_spin->setMaximum(2021);

        horizontalLayout_2->addWidget(year_spin);

        horizontalSpacer = new QSpacerItem(180, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        woman_radio = new QRadioButton(layoutWidget);
        woman_radio->setObjectName(QString::fromUtf8("woman_radio"));

        horizontalLayout_2->addWidget(woman_radio);

        man_radio = new QRadioButton(layoutWidget);
        man_radio->setObjectName(QString::fromUtf8("man_radio"));

        horizontalLayout_2->addWidget(man_radio);


        register_lay->addLayout(horizontalLayout_2);

        register_button = new QPushButton(layoutWidget);
        register_button->setObjectName(QString::fromUtf8("register_button"));
        register_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(78, 170, 39);"));

        register_lay->addWidget(register_button);

        register_lay->setStretch(0, 1);
        register_lay->setStretch(1, 1);
        register_lay->setStretch(2, 1);
        register_lay->setStretch(3, 1);
        register_lay->setStretch(4, 1);

        main_layout->addLayout(register_lay);

        main_layout->setStretch(1, 5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 653, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        email_label_9->setText(QCoreApplication::translate("MainWindow", "E-mail o telefono", nullptr));
        email_label_10->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        login_button->setText(QCoreApplication::translate("MainWindow", "Accedi", nullptr));
        recovery_button->setText(QCoreApplication::translate("MainWindow", "Non ricordi pi\303\271 come accedere all' account?", nullptr));
        name_lineEdit->setText(QString());
        name_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nome", nullptr));
        surname_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Cognome", nullptr));
        mail_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Numero di cellulare o e-mail", nullptr));
        password_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nuova Password", nullptr));
        woman_radio->setText(QCoreApplication::translate("MainWindow", "Donna", nullptr));
        man_radio->setText(QCoreApplication::translate("MainWindow", "Uomo", nullptr));
        register_button->setText(QCoreApplication::translate("MainWindow", "Iscriviti", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
