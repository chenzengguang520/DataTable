#include "DataTable.h"
#include "MainWidgets.h"
#include "LogWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //DataTable w;
    //w.show();
	/*MainWidgets w;
	w.show();*/
    LogWidget log;
    log.show();
    return a.exec();
}
