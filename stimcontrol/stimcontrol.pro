#-------------------------------------------------
#
# Project created by QtCreator 2016-08-28T22:43:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = stimcontrol
TEMPLATE = app


SOURCES += main.cpp\
        stimcontrol.cpp

HEADERS  += stimcontrol.h

FORMS    += stimcontrol.ui


INCLUDEPATH    += /home/leo/raspi3/sysroot/usr/include
LIBS += -L/home/leo/raspi3/sysroot/usr/lib -lpigpio

RESOURCES += \
    myresources.qrc


