# QT Modules
QT += qml quick

# Target
TARGET = LcmRecv
TEMPLATE = app

# Extra Configs
CONFIG += c++11

# Sources and Headers
INCLUDEPATH += src
HEADERS += \
    Src/LcmRecv.hpp \
    Src/LcmDataParse.hpp \
    Src/example_t.hpp \

SOURCES += \
    Src/main.cpp \
    Src/LcmRecv.cpp \
    Src/LcmDataParse.cpp \

# Resources
RESOURCES += qml.qrc
QMAKE_RESOURCE_FLAGS += -no-compress

INCLUDE += /usr/local/include
LIBS += /usr/local/lib/liblcm.so

# Objects Pathes
DESTDIR = bin
UI_DIR = build
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build
QMAKE_POST_LINK += $(STRIP) $(TARGET)


