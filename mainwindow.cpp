#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QInputDialog>
#include <QDir>
#include <QRegExp>
//todelete
#include<QTextCodec>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    RsaKeys=new int[4];

    setTabWidgetStyle();
    setInterfaceStyle();

}

MainWindow::~MainWindow()
{
    delete ui;
//    delete RsaKeys;
//    delete probabilityShenon;
//    delete codeCharShenonFano;
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
    ui->tabWidget->setTabText(5,"Shenon-Fano");
    ui->tabWidget->setTabText(6,"Parity Bit");
    ui->tabWidget->setTabText(7,"TIN");

    ui->centralwidget->setStyleSheet(stylehelper::getCentralWidgetStyle());
    //styles
    ui->tabWidget->tabBar()->setStyleSheet(stylehelper::getTabBarStyle());
    ui->tabWidget->setStyleSheet(stylehelper::getTabWidgetStyle());
    ui->Caesar->setStyleSheet(stylehelper::getTabsStyle());
    ui->Trithemius->setStyleSheet(stylehelper::getTabsStyle());
    ui->Vigener->setStyleSheet(stylehelper::getTabsStyle());
    ui->tablePermutation->setStyleSheet(stylehelper::getTabsStyle());
    ui->RSA->setStyleSheet(stylehelper::getTabsStyle());
    ui->ShenonFano->setStyleSheet(stylehelper::getTabsStyle());
    ui->ParityCheck->setStyleSheet(stylehelper::getTabsStyle());
    ui->TIN->setStyleSheet(stylehelper::getTabsStyle());
    ui->wt_TIN->setStyleSheet(stylehelper::getTabsStyle());

    //etc params
    ui->le_TIN_in->setInputMask("0_0_0_0_0_0_0_0_0_0");
    ui->le_TIN_out->setInputMask("0_0_0_0_0_0_0_0_0_0_0_0");
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
    ui->la_ShenonFano_img->setStyleSheet(stylehelper::getShenonFanoLableStyle());
    ui->la_ShenonFano_text->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_ShenonFano_res->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_ParityCheck_text->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_ParityCheck_res->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_TIN_numbers->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_TIN_res->setStyleSheet(stylehelper::getLablesStyle());
    ui->la_TIN_img->setStyleSheet(stylehelper::getTINLableStyle());

    //lineedit
    ui->le_TIN_in->setStyleSheet(stylehelper::getLineEditStyle());
    ui->le_TIN_out->setStyleSheet(stylehelper::getLineEditTINStyle());
    //tablewidget
    ui->tw_ShenonFano->setStyleSheet(stylehelper::getTableWidgetStyle());
    //checkbox
    ui->cb_Rsa_KeysAutoFill->setStyleSheet(stylehelper::getCheckBoxStyle());
    //spinbox
    ui->spin_Caesar->setStyleSheet(stylehelper::getSpinBoxStyle());
    //radioButton
    ui->rb_TIN_entity->setStyleSheet(stylehelper::getRadioButtonStyle());
    ui->rb_TIN_individual->setStyleSheet(stylehelper::getRadioButtonStyle());

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
    ui->te_ShenonFano_in->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_ParityCheck_in->setStyleSheet(stylehelper::getTextEditStyle());
    ui->te_ParityCheck_out->setStyleSheet(stylehelper::getTextEditOutStyle());

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
    ui->pb_ShenonFano_fillTable->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_ShenonFano_saveCode->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_ParityCheck_convert->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_ParityCheck_Reconvert->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_TIN_makeNum->setStyleSheet(stylehelper::getButtonsStyle());
    ui->pb_TIN_makeRandom->setStyleSheet(stylehelper::getButtonsStyle());

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

void MainWindow::setShenonFanoTableWidgetStyle(int rowCount)
{
    //tableParams
    ui->tw_ShenonFano->setColumnCount(3);
    ui->tw_ShenonFano->setRowCount(rowCount);
    ui->tw_ShenonFano->setShowGrid(true); // Включаем сетку
    // Разрешаем выделение только одного элемента
    ui->tw_ShenonFano->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tw_ShenonFano->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    ui->tw_ShenonFano->setHorizontalHeaderLabels(QStringList()<<trUtf8("char")
                                                            <<trUtf8("probability")
                                                            <<trUtf8("code")
                                                                     );
    // Растягиваем последнюю колонку на всё доступное пространство
    ui->tw_ShenonFano->horizontalHeader()->setStretchLastSection(true);
    // Скрываем колонку под номером 0
   // ui->tw_ShenonFano->hideColumn(0);
}

void MainWindow::on_pb_ShenonFano_fillTable_clicked()
{
    QString _uniqstr= _ShenonFano.getStrOfUniqueChars(ui->te_ShenonFano_in->toPlainText());
    setShenonFanoTableWidgetStyle(_uniqstr.size());
    codeCharShenonFano=new QString[_uniqstr.size()];//массив qstring для кодов char
    probabilityShenon=_ShenonFano.getProbabilityOfChars(ui->te_ShenonFano_in->toPlainText(),_uniqstr);//получение вероятностей
    reqursiaShenon(0,_uniqstr.size()-1,true);//определние кодов
    //заполнение таблицы
    for (int i = 0; i < _uniqstr.size(); ++i) {
        ui->tw_ShenonFano->setItem(i,0,new QTableWidgetItem( QString(_uniqstr[i])));
        ui->tw_ShenonFano->setItem(i,1,new QTableWidgetItem(QString::number(probabilityShenon[i],'g',4)));
        ui->tw_ShenonFano->setItem(i,2,new QTableWidgetItem(codeCharShenonFano[i]));
    }
}

void MainWindow::reqursiaShenon(int start, int end,bool topORbot)
{
        if(start<end)
        {
            double schet1=0,schet2=0;
            //подсчет середины
            int middle;
            for(int i=start;i<end;i++)
            {
            schet1+=probabilityShenon[i];
            }
            schet2=probabilityShenon[end];
            middle= end;
            while (schet1>(schet2+probabilityShenon[end]/2) && end-start!=1 )
            {
            middle--;
            schet1-= probabilityShenon[middle];
            schet2+=probabilityShenon[middle];
            }
            //0 && 1 top/bot
            for(int i=start;i<middle;i++)
            {
                setCodeCharShenonFano(i,true);
             }
            for(int i=middle;i<=end;i++)
            {
                setCodeCharShenonFano(i,false);
            }
            //рекурсии верхней ветки и нижней
            reqursiaShenon(start,middle-1,true);
            reqursiaShenon(middle,end,false);
        }
}

void MainWindow::setCodeCharShenonFano(int indexStr,bool oneORzero)
{
    if(oneORzero)
        codeCharShenonFano[indexStr]+="1";
    else
        codeCharShenonFano[indexStr]+="0";
}

void MainWindow::on_pb_ParityCheck_convert_clicked()
{
    ui->te_ParityCheck_out->setPlainText(_parityCheck.getBinaryCode(ui->te_ParityCheck_in->toPlainText()));
}

void MainWindow::on_pb_ParityCheck_Reconvert_clicked()
{
    ui->te_ParityCheck_out->setPlainText(_parityCheck.getStrFromBinaryCode(ui->te_ParityCheck_in->toPlainText()));
}

void MainWindow::on_rb_TIN_individual_clicked()
{
    ui->le_TIN_in->setInputMask("0_0_0_0_0_0_0_0_0_0");
    ui->le_TIN_out->setInputMask("0_0_0_0_0_0_0_0_0_0_0_0");
    ui->le_TIN_out->clear();
}

void MainWindow::on_rb_TIN_entity_clicked()
{
    ui->le_TIN_in->setInputMask("0_0_0_0_0_0_0_0_0");
    ui->le_TIN_out->setInputMask("0_0_0_0_0_0_0_0_0_0");
    ui->le_TIN_out->clear();
}

void MainWindow::on_pb_TIN_makeNum_clicked()
{
    QString str=ui->le_TIN_in->text();
    str.remove(QRegExp("_"));
    if(str=="")
        messError("Enter numbers or make Random");
    else
        ui->le_TIN_out->setText(_Tin.getFullTin(str));
}

void MainWindow::on_pb_TIN_makeRandom_clicked()
{
    ui->le_TIN_out->setText(_Tin.getFullTin("",ui->rb_TIN_individual->isChecked()));
}
