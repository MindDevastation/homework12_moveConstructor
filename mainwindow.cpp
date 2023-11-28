#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "reaction.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->react->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check (int index){
    switch (index) {
    case 0:
        ui->atomL->setText(this->ions[index].getCharge() + this->ions[index].getAtom() + " (" + QString::number(this->ions[index].getValency()) + ")");
        break;
    case 1:
        ui->atomL_2->setText(this->ions[index].getCharge() + this->ions[index].getAtom() + " (" + QString::number(this->ions[index].getValency()) + ")");
        break;
    case 2:
        ui->atomL_3->setText(this->ions[index].getCharge() + this->ions[index].getAtom() + " (" + QString::number(this->ions[index].getValency()) + ")");
        break;
    case 3:
        ui->atomL_4->setText(this->ions[index].getCharge() + this->ions[index].getAtom() + " (" + QString::number(this->ions[index].getValency()) + ")");
        break;
    case 4:
        ui->atomL_5->setText(this->ions[index].getCharge() + this->ions[index].getAtom() + " (" + QString::number(this->ions[index].getValency()) + ")");
        break;
    default:
        break;
    }
}

void MainWindow::checkx (int index){
    switch (index) {
    case 0:
        ui->atomL_11->setText(this->ion_Xreaction[index].getCharge() + this->ion_Xreaction[index].getAtom() + " (" + QString::number(this->ion_Xreaction[index].getValency()) + ")");
        break;
    case 1:
        ui->atomL_12->setText(this->ion_Xreaction[index].getCharge() + this->ion_Xreaction[index].getAtom() + " (" + QString::number(this->ion_Xreaction[index].getValency()) + ")");
        break;
    case 2:
        ui->atomL_13->setText(this->ion_Xreaction[index].getCharge() + this->ion_Xreaction[index].getAtom() + " (" + QString::number(this->ion_Xreaction[index].getValency()) + ")");
        break;
    case 3:
        ui->atomL_14->setText(this->ion_Xreaction[index].getCharge() + this->ion_Xreaction[index].getAtom() + " (" + QString::number(this->ion_Xreaction[index].getValency()) + ")");
        break;
    case 4:
        ui->atomL_15->setText(this->ion_Xreaction[index].getCharge() + this->ion_Xreaction[index].getAtom() + " (" + QString::number(this->ion_Xreaction[index].getValency()) + ")");
        break;
    default:
        break;
    }
}

void MainWindow::on_react_clicked()
{
    int ionInReaction = ui->ionsComboBox->currentIndex();
    int ionInReaction_2 = ui->ionsComboBox_2->currentIndex();

    if(this->ions[ionInReaction].getValency() != this->ions[ionInReaction_2].getValency()){
        ui->reactionResult->setText("Error! Different valency! ");
    }else{

    this->ion_reation[react] = std::move(this->ions[ionInReaction]);
        switch (react) {
        case 0:
            check(ionInReaction);
            ui->atomL_6->setText(this->ion_reation[react].getCharge() + this->ion_reation[react].getAtom() + " (" + QString::number(this->ion_reation[react].getValency()) + ")");
            break;
        case 1:
            check(ionInReaction);
            ui->atomL_7->setText(this->ion_reation[react].getCharge() + this->ion_reation[react].getAtom() + " (" + QString::number(this->ion_reation[react].getValency()) + ")");
            break;
        case 2:
            check(ionInReaction);
            ui->atomL_8->setText(this->ion_reation[react].getCharge() + this->ion_reation[react].getAtom() + " (" + QString::number(this->ion_reation[react].getValency()) + ")");
            break;
        case 3:
            check(ionInReaction);
            ui->atomL_9->setText(this->ion_reation[react].getCharge() + this->ion_reation[react].getAtom() + " (" + QString::number(this->ion_reation[react].getValency()) + ")");
            break;
        default:
            break;
        }
        react++;
    this->ion_reation[react] = std::move(this->ions[ionInReaction_2]);

    ui->ionsComboBox->clear();
    ui->ionsComboBox_2->clear();

        for(int i = 0; i < 5; i++){
            ui->ionsComboBox->addItem(this->ions[i].getCharge() + this->ions[i].getAtom() + " (" + QString::number(this->ions[i].getValency()) + ")");
            ui->ionsComboBox_2->addItem(this->ions[i].getCharge() + this->ions[i].getAtom() + " (" + QString::number(this->ions[i].getValency()) + ")");
    }

    switch (react) {
    case 0:
        check(ionInReaction_2);
        ui->atomL_6->setText(this->ion_reation[react].getCharge() + this->ion_reation[react].getAtom() + " (" + QString::number(this->ion_reation[react].getValency()) + ")");
        break;
    case 1:
        check(ionInReaction_2);
        ui->atomL_7->setText(this->ion_reation[react].getCharge() + this->ion_reation[react].getAtom() + " (" + QString::number(this->ion_reation[react].getValency()) + ")");
        break;
    case 2:
        check(ionInReaction_2);
        ui->atomL_8->setText(this->ion_reation[react].getCharge() + this->ion_reation[react].getAtom() + " (" + QString::number(this->ion_reation[react].getValency()) + ")");
        break;
    case 3:
        check(ionInReaction_2);
        ui->atomL_9->setText(this->ion_reation[react].getCharge() + this->ion_reation[react].getAtom() + " (" + QString::number(this->ion_reation[react].getValency()) + ")");
        break;
    default:
        break;
    }



    switch (rez) {
    case 0:
        if(this->ion_reation[react - 1].getAtom() != this->ion_reation[react].getAtom()){
            ui->rezL->setText(this->ion_reation[react - 1].getAtom() + this->ion_reation[react].getAtom() + QString::number(this->ion_reation[react].getValency()));
        }else{
            ui->rezL->setText("2" + this->ion_reation[react - 1].getAtom() + QString::number(this->ion_reation[react].getValency()));
        }
        break;
    case 1:
        if(this->ion_reation[react - 1].getAtom() != this->ion_reation[react].getAtom()){
            ui->rezL->setText(this->ion_reation[react - 1].getAtom() + this->ion_reation[react].getAtom());
        }else{
            ui->rezL_2->setText("2" + this->ion_reation[react - 1].getAtom());
        }
        break;
    default:
        break;
    }

    react++;
    rez++;

    ui->reactionResult->setText(" ");
    ui->react->setEnabled(false);
    }

}


void MainWindow::on_Add_clicked()
{
    QString charge = ui->sign->text();
    QString atom = ui->atom->text();
    int valency = ui->valency->text().toInt();

    this->ions[i] = {charge, atom, valency};

    ui->ionsComboBox->addItem(this->ions[i].getCharge() + this->ions[i].getAtom() + " (" + QString::number(this->ions[i].getValency()) + ")");
    ui->ionsComboBox_2->addItem(this->ions[i].getCharge() + this->ions[i].getAtom() + " (" + QString::number(this->ions[i].getValency()) + ")");

    check(i);

    i++;

    ui->ionsLeft->setText("Ions left: " + QString::number(5 - i));
    if(i == 5){
        ui->Add->setEnabled(false);
    }


}


void MainWindow::on_ionsComboBox_activated(int index)
{
    if(index == ui->ionsComboBox_2->currentIndex() || this->ions[index].getCharge() == this->ions[ui->ionsComboBox_2->currentIndex()].getCharge() || this->ions[index].getValency() != this->ions[ui->ionsComboBox_2->currentIndex()].getValency()){
        ui->react->setEnabled(false);
        ui->reactionResult->setText("Error! Unable to make reaction! ");
    }else{
        ui->react->setEnabled(true);
    }
}


void MainWindow::on_ionsComboBox_2_activated(int index)
{
    if(index == ui->ionsComboBox->currentIndex() || this->ions[index].getCharge() == this->ions[ui->ionsComboBox->currentIndex()].getCharge() || this->ions[index].getValency() != this->ions[ui->ionsComboBox->currentIndex()].getValency()){
        ui->react->setEnabled(false);
        ui->reactionResult->setText("Error! Unable to make reaction! ");
    }else{
        ui->react->setEnabled(true);
        ui->reactionResult->setText("Great! You are available to make a reaction! ");
    }
}


void MainWindow::on_finishReaction_clicked()
{
    for(int i = 0; i < 5 ; i++){
        ion_Xreaction[i] = std::move(ions[i]);
        checkx(i);
    }
}


void MainWindow::on_sign_textEdited(const QString &arg1)
{
    if(arg1 != "+" || arg1 != "+"){
        ui->ionsLeft->setText("Error! Unknown charge sign! Ions left: " + QString::number(5 - i));
        ui->Add->setEnabled(false);
    }else{
        ui->ionsLeft->setText("Ions left: " + QString::number(5 - i));
        ui->Add->setEnabled(true);
    }
}


void MainWindow::on_valency_textEdited(const QString &arg1)
{
    if(arg1 <= "1" && arg1 >= "7"){
        ui->ionsLeft->setText("Error! Unknown valency! Ions left: " + QString::number(5 - i));
        ui->Add->setEnabled(false);
    }else{
        ui->ionsLeft->setText("Ions left: " + QString::number(5 - i));
        ui->Add->setEnabled(true);
    }
}


void MainWindow::on_atom_textEdited(const QString &arg1)
{
    if(arg1 == "H" || arg1 == "He" || arg1 == "Li" || arg1 == "Be" || arg1 == "B" || arg1 == "C" || arg1 == "N" || arg1 == "O" || arg1 == "F" || arg1 == "Ne"
        || arg1 == "Na" || arg1 == "Mg" || arg1 == "Al" || arg1 == "Si" || arg1 == "P" || arg1 == "S" || arg1 == "Cl" || arg1 == "Ar" || arg1 == "K" || arg1 == "Ca"
        || arg1 == "Sc" || arg1 == "Ti" || arg1 == "V" || arg1 == "Cr" || arg1 == "Mn" || arg1 == "Fe" || arg1 == "Co" || arg1 == "Ni" || arg1 == "Cu" || arg1 == "Zn"
        || arg1 == "Ga" || arg1 == "Ge" || arg1 == "As" || arg1 == "Se" || arg1 == "Br" || arg1 == "Kr" || arg1 == "Rb" || arg1 == "Sr" || arg1 == "Y" || arg1 == "Zr"
        || arg1 == "Nb" || arg1 == "Mo" || arg1 == "Tc" || arg1 == "Ru" || arg1 == "Rh" || arg1 == "Pd" || arg1 == "Ag" || arg1 == "Cd" || arg1 == "In" || arg1 == "Sn"
        || arg1 == "Sb" || arg1 == "Te" || arg1 == "I" || arg1 == "Xe" || arg1 == "Cs" || arg1 == "Ba" || arg1 == "La" || arg1 == "Ce" || arg1 == "Pr" || arg1 == "Nd"
        || arg1 == "Pm" || arg1 == "Sm" || arg1 == "Eu" || arg1 == "Gd" || arg1 == "Tb" || arg1 == "Dy" || arg1 == "Ho" || arg1 == "Er" || arg1 == "Tm" || arg1 == "Yb"
        || arg1 == "Lu" || arg1 == "Hf" || arg1 == "Ta" || arg1 == "W" || arg1 == "Re" || arg1 == "Os" || arg1 == "Ir" || arg1 == "Pt" || arg1 == "Au" || arg1 == "Hg"
        || arg1 == "Tl" || arg1 == "Pb" || arg1 == "Bi" || arg1 == "Po" || arg1 == "At" || arg1 == "Rn" || arg1 == "Fr" || arg1 == "Ra" || arg1 == "Ac" || arg1 == "TH"
        || arg1 == "Pa" || arg1 == "U" || arg1 == "Np" || arg1 == "Pu" || arg1 == "Am" || arg1 == "Cm" || arg1 == "Bk" || arg1 == "Cf" || arg1 == "Es" || arg1 == "Fm"
        || arg1 == "Md" || arg1 == "No" || arg1 == "Lr" || arg1 == "Rf" || arg1 == "Db" || arg1 == "Sg" || arg1 == "Bh" || arg1 == "Hs" || arg1 == "Mt" || arg1 == "Ds"
        || arg1 == "Rg" || arg1 == "Cn" || arg1 == "Nh" || arg1 == "Fl" || arg1 == "Mc" || arg1 == "Lv" || arg1 == "Ts" || arg1 == "Og"){
        ui->ionsLeft->setText("Ions left: " + QString::number(5 - i));
        ui->Add->setEnabled(true);
    }else{
        ui->ionsLeft->setText("Error! Unknown atom! Ions left: " + QString::number(5 - i));
        ui->Add->setEnabled(false);

    }
}

