include(../RibiLibraries/WebApplication.pri)
include(../RibiLibraries/BoostAll.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralWeb.pri)
include(../RibiLibraries/Wt.pri)

include(../RibiClasses/CppEncranger/CppEncranger.pri)
include(../RibiClasses/CppLoopReader/CppLoopReader.pri)

include(EncrangerWebsite.pri)

SOURCES += wtmain.cpp

# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
