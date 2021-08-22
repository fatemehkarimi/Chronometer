QT += widgets
TEMPLATE = app

HEADERS += headers/MainWindow.h \
           headers/TimerWindow.h \
           headers/Timer.h \
           headers/Controller.h \
           headers/TimeController.h \
           headers/ChronoView.h \
           headers/ChronoController.h

SOURCES += main.cpp \
           MainWindow.cpp \
           TimerWindow.cpp \
           Timer.cpp \
           TimeController.cpp \
           ChronoView.cpp \
           ChronoController.cpp