QT += core
QT -= gui
TARGET = Jhr_test
TEMPLATE = app
CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        main.cpp \
    jhr_test.cpp \
    jhr_stdin.cpp

HEADERS += \
    jhr_test.h \
    jhr_stdin.h
