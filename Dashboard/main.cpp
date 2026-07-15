#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.setWindowTitle("VoltGuard Dashboard");
    window.resize(900, 600);
    window.show();

    return app.exec();
}