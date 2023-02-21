#include "mainwindow.h"

#include <QApplication>

#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;


    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint center = rect.center(); //координаты центра экрана
    int x = center.x() - (window.width()/2);  // учитываем половину ширины окна
    int y = center.y() - (window.height()/2); // .. половину высоты
    center.setX(x);
    center.setY(y);
    window.move(center);


    window.show();
    return a.exec();
}
