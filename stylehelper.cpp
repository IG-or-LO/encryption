#include "stylehelper.h"

QString stylehelper::getTabWidgetStyle()
{
    return "QTabWidget{"
           "border: none;"
            "}"
            "QTabWidget::pane {"
            "border:3px;"
            "background: black;"
            "}"
            "QTabBar::tab {"
            "border:none;"
            "}";
}

QString stylehelper::getTabsStyle()
{
    return "QWidget#Caesar {"
           " border-image: url(:/resources/img/fone2.png) 0 0 0 0 stretch stretch;"
           "} "
            "QWidget#Trithemius {"
                       " border-image: url(:/resources/img/fone2.png) 0 0 0 0 stretch stretch;"
                       "} "
            "QWidget#Vigener {"
                       " border-image: url(:/resources/img/fone2.png) 0 0 0 0 stretch stretch;"
                       "} "
             "QWidget#tablePermutation {"
                              " border-image: url(:/resources/img/fone2.png) 0 0 0 0 stretch stretch;"
                              "} "
           "QWidget#RSA {"
                      " border-image: url(:/resources/img/fone2.png) 0 0 0 0 stretch stretch;"
           "} "
           "QWidget#ShenonFano {"
                      " border-image: url(:/resources/img/fone2.png) 0 0 0 0 stretch stretch;"
           "} "
           "QWidget#ParityCheck {"
                      " border-image: url(:/resources/img/fone2.png) 0 0 0 0 stretch stretch;"
           "} "
           "QWidget#TIN {"
                      " border-image: url(:/resources/img/fone2.png) 0 0 0 0 stretch stretch;"
           "} "
            "QWidget#wt_TIN {"
                       " border-image: url(:/resources/img/TIN.png) 0 0 0 0 stretch stretch;"
            "} ";
}

QString stylehelper::getLablesStyle()
{
    return "QLabel{"
            "color:#fff;"
            "background: none;"
            "border: none;"
            "border-radius:1px;"
            "font-family: 'Roboto-Medium';"
            "font-size:20px;"
           "}";
}

QString stylehelper::getCheckBoxStyle()
{
    return "QCheckBox{"
            "color:#fff;"
           "font-family: 'Roboto-Medium';"
            "font-weight: 600;"
            "font-size:18px;"
            "background:#133C44;"
           "}"

            "QCheckBox::indicator {"
                "width: 18px;"
                "height: 18px;"
                "background:#62f6e6;"
            "}"

            "QCheckBox::indicator:checked {"
                "image: url(:/resources/img/cross2.png);"
            "}"
            ;
}

QString stylehelper::getSpinBoxStyle()
{
    return "QSpinBox{"
            "color:white;"
           "font-family: 'Roboto-Medium';"
            "border:none;"
            "font-weight: 600;"
            "background:  qlineargradient(spread:reflect, x1:1, y1:0.533818, x2:1, y2:0, stop:0.375 rgba(0, 83, 67, 255), stop:1 rgba(0, 0, 14, 255));"
           "font-size:20px;"
           "}";
}

QString stylehelper::getTabBarStyle()
{
    return "QTabBar::tab {"
            "background: qlineargradient(spread:reflect, x1:1, y1:0, x2:1, y2:0.465909, stop:0 rgba(0, 0, 14, 255), stop:0.514851 rgba(0, 0, 83, 255)); "
            "color:#fff;"
            "font-weight: 600;"
            "min-width:20ex;"
            "min-height:8ex;"
            "margin:25px ;"
            "border-radius:20px;"
            "}"
            "QTabBar::tab:selected {"
           "background:qlineargradient(spread:repeat, x1:0.717, y1:0.193182, x2:0.067, y2:0.807045, stop:0.48 rgba(0, 107, 180, 255), stop:1 rgba(53, 0, 180, 255));"
           "}"
           "QTabBar::tab:hover {"
          "background:qlineargradient(spread:reflect, x1:1, y1:0.533818, x2:1, y2:0, stop:0.375 rgba(0, 83, 67, 255), stop:1 rgba(0, 0, 14, 255));"
           "}";
}


QString stylehelper::getCentralWidgetStyle()
{
    return "QWidget{"
            "background:black;"
            "}";
}

QString stylehelper::getTextEditStyle()
{
    return "QTextEdit {"
            "background: qlineargradient(spread:pad, x1:0.51705, y1:0, x2:0.527, y2:1, stop:1 rgba(94, 195, 225, 255));"
           "color:black;"
            "border-radius:20px;"
            "padding:10px;"
            "font-weight: 600;"
           "font-family: 'Roboto-Medium';"
           "font-size:18px;"
           "}";
}

QString stylehelper::getTextEditOutStyle()
{
    return "QTextEdit {"
            "background: qlineargradient(spread:pad, x1:0.51705, y1:0, x2:0.527, y2:1, stop:1 rgba(94, 195, 225, 255));"
           "color:#760eab;"
            "border-radius:20px;"
            "padding:10px;"
            "font-weight: 600;"
           "font-family: 'Roboto-Medium';"
           "font-size:18px;"
           "}";
}

QString stylehelper::getButtonsStyle()
{
    return "QPushButton{"
        "color: #fff;"
        "border-radius: 15px;"
        "padding: 10px 25px;"
        "font-family: 'Roboto-Medium';"
        "font-weight: 600;"
        "position: relative;"
        "outline: none;"
        "background: qlineargradient(spread:pad, x1:0.46005, y1:0.403409, x2:1, y2:1, stop:0 rgba(22, 119, 100, 255), stop:0.856436 rgba(22, 119, 255, 255));"
      "}"
           "QPushButton:hover{"
           "background:qlineargradient(spread:pad, x1:0.56005, y1:0.596591, x2:0, y2:0, stop:0 rgba(22, 119, 100, 255), stop:1 rgba(22, 119, 255, 255));"
        "}"
            ;
}

QString stylehelper::getComboBoxStyle()
{
    return "QComboBox{"
            "background:none;"
             "color:#167764;"
            "font-family: 'Roboto-Medium';"
            "font-weight: 600;"
            "font-size:18px;"
            "background-color: #072721;"
            "}";
}

QString stylehelper::getCeaserLableStyle()
{
    return "QLabel{"
            "border-image: url(:/resources/img/ceaser.jpeg) 0 0 0 0 stretch stretch;"
            "border-radius:20px;"
           "}";
}

QString stylehelper::getTrithemiusLableStyle()
{
    return "QLabel{"
            "border-image: url(:/resources/img/Trithemius.jpg) 0 0 0 0 stretch stretch;"
            "border-radius:20px;"
           "}";
}

QString stylehelper::getVigenerLableStyle()
{
    return "QLabel{"
            "border-image: url(:/resources/img/viginer.jpeg) 0 0 0 0 stretch stretch;"
            "border-radius:20px;"
           "}";
}

QString stylehelper::getPermutationLableStyle()
{
    return "QLabel{"
            "border-image: url(:/resources/img/permutation.png) 0 0 0 0 stretch stretch;"
            "border-radius:20px;"
           "}";
}
QString stylehelper::getRsaLableStyle()
{
    return "QLabel{"
            "border-image: url(:/resources/img/rsa.png) 0 0 0 0 stretch stretch;"
            "border-radius:20px;"
           "}";
}

QString stylehelper::getTableWidgetStyle()
{
    return "QTableWidget {"
            "selection-background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:0, y2:0.29, stop:0 rgba(146, 0, 137, 255), stop:1 rgba(18, 153, 211, 255));"
            "background-color: qlineargradient(spread:pad, x1:0.51705, y1:0, x2:0.527, y2:1, stop:1 rgba(94, 195, 225, 255));"
            "color:#760eab;"
            "font-weight: 600;"
            "font-family: 'Roboto-Medium';"
            "font-size:18px;"
            "border:1px solid #c3c3c3;"
            "border-radius:5px;"
           "}"
            "QTableWidget QTableCornerButton::section{"
            "background-color: qlineargradient(spread:pad, x1:0.51705, y1:0, x2:0.527, y2:1, stop:1 rgba(94, 195, 225, 255));"
            "}"
            "QHeaderView {"
            "background-color: qlineargradient(spread:pad, x1:0.51705, y1:0, x2:0.527, y2:1, stop:1 rgba(94, 195, 225, 255));"
            "font-weight: 600;"
            "font-family: 'Roboto-Medium';"
            "font-size:16px;"
            "}"
            ;
}

QString stylehelper::getShenonFanoLableStyle()
{
    return "QLabel{"
            "border-image: url(:/resources/img/shenon.jpg) 0 0 0 0 stretch stretch;"
            "border-radius:20px;"
           "}";
}

QString stylehelper::getLineEditStyle()
{
    return "QLineEdit {"
            "background: qlineargradient(spread:pad, x1:0.51705, y1:0, x2:0.527, y2:1, stop:1 rgba(94, 195, 225, 255));"
            "color:#760eab;"
            "border-radius:20px;"
            "padding:10px;"
            "font-weight: 600;"
           "font-family: 'Roboto-Medium';"
           "font-size:18px;"
           "}";
}

QString stylehelper::getLineEditTINStyle()
{
    return "QLineEdit {"
            "background: white;"
            "color:black;"
            "border-radius:20px;"
            "padding:5px;"
            "font-weight: 400;"
           "font-family: 'Roboto-Medium';"
           "font-size:12px;"
           "}";
}

QString stylehelper::getRadioButtonStyle()
{
    return "QRadioButton {"
            "color:white;"
           "font-family: 'Roboto-Medium';"
            "border:none;"
            "font-weight: 600;"
            "background:  qlineargradient(spread:reflect, x1:1, y1:0.533818, x2:1, y2:0, stop:0.375 rgba(0, 83, 67, 255), stop:1 rgba(0, 0, 14, 255));"
           "font-size:20px;"
           "}";
}

QString stylehelper::getTINLableStyle()
{
    return "QLabel{"
            "border-image: url(:/resources/img/nalog.jpg) 0 0 0 0 stretch stretch;"
            "border-radius:20px;"
            "}";
}
