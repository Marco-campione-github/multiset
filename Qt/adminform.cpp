#include "adminform.h"
#include "ui_adminform.h"
#include <iostream>

adminform::adminform(QWidget *parent) :
    QDialog(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
    text = readFile();
    usersTable();
}

adminform::~adminform(){
    delete ui;
}

//funzione che legge il file "users.csv"
QString adminform::readFile(){
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

//funzione che cambia la schermata e i pulsanti della pagina dell' admin
void adminform::setMode(int mode){
    if(mode == 0){
        ui->tableWidget->setVisible(true);
        ui->graphicsView->setVisible(false);
        ui->button1->setDisabled(true);
        ui->button2->setEnabled(true);
        ui->button3->setEnabled(true);
    }
    if(mode == 1){
        ui->graphicsView->setVisible(true);
        ui->tableWidget->setVisible(false);
        ui->button2->setDisabled(true);
        ui->button1->setEnabled(true);
        ui->button3->setEnabled(true);
    }
    if(mode == 2){
        ui->graphicsView->setVisible(true);
        ui->tableWidget->setVisible(false);
        ui->button1->setEnabled(true);
        ui->button3->setDisabled(true);
        ui->button2->setEnabled(true);
    }
}

//funzione che mostra la lista di utenti in una tabella
void adminform::usersTable(){
    setMode(0);
    QString mail = "", name = "", surname = "",
            day = "", month = "", year = "", gender = "";
    int commaCount = 0, i = 0;
    ui->tableWidget->clearContents();
    ui->tableWidget->model()->removeRows(0, ui->tableWidget->rowCount());
    while(i < text.size()){
        if(text.at(i) != ',' && text.at(i) != '\n' ){
            switch(commaCount) {
            case 0:{
                mail += text.at(i);
            }
            case 1:{
                break;
            }
            case 2:{
                name += text.at(i);
                break;
            }
            case 3:{
                surname += text.at(i);
                break;
            }
            case 4:{
                day += text.at(i);
                break;
            }
            case 5:{
                month += text.at(i);
                break;
            }
            case 6:{
                year += text.at(i);
                break;
            }
            case 7:{
                gender += text.at(i);
                break;
            }
            }
        }
        if(text.at(i) == ',')
            commaCount++;
        if(text.at(i) == '\n'){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                     0, new QTableWidgetItem(mail));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                     1, new QTableWidgetItem(name));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                     2, new QTableWidgetItem(surname));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                     3, new QTableWidgetItem(day + "/" + month + "/" + year));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,
                                     4, new QTableWidgetItem(gender));
            commaCount = 0;
            mail = "";
            name = "";
            surname = "";
            day = "";
            month = "";
            year = "";
            gender = "";
        }
        i++;
    }
}

//funzione che mostra un grafico a torta degli uomini e della donne
void adminform::genderGraph(){
    QString gender = "";
    int male = 0, female  = 0;
    int commaCount = 0, i = 0;
    while(i < text.size()){
        if(commaCount == 7)
            gender += text.at(i);
        if(text.at(i) == ',')
            commaCount++;
        if(text.at(i) == '\n'){
            if(gender.compare("uomo\n") == 0)
                male++;
            if(gender.compare("donna\n") == 0)
                female++;
            gender = "";
            commaCount = 0;
        }
        i++;
    }
    QPieSeries *series = new QPieSeries();
    QPieSlice *slice1 = new QPieSlice("Uomini", static_cast<double>(male));
    QPieSlice *slice2 = new QPieSlice("Donne", static_cast<double>(female));
    slice1->setBrush(Qt::blue);
    slice2->setBrush(QColor("#FF00FF"));
    series->append(slice1);
    series->append(slice2);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Percentuale uomini e donne");
    ui->graphicsView->setChart(chart);
}

//funzione che mostra un grafico a torta dei range di età
void adminform::ageGraph(){
    QDate current_date = QDate::currentDate();
    QString day = "", month = "", year = "";
    QVector<int> ages;
    int commaCount = 0, i = 0, age = 0;
    while(i < text.size()){
        if(commaCount == 4)
            day += text.at(i);
        if(commaCount == 5)
            month += text.at(i);
        if(commaCount == 6)
            year += text.at(i);
        if(text.at(i) == ',')
            commaCount++;
        if(text.at(i) == '\n'){
            day = day.remove(',');
            month = month.remove(',');
            year = year.remove(',');
            QDate user_date(year.toInt(), month.toInt(), day.toInt());
            age = current_date.year() - user_date.year();
            if ((user_date.month() > current_date.month() ||
                (user_date.month() == current_date.month() &&
                user_date.day() > current_date.day()))) {
            age--;
            }
            ages.append(age);
            day = "";
            month = "";
            year = "";
            commaCount = 0;
        }
        i++;
    }
    QPieSeries *series = new QPieSeries();
    QPieSlice *slice1 = new QPieSlice("18-26", countInRange(ages, 18, 26));
    QPieSlice *slice2 = new QPieSlice("27-35", countInRange(ages, 27, 35));
    QPieSlice *slice3 = new QPieSlice("36-44", countInRange(ages, 36, 44));
    QPieSlice *slice4 = new QPieSlice("45-53", countInRange(ages, 45, 53));
    QPieSlice *slice5 = new QPieSlice("54+", countInRange(ages, 54, 500));
    slice1->setBrush(QColor("#000080"));
    slice2->setBrush(QColor("#FFFF00"));
    slice3->setBrush(QColor("#00FF00"));
    slice4->setBrush(QColor("#FFA500"));
    slice5->setBrush(QColor("#7f00ff"));
    series->append(slice1);
    series->append(slice2);
    series->append(slice3);
    series->append(slice4);
    series->append(slice5);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Percentuale eta'");
    ui->graphicsView->setChart(chart);
}

//funzione di supporto per ageGraph() che conta le persone in un range di età
int adminform::countInRange(QVector<int> &ages, int x, int y) {
    int count = 0, elem = 0;
    QVectorIterator<int>ageIter(ages);
    while (ageIter.hasNext()) {
        elem = ageIter.next();
        if (elem >= x && elem <= y)
            count++;
    }
    return count;
}

//slot del pulsante della lista
void adminform::on_button1_clicked() {
    setMode(0);
    usersTable();
}

//slot del pulsante del primo grafico
void adminform::on_button2_clicked() {
    setMode(1);
    genderGraph();
}

//slot del pulsante del secondo grafico
void adminform::on_button3_clicked() {
    setMode(2);
    ageGraph();
}

//slot del pulsante del logout
void adminform::on_button4_clicked() {
    close();
}
