TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    game.cpp \
    userinterface.cpp \
    user.cpp \
    player.cpp \
    bot.cpp

HEADERS += \
    game.h \
    userinterface.h \
    user.h \
    player.h \
    bot.h
