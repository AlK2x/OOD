#-------------------------------------------------
#
# Project created by QtCreator 2016-06-27T21:54:12
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Harmonic
TEMPLATE = app

INCLUDEPATH += C:/SDK/boost/
LIBS += "-LC:/SDK/boost/stage/lib/"

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    charmonicequation.cpp \
    newharmonicdialog.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    charmonicequation.h \
    newharmonicdialog.h

FORMS    += mainwindow.ui \
    newharmonicdialog.ui
