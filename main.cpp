#include <QtGui/QGuiApplication>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>

#include "leap/Leap.h"
#include "samplelistener.h"
#include "fingerqmlinterface.h"
#include "qtquick2applicationviewer.h"

using namespace Leap;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;

    FingerQMLInterface *qmlInterface = new FingerQMLInterface(&viewer);
    SampleListener listener(qmlInterface);

    Controller leapController;
    leapController.addListener(listener);

    viewer.engine()->rootContext()->setContextProperty("_QmlInterface", qmlInterface);
    viewer.setMainQmlFile(QStringLiteral("qml/AirSurprise/main.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.showFullScreen();

    return app.exec();
}
