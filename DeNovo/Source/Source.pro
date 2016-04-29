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
    edgeiterator.cpp \
    edge.cpp \
    vertexiterator.cpp \
    vertex.cpp

HEADERS  += mainwindow.h \
    digraph.h \
    igraph.h \
    abstractiterator.h \
    euleriancircuit.h \
    edgeiterator.h \
    abstractcomponent.h \
    edge.h \
    typeiterator.h \
    vertexiterator.h \
    vertex.h

FORMS    += mainwindow.ui
