#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
//myIncludes
#include <stringhelper.h>
#include <stylehelper.h>
#include <shifrCaeser.h>
#include <shifrtrithemius.h>
#include <shifrvigenera.h>
#include <tablepermutation.h>
#include <rsa.h>
#include <shenonfano.h>
#include <paritycheck.h>
#include <tin.h>

#define SIZECODE 7

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *e) override;

private slots:
    void on_pb_Caesar_shifr_clicked();

    void on_pb_Caesar_RasShifr_clicked();

    void on_cb_Caesar_lanq_currentIndexChanged(int index);

    void on_pb_Trithemius_shifr_clicked();

    void on_pb_Trithemius_RasShifr_clicked();

    void on_cb_Trithemius_lanq_currentIndexChanged(int index);

    void on_pb_Vigener_shifr_clicked();

    void on_pb_Vigener_RasShifr_clicked();

    void on_cb_Vigener_lanq_currentIndexChanged(int index);

    void on_pb_Permutation_shifr_clicked();

    void on_pb_Permutation_RasShifr_clicked();

    void on_pb_Rsa_genKey_clicked();

    void on_pb_Rsa_shifr_clicked();

    void on_pb_Rsa_RasShifr_clicked();

    void on_cb_Rsa_lanq_currentIndexChanged(int index);

    void on_pb_Rsa_saveKeys_clicked();

    void on_pb_Rsa_saveResult_clicked();

    void on_pb_ShenonFano_fillTable_clicked();

    void on_pb_ParityCheck_convert_clicked();

    void on_pb_ParityCheck_Reconvert_clicked();

    void on_rb_TIN_individual_clicked();

    void on_rb_TIN_entity_clicked();

    void on_pb_TIN_makeNum_clicked();

    void on_pb_TIN_makeRandom_clicked();

private:
    Ui::MainWindow *ui;
    stylehelper _styleHelper;
    stringHelper _strHelper;
    ShifrCaeser _shifrCaeser;
    shifrVigenera _shifrVigener;
    shifrTrithemius _shifrTrithemius;
    tablePermutation _tablePerm;
    Rsa _Rsa;
    ShenonFano _ShenonFano;
    ParityCheck _parityCheck;
    TIN _Tin;

    int *RsaKeys;
    double *probabilityShenon;
    QString *codeCharShenonFano;

    void setInterfaceStyle();
    void setTabWidgetStyle();
    void setShenonFanoTableWidgetStyle(int rowCount);
    void messError(QString mess);
    void reqursiaShenon(int start,int end,bool topORbot);
    void setCodeCharShenonFano(int indexStr,bool oneORzero);
};
#endif // MAINWINDOW_H
