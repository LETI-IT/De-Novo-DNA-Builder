#-------------------------------------------------
#
# Project created by QtCreator 2016-03-27T22:28:27
#
#-------------------------------------------------
TARGET = DeNovo
TEMPLATE = subdirs

SUBDIRS += TestSuite \
            Source
CONFIG   += c++11
CONFIG += ordered

QMAKE_CXXFLAGS += -std=c++11
