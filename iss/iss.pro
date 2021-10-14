QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = iss

SOURCES += \
    listview.cpp \
    main.cpp \
    mainmodel.cpp \
    presenter.cpp \
    widget.cpp \


HEADERS += \
    listview.h \
    mainmodel.h \
    presenter.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
