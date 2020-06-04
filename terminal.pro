QT += widgets serialport
requires(qtConfig(combobox))

TARGET = terminal
TEMPLATE = app

RC_FILE = terminal.rc

SOURCES += \
    debug.cpp \
    dmxconsole.cpp \
    ledrgbold.cpp \
    loadingdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    qtdmxlib.cpp \
    settingsdialog.cpp \
    console.cpp

HEADERS += \
    debug.h \
    dmxconsole.h \
    ledrgbold.h \
    loadingdialog.h \
    mainwindow.h \
    qtdmxlib.h \
    settingsdialog.h \
    console.h

FORMS += \
    dmxconsole.ui \
    ledrgbold.ui \
    loadingdialog.ui \
    mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target

DISTFILES += \
    terminal.exe.manifest
