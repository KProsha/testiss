#include <QApplication>

#include "widget.h"
#include "mainmodel.h"
#include "presenter.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainModel model;
    Widget widget;
    Presenter presenter(&widget, &model);

    widget.show();
    return a.exec();
}
