#include <QApplication>
#include <QTest>

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

    for(int i = 0; i < 30; ++i){
        QTest::keyClicks(widget.mainLineEdit(), QString("Test %1").arg(i));
        QTest::mouseClick(widget.addMainButton(), Qt::LeftButton);
    }


    return a.exec();
}
