QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    detectorcontroller.h \
    trafficlightdetector.h

SOURCES += \
        detectorcontroller.cpp \
        main.cpp \
        trafficlightdetector.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(../share/dbus/dbus.pri)
include(../share/share.pri)

INCLUDEPATH += ../3rdparty/opencv/include

LIBS += ../3rdparty/opencv/x64/mingw/bin/libopencv_core452.dll
LIBS += ../3rdparty/opencv/x64/mingw/bin/libopencv_highgui452.dll
LIBS += ../3rdparty/opencv/x64/mingw/bin/libopencv_imgcodecs452.dll
LIBS += ../3rdparty/opencv/x64/mingw/bin/libopencv_imgproc452.dll
LIBS += ../3rdparty/opencv/x64/mingw/bin/libopencv_features2d452.dll
LIBS += ../3rdparty/opencv/x64/mingw/bin/libopencv_calib3d452.dll
LIBS += ../3rdparty/opencv/x64/mingw/bin/libopencv_videoio452.dll
LIBS += ../3rdparty/opencv/x64/mingw/bin/libopencv_video452.dll
