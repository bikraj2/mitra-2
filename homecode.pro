QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog1.cpp \
    dialog2.cpp \
    forgotpassword.cpp \
    main.cpp \
    mainwindow.cpp \
    signup.cpp\
    taskadder.cpp \
    todo.cpp

HEADERS += \
    dialog1.h \
    dialog2.h \
    forgotpassword.h \
    mainwindow.h \
    signup.h\
    taskadder.h \
    todo.h

FORMS += \
    dialog1.ui \
    dialog2.ui \
    forgotpassword.ui \
    mainwindow.ui \
    signup.ui\
    taskadder.ui \
    todo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
