#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reaction.h"
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
    reaction ions[5];
    reaction ion_reation[5];
    reaction ion_Xreaction[5];
    int i = 0;
    int react = 0, xreact = 0;
    int rez = 0;


private slots:
    void on_react_clicked();

    void on_Add_clicked();

    void on_ionsComboBox_activated(int index);

    void on_ionsComboBox_2_activated(int index);

    void check(int index);

    void checkx(int index);

    void on_finishReaction_clicked();

    void on_sign_textEdited(const QString &arg1);

    void on_valency_textEdited(const QString &arg1);

    void on_atom_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
