TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++1z -Og
LIBS += -lpthread -lviking -lstdc++fs -lz
INCLUDEPATH += /usr/include/viking

SOURCES += main.cpp \
    routes.cpp \
    chat.cpp \
    chat_manager.cpp

HEADERS += \
    routes.h \
    chat.h \
    chat_manager.h

