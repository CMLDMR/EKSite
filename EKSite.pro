#-------------------------------------------------
#
# Project created by QtCreator 2019-06-20T18:11:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EKSite
#TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14 console
CONFIG += no_keywords


#QMAKE_CXXFLAGS += -Wno-c++98-compat

SOURCES += \
    admin/admin.cpp \
    admin/yenivilla.cpp \
    body/body.cpp \
    eCore/containerwiget.cpp \
    eCore/db.cpp \
    eCore/item.cpp \
    eCore/listitem.cpp \
    main.cpp \
    mainapplication.cpp \
    villa/villa.cpp


HEADERS += \
    admin/admin.h \
    admin/yenivilla.h \
    body/body.h \
    bootstrap.h \
    eCore/containerwiget.h \
    eCore/db.h \
    eCore/item.h \
    eCore/listitem.h \
    inlinestyle.h \
    mainapplication.h \
    mongoheaders.h \
    villa/villa.h \
    wtinclude.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target






DISTFILES +=

QMAKE_CXXFLAGS += /wd4251 /wd4275 /wd4267 /wd4189

INCLUDEPATH += C:/boost/boost
DEPENDPATH += C:/boost/boost


win32: LIBS += -LC:/Mongo/msvc2017x64/lib/ -lbsoncxx -lmongocxx

INCLUDEPATH += C:/Mongo/msvc2017x64/include/bsoncxx/v_noabi
DEPENDPATH += C:/Mongo/msvc2017x64/include/bsoncxx/v_noabi

INCLUDEPATH += C:/Mongo/msvc2017x64/include/mongocxx/v_noabi
DEPENDPATH += C:/Mongo/msvc2017x64/include/mongocxx/v_noabi

win32: LIBS += -LC:/Wt-4.1.2-msvs2017-x64/lib/ -lwt -lwthttp

INCLUDEPATH += C:/Wt-4.1.2-msvs2017-x64/include
DEPENDPATH += C:/Wt-4.1.2-msvs2017-x64/include
