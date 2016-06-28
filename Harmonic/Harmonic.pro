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

INCLUDEPATH += C:/SDK/boost_1_60_0/
LIBS += "-LC:/SDK/boost_1_60_0/stage/lib/"

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    charmonicequation.cpp \
    newharmonicdialog.cpp \
    dialogpresenter.cpp \
    equationsolver.cpp \
    harmonicfunctionlistmodel.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    charmonicequation.h \
    newharmonicdialog.h \
    dialogpresenter.h \
    equationsolver.h \
    harmonicfunctionlistmodel.h

FORMS    += mainwindow.ui \
    newharmonicdialog.ui
