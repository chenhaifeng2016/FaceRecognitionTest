#-------------------------------------------------
#
# Project created by QtCreator 2017-09-19T17:08:45
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FaceRecognitionTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../IDCardReader/lib/ -lIDCardReader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../IDCardReader/lib/ -lIDCardReaderd

INCLUDEPATH += $$PWD/../../IDCardReader/include
DEPENDPATH += $$PWD/../../IDCardReader/include

win32: LIBS += -L$$PWD/../../FaceRecognitionTest/third_party/wtl/ -lWltRS

INCLUDEPATH += $$PWD/../../FaceRecognitionTest/third_party/wtl
DEPENDPATH += $$PWD/../../FaceRecognitionTest/third_party/wtl

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../FaceRecognitionDLL/lib/ -lFaceRecognitionDLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../FaceRecognitionDLL/lib/ -lFaceRecognitionDLLd

INCLUDEPATH += $$PWD/../../FaceRecognitionDLL/include
DEPENDPATH += $$PWD/../../FaceRecognitionDLL/include
