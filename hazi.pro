#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T06:04:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hazi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewindow.cpp \
    ship.cpp \
    waitclientdialog.cpp \
    utilities.cpp

HEADERS  += mainwindow.h \
    gamewindow.h \
    ship.h \
    waitclientdialog.h \
    utilities.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    images.qrc
