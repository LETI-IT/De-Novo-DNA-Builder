#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T00:56:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Source
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    digraph.cpp \
    digraphiterator.cpp

HEADERS  += mainwindow.h \
    digraph.h \
    igraph.h \
    digraphiterator.h \
    abstractiterator.h \
    euleriancircuit.h

FORMS    += mainwindow.ui
