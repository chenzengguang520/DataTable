#include "DataTable.h"
#include "MainWidgets.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //DataTable w;
    //w.show();
    MainWidgets w;
    w.show();
    return a.exec();
}
