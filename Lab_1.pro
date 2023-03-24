TEMPLATE = app
TARGET = Lab_1
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

QT += widgets

SOURCES += \
        FileMonitor.cpp \
        FileState.cpp \
        main.cpp

HEADERS += \
    FileMonitor.h \
    FileState.h
