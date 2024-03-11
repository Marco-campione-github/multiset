/********************************************************************************
** Form generated from reading UI file 'adminform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFORM_H
#define UI_ADMINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout1;
    QTableWidget *tableWidget;
    QChartView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(676, 376);
        verticalLayoutWidget = new QWidget(Form);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 9, 651, 351));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout1 = new QHBoxLayout();
        horizontalLayout1->setObjectName(QString::fromUtf8("horizontalLayout1"));
        tableWidget = new QTableWidget(verticalLayoutWidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setColumnCount(5);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(120);

        horizontalLayout1->addWidget(tableWidget);

        graphicsView = new QChartView(verticalLayoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout1->addWidget(graphicsView);

        horizontalLayout1->setStretch(0, 1);
        horizontalLayout1->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button1 = new QPushButton(verticalLayoutWidget);
        button1->setObjectName(QString::fromUtf8("button1"));

        horizontalLayout->addWidget(button1);

        button2 = new QPushButton(verticalLayoutWidget);
        button2->setObjectName(QString::fromUtf8("button2"));

        horizontalLayout->addWidget(button2);

        button3 = new QPushButton(verticalLayoutWidget);
        button3->setObjectName(QString::fromUtf8("button3"));

        horizontalLayout->addWidget(button3);

        button4 = new QPushButton(verticalLayoutWidget);
        button4->setObjectName(QString::fromUtf8("button4"));

        horizontalLayout->addWidget(button4);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(1, 1);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Form", "mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Form", "nome", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Form", "cognome", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Form", "data", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Form", "sesso", nullptr));
        button1->setText(QCoreApplication::translate("Form", "Lista Utenti", nullptr));
        button2->setText(QCoreApplication::translate("Form", "Percentuale Uomini/Donne", nullptr));
        button3->setText(QCoreApplication::translate("Form", "Percentuale eta'", nullptr));
        button4->setText(QCoreApplication::translate("Form", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFORM_H
