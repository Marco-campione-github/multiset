#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "adminform.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//funzione che pulisce la UI
void MainWindow::clearUI(){
    //pulisce la sezione di registrazione
    ui->mail_lineEdit->setText("");
    ui->name_lineEdit->setText("");
    ui->surname_lineEdit->setText("");
    ui->password_lineEdit->setText("");
    ui->man_radio->setChecked(false);
    ui->woman_radio->setChecked(false);
    ui->day_spin->setValue(1);
    ui->month_spin->setValue(1);
    ui->year_spin->setValue(1900);

    //pulisce la sezione di login
    ui->email_lineEdit_Login->setText("");
    ui->password_lineEdit_Login->setText("");
}

//funzione che legge dal file "users.csv"
QString MainWindow::readFile(){
    QFile file("users.csv");
    QString str;
    if(!file.open(QIODevice::ReadOnly)){
        std::cerr << "Cannot open file for writing and reading: " <<
                     qPrintable(file.errorString()) <<
                     std::endl;
    }
    QTextStream in(&file);
    str = in.readAll();
    return str;
}

//funzione che scrive sul file "users.csv"
void MainWindow::WriteFile(const QString &str){
    QFile file("users.csv");
    if(!file.open(QIODevice::WriteOnly)){
        std::cerr << "Cannot open file for writing and reading: " <<
                     qPrintable(file.errorString()) <<
                     std::endl;
    }
    QTextStream out(&file);
    out << str;
}

//funzione che apre una dialog dopo una login o una registrazione
void MainWindow::openDialog(const QString &name, const QString &surname, const QString mail,
                            int day, int month, int year, bool gender_male,const QString &access){
    Dialog d;
    d.setValues(name, surname, mail, day, month, year, gender_male, access);
    d.exec();
}

//funzione che apre una dialog per il recupero della password
void MainWindow::openRecoveryDialog(const QString &mail){
    Dialog d;
    d.recoveryDialog(mail);
    d.exec();
}

//funzione che apre una dialog di errore
void MainWindow::openErrorDialog(const QString &err){
    Dialog d;
    d.errorDialog(err);
    d.exec();
}

//funzione che registra un nuovo utente su file
void MainWindow::registerOnFile(){
    QString text = readFile();
    bool gender_male = true;
    if(checkValidRegistration()){
        if(!mailContained(ui->mail_lineEdit->text())){
            text.append(ui->mail_lineEdit->text());
            text.append(",");
            text.append(ui->password_lineEdit->text());
            text.append(",");
            text.append(ui->name_lineEdit->text());
            text.append(",");
            text.append(ui->surname_lineEdit->text());
            text.append(",");
            text.append(QString::number((ui->day_spin->value())));
            text.append(",");
            text.append(QString::number((ui->month_spin->value())));
            text.append(",");
            text.append(QString::number((ui->year_spin->value())));
            text.append(",");
            if(ui->man_radio->isChecked()){
                text.append("uomo");
                gender_male = true;
            }
            if(ui->woman_radio->isChecked()){
                text.append("donna");
                gender_male = false;
            }
            text.append("\n");
            WriteFile(text);
            openDialog(ui->name_lineEdit->text(),
                       ui->surname_lineEdit->text(),
                       ui->mail_lineEdit->text(),
                       ui->day_spin->value(),
                       ui->month_spin->value(),
                       ui->year_spin->value(),
                       gender_male,
                       "REGISTRAZIONE EFFETTUATA:");
            clearUI();

        }
        else
             openErrorDialog("Utente gia'\nregistrato!");
    }
}

//funzione che gestisce il login
void MainWindow::login(){
    QString text = readFile();
    if(mailContained(ui->email_lineEdit_Login->text())){
        QString password, name, surname, day = 0, month = 0, year = 0, gender;
        QString mail = ui->email_lineEdit_Login->text();
        int commaCount = 0;
        int index = text.indexOf(mail);
        while(text.at(index) != '\n'){
            if(text.at(index) != ','){
                switch(commaCount) {
                case 0:{
                    break;
                }
                case 1:{
                    password += text.at(index);
                    break;
                }
                case 2:{
                    name += text.at(index);
                    break;
                }
                case 3:{
                    surname += text.at(index);
                    break;
                }
                case 4:{
                    day += text.at(index);
                    break;
                }
                case 5:{
                    month += text.at(index);
                    break;
                }
                case 6:{
                    year += text.at(index);
                    break;
                }
                case 7:{
                    gender += text.at(index);
                    break;
                }
                }
            }
            if(text.at(index) == ',')
                commaCount++;
            index++;
        }
        if(ui->password_lineEdit_Login->text() == password){
            bool gender_male = true;
            if(gender == "male")
                gender_male = true;
            if(gender == "female")
                gender_male = false;
            openDialog(name, surname, mail, day.toInt(), month.toInt(),
                       year.toInt(), gender_male, "LOGIN EFFETTUATO");
            clearUI();
        }
        else{
            openErrorDialog("Password errata!");
        }
    }
    else{
        if(ui->email_lineEdit_Login->text() == "admin@pas.com"){
            if(ui->password_lineEdit_Login->text() == "admin"){
                loginAdmin();
            }
            else
                openErrorDialog("Password errata!");
        }
        else
            openErrorDialog("Utente non\n registrato!");
    }
}

//funzione che gestisce il login dell' admin
void MainWindow::loginAdmin(){
    adminform a;
    this->hide();
    a.exec();
    this->show();
    clearUI();
}

//funzione che gestisce il recupero della password
void MainWindow::password_recovery(){
    if(mailContained(ui->email_lineEdit_Login->text())){
        openRecoveryDialog(ui->email_lineEdit_Login->text());
    }
    else{
        if(ui->email_lineEdit_Login->text() == "admin@pas.com")
            openRecoveryDialog("admin@pas.com");
        else
            openErrorDialog("Utente non trovato!");
    }
    clearUI();
}

//funzione che assicura che la registrazione sia valida
bool MainWindow::checkValidRegistration(){
    bool flag = true;
    if(!checkName() || !checkSurname() || !checkMail() ||
        !checkPW() || !checkDate() || !checkGender()){
        flag = false;
    }
    return flag;
}

//funzione di controllo sulla data
bool MainWindow::checkDate(){
    QDate current_date = QDate::currentDate();
    int day = ui->day_spin->value();
    int month = ui->month_spin->value();
    int year = ui->year_spin->value();
    QDate user_date(year, month, day);
    if(!user_date.isValid()){
        openErrorDialog("Data non valida!");
        return false;
    }
    if(year > current_date.year() - 18){
        openErrorDialog("Utente non maggiorenne!");
        return false;
    }
    if(year == current_date.year() - 18){
        if(month < current_date.month()){
            openErrorDialog("Utente non maggiorenne!");
            return false;
        }
        if(month == current_date.month())
            if(day < current_date.day()){
                openErrorDialog("Utente non maggiorenne!");
            }
    }
    return true;
}

//funzione di controllo sul nome
bool MainWindow::checkName(){
    QString name = ui->name_lineEdit->text();
    if(name == ""){
        openErrorDialog("Il nome non e' stato inserito");
        return false;
    }
    for(int i = 0; i < name.size(); ++i)
        if(!name[i].isLetter()){
            openErrorDialog("Il nome contiene\ncaratteri non validi");
            return false;
        }
    return true;
}

//funzione di controllo sul cognome
bool MainWindow::checkSurname(){
    QString surname = ui->surname_lineEdit->text();
    if(surname == ""){
        openErrorDialog("Il cognome non e'\nstato inserito");
        return false;
    }
    for(int i = 0; i < surname.size(); ++i)
        if(!surname[i].isLetter()){
            openErrorDialog("Il cognome contiene\ncaratteri non validi");
            return false;
        }
    return true;
}

//funzione di controllo sulla mail/telefono
bool MainWindow::checkMail(){
    bool isMail = false;
    bool isPhone = true;
    QString mail = ui->mail_lineEdit->text();
    if(mail.contains(",") || mail.contains("\\")){
        openErrorDialog("L'email contiene caratteri non validi!");
        return false;
    }
    if(mail == "admin@pas.com"){
        openErrorDialog("E-mail non valida per\nla registrazione!");
        return false;
    }
    else{
        //controlla per la mail tramite espressioni regolari
        QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
        mailREX.setCaseSensitivity(Qt::CaseInsensitive);
        mailREX.setPatternSyntax(QRegExp::RegExp);
        if(mailREX.exactMatch(mail))
            isMail = true;
        //controllo numero di telefono
        //Il Numero deve avere 9 o 10 cifre e iniziare o con 3 (mobile) o con 0 (fisso).
        for(int i = 0; i < mail.size() && isPhone; i++){
            if(!mail.at(i).isDigit())
                isPhone = false;
        }
        if(isPhone){
            if(!(mail.size() == 9 || mail.size() == 10))
                isPhone = false;
            if(!(mail.at(0) == '3' || mail.at(0) == '0'))
                isPhone = false;
        }
    }
    if(isMail || isPhone)
        return true;
    else{
        openErrorDialog("E-mail o numero di telefono non \nvalidi per la registrazione!\n"
                        "NUMERO DI TELEFONO: 9 o 10 cifre\n e deve iniziare o per '3' o per '0'\n"
                        "E-MAIL: 'xxxxxxxxx@xxxxxxxx.xxxx'\n (con 2, 3 o 4 'x' dopo il punto)");
        return false;
    }
    return false;
}

//funzione di controllo sulla password
bool MainWindow::checkPW(){
     QString pw = ui->password_lineEdit->text();
     if(pw.size() < 8){
         openErrorDialog("La password deve essere\ndi minimo 8 caratteri!");
         return false;
     }
     if(pw.contains("\\") || pw.contains(",")){
         openErrorDialog("La password contiene\ncaratteri non validi!");
         return false;
     }

     return true;
}

//funzione di controllo sul sesso
bool MainWindow::checkGender(){
    bool flag = true;
    if(!ui->man_radio->isChecked() && !ui->woman_radio->isChecked()){
        openErrorDialog("Devi specificare \nse sei uomo o donna!");
        flag = false;
    }
    return flag;
}

//funzione che controlla se la mail è presente nel file
bool MainWindow::mailContained(const QString &mail){
    QString text = readFile();
    QString tmp = "";
    int  i = 0;
    bool commaCounted = true;
    while(i < text.size()){
        while(text.at(i) != '\n'){
            if(text.at(i) == ',')
                commaCounted = false;
            if(commaCounted)
                tmp.append(text.at(i));
            i++;
        }
        if(mail == tmp)
            return true;
        i++;
        commaCounted = true;
        tmp = "";
    }
    return false;
}

//slot del login_button
void MainWindow::on_login_button_clicked()
{
    login();
}

//slot del recovery_button
void MainWindow::on_recovery_button_clicked()
{
    password_recovery();
}

//slot del register_button
void MainWindow::on_register_button_clicked()
{
    registerOnFile();
}
