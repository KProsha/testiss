QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = testiss

MAINSRCPATH = $${PWD}/../iss

INCLUDEPATH += $${MAINSRCPATH}

SOURCES += \
    main.cpp \
    $${MAINSRCPATH}/listview.cpp \
    $${MAINSRCPATH}/mainmodel.cpp \
    $${MAINSRCPATH}/presenter.cpp \
    $${MAINSRCPATH}/widget.cpp

HEADERS += \
    $${MAINSRCPATH}/listview.h \
    $${MAINSRCPATH}/mainmodel.h \
    $${MAINSRCPATH}/presenter.h \
    $${MAINSRCPATH}/widget.h

FORMS += \
    $${MAINSRCPATH}/widget.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
