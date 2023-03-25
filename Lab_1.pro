TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt


SOURCES += \
        ChangeOutput.cpp \
        FileMonitor.cpp \
        FileState.cpp \
        main.cpp

HEADERS += \
    ChangeOutput.h \
    FileMonitor.h \
    FileState.h
