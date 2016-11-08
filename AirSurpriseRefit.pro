TEMPLATE = app

QT += qml quick
CONFIG += c++11

include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

SOURCES += main.cpp \
    samplelistener.cpp \
    fingerqmlinterface.cpp \
    gestures/fingerpointer.cpp \
    gestures/holdgesturerecogniser.cpp \
    gestures/mousepointer.cpp

# RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

macx {
    QMAKE_MAC_SDK = macosx10.12
}

HEADERS += \
    samplelistener.h \
    fingerqmlinterface.h \
    gestures/fingerpointer.h \
    gestures/holdgesturerecogniser.h \
    gestures/mousepointer.h \
    gestures/pointeradapter.h

RESOURCES += \
    qml.qrc \
    res.qrc
