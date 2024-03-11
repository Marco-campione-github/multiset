#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void setValues(const QString &name, const QString &surname, const QString mail,
                   int day, int month, int year, bool gender_male,const QString &access);
    void recoveryDialog(const QString &mail);
    void errorDialog(const QString &err);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
