QT += core gui widgets opengl openglwidgets

LIBS += -lopengl32 -lglu32

TARGET = fractalgenerator

TEMPLATE = app

RC_ICONS = fractalsymb.ico

SOURCES += \
    glwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    glwidget.h \
    main.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

