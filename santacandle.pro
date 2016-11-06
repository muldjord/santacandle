TEMPLATE = app
TARGET = SantaCandle
DEPENDPATH += .
INCLUDEPATH += .
#CONFIG += console
QT += core gui

include(./VERSION)
DEFINES+=VERSION=\\\"$$VERSION\\\"

# Input
HEADERS += santacandle.h \
           candleflame.h \
           about.h \
           inferno.h \
           pixies.h

SOURCES += santacandle.cpp \
           candleflame.cpp \
           about.cpp \
           inferno.cpp \
           pixies.cpp \
           main.cpp

RESOURCES += santacandle.qrc
TRANSLATIONS = santacandle_da_DK.ts
RC_FILE = santacandle.rc
