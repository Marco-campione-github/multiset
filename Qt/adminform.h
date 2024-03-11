#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QDialog>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QTableWidget>
#include <QPieSeries>
#include <QtCharts>
#include <QChartView>

QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class adminform : public QDialog
{
    Q_OBJECT

public:
    explicit adminform(QWidget *parent = nullptr);
    virtual ~adminform();

private slots:
    void on_button1_clicked(); //table
    void on_button2_clicked(); //gender graph
    void on_button3_clicked(); //age graph
    void on_button4_clicked(); //logout

private:
    Ui::Form *ui;
    QString text;

    void setMode(int mode);
    void usersTable();
    QString readFile();
    void genderGraph();
    void ageGraph();
    int countInRange(QVector<int> &ages, int x, int y);
};

#endif // ADMINFORM_H
