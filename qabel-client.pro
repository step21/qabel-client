#-------------------------------------------------
#
# Project created by QtCreator 2014-02-03T07:21:09
#
#-------------------------------------------------

QABEL_LIB_SRC = $$PWD/../qabel-lib
QABEL_LIB_BUILD = $$PWD/../qabel-lib/build

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG(branding) {
    message(Building with official Qabel branding.)
    DEFINES += QABEL_BRANDING
    QT += multimedia
}

TARGET = qabel-client
TEMPLATE = app


SOURCES += src/main.cpp \
    src/qbl-css.cpp \
    src/qbl-client.cpp \
    src/desktop/qbl-desktop-client.cpp \
    src/desktop/qbl-desktop-addressbook.cpp \
    src/desktop/qbl-desktop-chat.cpp \
    src/qbl-content.cpp \
    src/desktop/qbl-desktop-list-identity.cpp \
    src/desktop/qbl-desktop-list-item.cpp \
    src/desktop/qbl-desktop-list-address-row.cpp \
    src/desktop/qbl-desktop-chat-content.cpp \
    src/desktop/qbl-desktop-content.cpp \
    src/desktop/qbl-desktop-wizard.cpp \
    src/desktop/qbl-desktop-settings.cpp \
    src/desktop/qbl-desktop-list-settings-row.cpp \
    src/desktop/qbl-desktop-settings-identity.cpp \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-intro.cpp \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-newuser.cpp \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-chooseconfig.cpp \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-choosedirectory.cpp \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-createidentity.cpp \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-createmasterkey.cpp \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-ffsyncserver.cpp \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-lastpage.cpp \
    src/desktop/qbl-desktop-content-settings.cpp \
    src/desktop/qbl-desktop-content-addressbook.cpp \
    src/desktop/qbl-desktop-content-chat.cpp \
    src/desktop/qbl-desktop-content-file.cpp \
    src/desktop/qbl-desktop-address-identity.cpp \
    src/desktop/qbl-desktop-addressbook-content.cpp \
    src/desktop/qbl-desktop-ballon.cpp \
    src/desktop/qbl-desktop-chat-ballon-me.cpp \
    src/desktop/qbl-desktop-chat-ballon-other.cpp \
    src/desktop/qbl-desktop-config-preferences.cpp \
    src/desktop/qbl-desktop-config-drop_servers.cpp \
    src/desktop/qbl-desktop-chat-ballon.cpp \
    src/desktop/qbl-desktop-file.cpp \
    src/desktop/qbl-desktop-fcontent.cpp \
    src/desktop/qbl-desktop-topinfo-list.cpp \
    src/desktop/qbl-desktop-list-file-row.cpp \
    src/desktop/qbl-desktop-addnewcontact.cpp


HEADERS  += \
    include/qbl-css.h \
    include/qbl-desktop-client.h \
    include/qbl-client.h \
    src/desktop/qbl-desktop-addressbook.h \
    src/desktop/qbl-desktop-chat.h \
    include/qbl-content.h \
    src/desktop/qbl-desktop-list-identity.h \
    src/desktop/qbl-desktop-list-item.h \
    src/desktop/qbl-desktop-list-address-row.h \
    src/desktop/qbl-desktop-content.h \
    src/desktop/qbl-desktop-chat-content.h \
    src/desktop/qbl-desktop-wizard.h \
    src/desktop/qbl-desktop-settings.h \
    src/desktop/qbl-desktop-list-settings-row.h \
    src/desktop/qbl-desktop-settings-identity.h \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-intro.h \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-newuser.h \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-chooseconfig.h \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-choosedirectory.h \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-createidentity.h \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-createmasterkey.h \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-ffsyncserver.h \
    src/desktop/wizard-pages/qbl-desktop-wizard-page-lastpage.h \
    src/desktop/qbl-desktop-content-settings.h \
    src/desktop/qbl-desktop-content-addressbook.h \
    src/desktop/qbl-desktop-content-chat.h \
    src/desktop/qbl-desktop-content-file.h \
    src/desktop/qbl-desktop-settings-constants.h \
    src/desktop/qbl-desktop-address-identity.h \
    src/desktop/qbl-desktop-addressbook-content.h \
    src/desktop/qbl-desktop-ballon.h \
    src/desktop/qbl-desktop-chat-ballon-me.h \
    src/desktop/qbl-desktop-chat-ballon-other.h \
    src/desktop/qbl-desktop-config-preferences.h \
    src/desktop/qbl-desktop-config-drop_servers.h \
    src/desktop/qbl-desktop-chat-ballon.h \
    src/desktop/qbl-desktop-file.h \
    src/desktop/qbl-desktop-fcontent.h \
    src/desktop/qbl-desktop-topinfo-list.h \
    src/desktop/qbl-desktop-list-file-row.h \
    src/desktop/qbl-desktop-addnewcontact.h


FORMS    += \
    forms/qbl-desktop-client.ui \
    forms/qbl-desktop-list-identity.ui \
    forms/qbl-desktop-list-row.ui \
    forms/qbl-desktop-content.ui \
    forms/qbl-desktop-chat-content.ui \
    forms/qbl-desktop-config-block_servers.ui \
    forms/qbl-desktop-config-drop_servers.ui \
    forms/qbl-desktop-config-identities.ui \
    forms/qbl-desktop-config-preferences.ui \
    forms/qbl-desktop-config-shares.ui \
    forms/qbl-desktop-config-list.ui \
    forms/qbl-desktop-list-row-config.ui \
    forms/qbl-desktop-addressbook-content.ui \
    forms/qbl-desktop-ballon.ui \
    forms/qbl-desktop-chat-ballon-me.ui \
    forms/qbl-desktop-chat-ballon-other.ui \
    forms/qbl-desktop-fcontent.ui \
    forms/qbl-desktop-topinfo-list.ui \
    forms/qbl-desktop-addnewcontact.ui

CONFIG += mobility
MOBILITY = 

QMAKE_CXXFLAGS += -std=c++11


win32:CONFIG(release, debug|release): LIBS += -L$$QABEL_LIB_SRC/.libs/release/ -lqabel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$QABEL_LIB_SRC/src/.libs/debug/ -lqabel
else:unix: LIBS += -L$$QABEL_LIB_BUILD/src/ -lqabel

INCLUDEPATH += $$PWD/include \
    $$QABEL_LIB_SRC/include \
    $$QABEL_LIB_SRC/src
DEPENDPATH += $$QABEL_LIB_BUILD/src/

RESOURCES += \
    qabel-client.qrc

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += json-c

mac:CONFIG+=c++11
mac:QT_CONFIG -= no-pkg-config
