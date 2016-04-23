#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T15:31:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sc2overlay
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    todolist.cpp \
    choices.cpp \
    buildorder.cpp \
    globals.cpp

HEADERS  += mainwindow.h \
    choices.h \
    buildorder.h \
    globals.h

FORMS    += mainwindow.ui \
    choices.ui

win32:LIBS += -luser32

DISTFILES += \
    overlay.ico \
    overlay.rc

RC_FILE = overlay.rc
CONFIG+= static
