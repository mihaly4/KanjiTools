#-------------------------------------------------
#
# Project created by QtCreator 2012-09-23T12:17:44
#
#-------------------------------------------------

QT       += testlib sql

#QT       -= gui

TARGET = tst_qt_unit_test_testtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_qt_unit_test_testtest.cpp ../db_connection.cpp ../connector_wrapper.cpp


DEFINES += SRCDIR=\\\"$$PWD/\\\"

linux-*:QMAKE_CXXFLAGS += -std=gnu++0x
