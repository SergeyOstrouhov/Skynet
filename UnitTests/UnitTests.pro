QT += testlib
QT -= gui
QT += network
QT += widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    test_parsing.cpp

HEADERS += ../function.h
