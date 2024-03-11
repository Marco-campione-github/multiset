#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//funzione che mostra i dati dell' utente che si è appena
//registrato o ha effettuato un login sulla dialog
void Dialog::setValues(const QString &name, const QString &surname, const QString mail,
               int day, int month, int year, bool gender_male,const QString &access){
    ui->access_label->setText(access);
    ui->welcome_label->setText("BENVENUTO \n" + name + "\n" + surname);
    ui->mail_label->setText("e-mail/telefono: " + mail);
    ui->date_label->setText("data di nascita: " +
                            QString::number(day) + "/" +
                            QString::number(month) + "/" +
                            QString::number(year));
    if(gender_male)
        ui->gender_label->setText("sesso: uomo");
    else
        ui->gender_label->setText("sesso: donna");
    this->setWindowTitle("LOGIN");
}

//funzione che mostra la dialog del recupero della password
void Dialog::recoveryDialog(const QString &mail){
    ui->welcome_label->setText("");
    ui->mail_label->setText("");
    ui->date_label->setText("");
    ui->access_label->setText("");
    ui->gender_label->setText("");
    ui->pushButton->setText("BACK");
    ui->extra_label->setEnabled(true);
    ui->extra_label->setText("E-mail con procedura di ripristino inviata a:\n" + mail);
}

//funzione che mostra una dialog di errore
void Dialog::errorDialog(const QString &err){
    ui->welcome_label->setText("");
    ui->mail_label->setText("");
    ui->date_label->setText("");
    ui->access_label->setText("");
    ui->gender_label->setText("");
    ui->pushButton->setText("BACK");
    ui->extra_label->setEnabled(true);
    ui->extra_label->setStyleSheet("QLabel { color : red; }");
    ui->extra_label->setText(err);
}

//slot del bottone di logout
void Dialog::on_pushButton_clicked()
{
    close();
}
