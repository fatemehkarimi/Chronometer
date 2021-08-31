QT += core widgets
TEMPLATE = app
TARGET = Chronometer

INCLUDEPATH += $$PWD/include/
HEADERS += $$PWD/include/$$TARGET/*.h
HEADERS += $$PWD/include/$$TARGET/Components/*.h
SOURCES += $$PWD/src/*.cpp
SOURCES += $$PWD/src/Components/*.cpp

unix {
  # Enable ASAN to take care of memory operations.
  CONFIG(debug, debug | release) {
    QMAKE_CXXFLAGS += -ggdb
    QMAKE_LFLAGS += -fsanitize=address
    QMAKE_CXXFLAGS += -fsanitize=address
  }

  # Enable extra GCC/Clang/TCC warnings
  QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic
}

win32-msvc* {
  # Enable extra MSVC warnings
  QMAKE_CXXFLAGS += /Wall
}
