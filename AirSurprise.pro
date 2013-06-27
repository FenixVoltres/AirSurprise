# Add more folders to ship with the application, here
folder_01.source = qml/AirSurprise
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    samplelistener.cpp \
    fingerqmlinterface.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2applicationviewer/qtquick2applicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += \
    leap/Leap.i

HEADERS += \
    leap/LeapMath.h \
    leap/Leap.h \
    samplelistener.h \
    fingerqmlinterface.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/ -lLeap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/ -lLeapd

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Leap.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Leapd.lib
