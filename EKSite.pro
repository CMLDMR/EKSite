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

SOURCES += \
        admin/adminpanel.cpp \
        admin/villaaddpage.cpp \
        admin/villaadminpage.cpp \
        admin/villalistpage.cpp \
        base/containerwidget.cpp \
        base/dbclass.cpp \
        base/userclass.cpp \
        base/villaitem.cpp \
        body/body.cpp \
        body/footer.cpp \
        body/header.cpp \
        customwidgets/loginwidget.cpp \
        customwidgets/placethumpnails.cpp \
        customwidgets/reservationwidget.cpp \
        customwidgets/slider.cpp \
        ilancontainer.cpp \
        main.cpp \
        mainapplication.cpp

HEADERS += \
    admin/adminpanel.h \
    admin/villaaddpage.h \
    admin/villaadminpage.h \
    admin/villalistpage.h \
    base/containerwidget.h \
    base/dbclass.h \
    base/userclass.h \
    base/villaitem.h \
    body/body.h \
    body/footer.h \
    body/header.h \
    bootstrap.h \
    customwidgets/loginwidget.h \
    customwidgets/placethumpnails.h \
    customwidgets/reservationwidget.h \
    customwidgets/slider.h \
    ilancontainer.h \
    inlinestyle.h \
    mainapplication.h \
    mongoheaders.h \
    wtinclude.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target






#win32: LIBS += -L$$PWD/../../Yonetim-yazilimi/Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/lib/ -lwt
#win32: LIBS += -L$$PWD/../../Yonetim-yazilimi/Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/lib/ -lwthttp

#INCLUDEPATH += $$PWD/../../Yonetim-yazilimi/Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/include
#DEPENDPATH += $$PWD/../../Yonetim-yazilimi/Server/WebServer/Wt-4.0.0-msvs2015-Windows-x64-SDK/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lbsoncxx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lbsoncxxd
else:unix: LIBS += -L$$PWD/lib/ -lbsoncxx

INCLUDEPATH += $$PWD/include/bsoncxx/v_noabi
DEPENDPATH += $$PWD/include/bsoncxx/v_noabi

INCLUDEPATH += $$PWD/Body
DEPENDPATH += $$PWD/Body



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lmongocxx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lmongocxxd
else:unix: LIBS += -L$$PWD/lib/ -lmongocxx

INCLUDEPATH += $$PWD/include/mongocxx/v_noabi
DEPENDPATH  += $$PWD/include/mongocxx/v_noabi


#INCLUDEPATH += $$PWD/../../Yonetim-yazilimi/Boost/boost/
#DEPENDPATH  += $$PWD/../../Yonetim-yazilimi/Boost/boost/

#INCLUDEPATH += $$PWD/../../Yonetim-yazilimi/Comman
#DEPENDPATH  += $$PWD/../../Yonetim-yazilimi/Comman



#win32: LIBS += -L$$PWD/../../../local/boost_1_70_0/lib64-msvc-14.1/ -lboost_bzip2-vc141-mt-gd-x64-1_70

INCLUDEPATH += $$PWD/../../../local/boost_1_70_0/
DEPENDPATH += $$PWD/../../../local/boost_1_70_0/

win32: LIBS += -L$$PWD/../../Wt/Wt-4.1.0-msvs2015-x64/lib/ -lwt -lwthttp

INCLUDEPATH += $$PWD/../../Wt/Wt-4.1.0-msvs2015-x64/include
DEPENDPATH += $$PWD/../../Wt/Wt-4.1.0-msvs2015-x64/include

DISTFILES +=
