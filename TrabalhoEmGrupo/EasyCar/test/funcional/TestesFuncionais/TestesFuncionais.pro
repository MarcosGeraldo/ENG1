QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../../../src/lib/rentHB.cpp \
        ../../../src/lib/systemHB.cpp \
        ../../../src/lib/userHB.cpp \
        ../../../src/lib/vehicleHB.cpp \
        ../../unit/testesunitarios.cpp \
        ../main.cpp \
        ../testesfuncionais.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../../src/lib/handleBodySemDebug.h \
    ../../../src/lib/rent.h \
    ../../../src/lib/rentHB.h \
    ../../../src/lib/system.h \
    ../../../src/lib/systemHB.h \
    ../../../src/lib/user.h \
    ../../../src/lib/userHB.h \
    ../../../src/lib/vehicle.h \
    ../../../src/lib/vehicleHB.h \
    ../../unit/testesunitarios.h \
    ../testesfuncionais.h
