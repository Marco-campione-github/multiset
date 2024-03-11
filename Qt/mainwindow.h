#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_button_clicked();
    void on_recovery_button_clicked();
    void on_register_button_clicked();

private:
    Ui::MainWindow *ui;

    void clearUI();
    QString readFile();
    void WriteFile(const QString &str);
    void openDialog(const QString &name, const QString &surname, const QString mail,
                    int day, int month, int year, bool gender_male, const QString &access);
    void openRecoveryDialog(const QString &mail);
    void openErrorDialog(const QString &err);
    void registerOnFile();
    void login();
    void loginAdmin();
    void password_recovery();
    bool checkValidRegistration();
    bool checkDate();
    bool checkName();
    bool checkSurname();
    bool checkPW();
    bool checkMail();
    bool checkPhone();
    bool checkGender();
    bool mailContained(const QString &mail);
};
#endif // MAINWINDOW_H
