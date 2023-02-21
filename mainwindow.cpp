#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QInputDialog>
#include <QDir>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    RsaKeys=new int[4];

    setTabWidgetStyle();
    setInterfaceStyle();
 //   ui->te_Caesar_in->setVerticalScrollBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Left)
    {
        if(ui->tabWidget->currentIndex()==0)
            ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
        else
            ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-1);
    }
    else if(e->key()==Qt::Key_Right)
    {
        if(ui->tabWidget->currentIndex()==ui->tabWidget->count()-1)
            ui->tabWidget->setCurrentIndex(0);
        else
            ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    }
}


void MainWindow::setTabWidgetStyle()
{
    ui->tabWidget->setTabText(2,"Vigener");
    ui->tabWidget->setTabText(3,"Permutation");
    ui->tabWidget->setTabText(4,"RSA");

    ui->centralwidget->setStyleSheet(stylehelper::getCentralWidgetStyle());
    //styles
    ui->tabWidget->tabBar()->setStyleSheet(stylehelper::getTabBarStyle());
    ui->tabWidget->setStyleSheet(stylehelper::getTabWidgetStyle());
    ui->Caesar->setStyleSheet(stylehelper::getTabsStyle());
    ui->Trithemius->setStyleSheet(stylehelper::getTabsStyle());
    ui->Vigener->setStyleSheet(stylehelper::getTabsStyle());
    ui->tablePermutation->setStyleSheet(stylehelper::getTabsStyle());
    ui->RSA->setStyleSheet(stylehelper::getTabsStyle());
}

void MainWindow::setInterfaceStyle()
{
    //labelsStyle
    ui->la_Caesar_bias->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Caesar_img->setStyleSheet(stylehelper::getCeaserLableStyle());
    ui->la_Caesar_lanq->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Caesar_res->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Caesar_text->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Permutation_img->setStyleSheet(stylehelper::getPermutationLableStyle());
    ui->la_Permutation_code->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Permutation_res->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Permutation_text->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Rsa_img->setStyleSheet(stylehelper::getRsaLableStyle());
    ui->la_Rsa_addCLoseKey->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Rsa_addOpenKey->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Rsa_genKey->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Rsa_lanq->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Rsa_res->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Rsa_text->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Trithemius_img->setStyleSheet(stylehelper::getTrithemiusLableStyle());
    ui->la_Trithemius_code->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Trithemius_lanq->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Trithemius_res->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Trithemius_text->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Vigener_img->setStyleSheet(stylehelper::getVigenerLableStyle());
    ui->la_Vigener_code->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Vigener_lanq->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Vigener_res->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_Vigener_text->setStyleSheet(stylehelper::getLablesStyle());

    //checkbox
    ui->cb_Rsa_KeysAutoFill->setStyleSheet(stylehelper::getCheckBoxStyle());
    //spinbox
    ui->spin_Caesar->setStyleSheet(stylehelper::getSpinBoxStyle());
    //textedit

    ui->te_Caesar_in->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Caesar_out->setStyleSheet(stylehelper::getTextEditOutStyle());
    ui->te_Permutation_code->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Permutation_in->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Permutation_out->setStyleSheet(stylehelper::getTextEditOutStyle());
    ui->te_Rsa_addCLoseKey1->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Rsa_addCLoseKey2->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Rsa_addOpenKey1->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Rsa_addOpenKey2->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Rsa_genKey->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Rsa_in->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Rsa_out->setStyleSheet(stylehelper::getTextEditOutStyle());
    ui->te_Trithemius_code->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Trithemius_in->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Trithemius_out->setStyleSheet(stylehelper::getTextEditOutStyle());
    ui->te_Vigener_code->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Vigener_in->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_Vigener_out->setStyleSheet(stylehelper::getTextEditOutStyle());

    //buttons
    ui->pb_Caesar_RasShifr->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Caesar_shifr->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Permutation_RasShifr->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Permutation_shifr->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Rsa_genKey->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Rsa_RasShifr->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Rsa_saveKeys->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Rsa_saveResult->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Rsa_shifr->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Trithemius_RasShifr->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Trithemius_shifr->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Vigener_RasShifr->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_Vigener_shifr->setStyleSheet(stylehelper::getButtonsStyle());

    //combobox
    ui->cb_Caesar_lanq->setStyleSheet(stylehelper::getComboBoxStyle());
    ui->cb_Rsa_lanq->setStyleSheet(stylehelper::getComboBoxStyle());
    ui->cb_Trithemius_lanq->setStyleSheet(stylehelper::getComboBoxStyle());
    ui->cb_Vigener_lanq->setStyleSheet(stylehelper::getComboBoxStyle());

}



void MainWindow::messError(QString mess)
{

    QMessageBox msgBox;
    msgBox.setWindowTitle("Ошибка");
    msgBox.setText(mess);
    msgBox.exec();
}

void MainWindow::on_pb_Caesar_shifr_clicked()
{
       ui->te_Caesar_out->setPlainText(_shifrCaeser.makeShifrString(ui->te_Caesar_in->toPlainText().toLower(),ui->spin_Caesar->value()));
}

void MainWindow::on_pb_Caesar_RasShifr_clicked()
{
    ui->te_Caesar_out->setPlainText(_shifrCaeser.makeRasShifrString(ui->te_Caesar_in->toPlainText().toLower(),ui->spin_Caesar->value()));
}

void MainWindow::on_cb_Caesar_lanq_currentIndexChanged(int index)
{
    _shifrCaeser.setlanquage(index);
    switch (index) {
    case 0:ui->spin_Caesar->setMaximum(32);
        break;
    case 1:ui->spin_Caesar->setMaximum(25);
        break;
    case 2:ui->spin_Caesar->setMaximum(31);
    default:
        break;
    }
}

void MainWindow::on_pb_Trithemius_shifr_clicked()
{
        QString str;
        QString strcode;

        str=ui->te_Trithemius_in->toPlainText().toLower();
        strcode=ui->te_Trithemius_code->toPlainText().toLower();

        ui->te_Trithemius_out->setPlainText(_shifrTrithemius.makeShifrString(str,strcode));

}

void MainWindow::on_pb_Trithemius_RasShifr_clicked()
{
    ui->te_Trithemius_out->setPlainText(_shifrTrithemius.makeRasShifrString(ui->te_Trithemius_in->toPlainText().toLower(),ui->te_Trithemius_code->toPlainText().toLower()));
}

void MainWindow::on_cb_Trithemius_lanq_currentIndexChanged(int index)
{
    _shifrTrithemius.setlanquage(index);
    switch (index) {
    case 0:ui->spin_Caesar->setMaximum(31);
        break;
    case 1:ui->spin_Caesar->setMaximum(25);
    default:
        break;
    }
}

void MainWindow::on_pb_Vigener_shifr_clicked()
{
    ui->te_Vigener_out->setPlainText(_shifrVigener.makeShifr(ui->te_Vigener_in->toPlainText().toLower(),ui->te_Vigener_code->toPlainText().toLower()));
}

void MainWindow::on_pb_Vigener_RasShifr_clicked()
{
    ui->te_Vigener_out->setPlainText(_shifrVigener.makeRasShifr(ui->te_Vigener_in->toPlainText().toLower(),ui->te_Vigener_code->toPlainText().toLower()));
}



void MainWindow::on_cb_Vigener_lanq_currentIndexChanged(int index)
{
    _shifrVigener.setlanquage(index);
    switch (index) {
    case 0:ui->spin_Caesar->setMaximum(31);
        break;
    case 1:ui->spin_Caesar->setMaximum(25);
    default:
        break;
    }
}

void MainWindow::on_pb_Permutation_shifr_clicked()
{
    QString strIN=_strHelper.removeCharFromAllStr(ui->te_Permutation_in->toPlainText().toLower(), ' ');
   ui->te_Permutation_out->setPlainText(_tablePerm.makeShifr(strIN,ui->te_Permutation_code->toPlainText().toLower()));
}

void MainWindow::on_pb_Permutation_RasShifr_clicked()
{
    ui->te_Permutation_out->setPlainText(_tablePerm.makeRasShifr(ui->te_Permutation_in->toPlainText().toLower(),ui->te_Permutation_code->toPlainText().toLower()));
}



void MainWindow::on_pb_Rsa_genKey_clicked()
{
    RsaKeys=_Rsa.genKey();
    QString str="Open KEY: "+QString::number( RsaKeys[0] ) +","+ QString::number( RsaKeys[1] )+"\n"+
          "Close KEY:"+QString::number(RsaKeys[2])+","+ QString::number(RsaKeys[3]);
    ui->te_Rsa_genKey->setPlainText(str);

    if(ui->cb_Rsa_KeysAutoFill->isChecked())
    {
        ui->te_Rsa_addOpenKey1->setPlainText(QString::number(RsaKeys[0]));
        ui->te_Rsa_addOpenKey2->setPlainText(QString::number(RsaKeys[1]));
        ui->te_Rsa_addCLoseKey1->setPlainText(QString::number(RsaKeys[2]));
        ui->te_Rsa_addCLoseKey2->setPlainText(QString::number(RsaKeys[3]));
    }

}

void MainWindow::on_pb_Rsa_shifr_clicked()
{

    ui->te_Rsa_out->setPlainText( _Rsa.makeShifr(ui->te_Rsa_in->toPlainText().toLower(),ui->te_Rsa_addOpenKey1->toPlainText().toInt(),ui->te_Rsa_addOpenKey2->toPlainText().toInt()));
}

void MainWindow::on_pb_Rsa_RasShifr_clicked()
{
    ui->te_Rsa_out->setPlainText(_Rsa.makeRasShifr(ui->te_Rsa_in->toPlainText().toLower(),ui->te_Rsa_addCLoseKey1->toPlainText().toInt(),ui->te_Rsa_addCLoseKey2->toPlainText().toInt()));
}

void MainWindow::on_cb_Rsa_lanq_currentIndexChanged(int index)
{
    _Rsa.setlanquage(index);
}

void MainWindow::on_pb_Rsa_saveKeys_clicked()
{
    bool bOk;
    QString strName = QInputDialog::getText( this, "Save Keys","Имя файла",
                                         QLineEdit::Normal, ".txt", &bOk);

    if (bOk && !strName.isEmpty())
    {// Была нажата кнопка OK
        QString strToSave="Open KEY: "+QString::number( RsaKeys[0] ) +","+ QString::number( RsaKeys[1] )+"\n"+
              "Close KEY:"+QString::number(RsaKeys[2])+","+ QString::number(RsaKeys[3]);

        QFile fileOut(strName);
         if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)) {
              QTextStream writeStream(&fileOut);
              writeStream<<strToSave;
              fileOut.close();
         }
    }
}

void MainWindow::on_pb_Rsa_saveResult_clicked()
{
    bool bOk;
    QString strName = QInputDialog::getText( this, "Save Mess","Имя файла",
                                         QLineEdit::Normal, ".txt", &bOk);

    if (bOk && !strName.isEmpty())
    {// Была нажата кнопка OK
        QString strToSave=ui->te_Rsa_out->toPlainText();

        QFile fileOut(strName);
         if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)) {
              QTextStream writeStream(&fileOut);
              writeStream<<strToSave;
              fileOut.close();
         }
    }
}

