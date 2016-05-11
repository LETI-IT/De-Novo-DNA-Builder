#-------------------------------------------------
#
# Project created by QtCreator 2016-04-11T00:12:27
#
#-------------------------------------------------
include(../Source/Source.pri)

QT       += testlib

QT       -= gui

TARGET = tst_testsuitetest
CONFIG   += console
CONFIG   -= app_bundle


TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

HEADERS += mocfactory.h
SOURCES += tst_testsuitetest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
