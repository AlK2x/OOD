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

INCLUDEPATH += C:/sdk/boost_1_57_0/
LIBS += "-LC:/sdk/boost_1_57_0/stage/lib/"

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    charmonicequation.cpp \
    newharmonicdialog.cpp \
    dialogpresenter.cpp \
    equationsolver.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    charmonicequation.h \
    newharmonicdialog.h \
    dialogpresenter.h \
    equationsolver.h

FORMS    += mainwindow.ui \
    newharmonicdialog.ui
