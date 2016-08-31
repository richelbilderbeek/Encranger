include(../RibiLibraries/ConsoleApplicationNoWeffcpp.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)

include(EncrangerConsole.pri)
include(../RibiClasses/CppEncranger/CppEncranger.pri)
include(../RibiClasses/CppLoopReader/CppLoopReader.pri)

SOURCES += main.cpp

# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
