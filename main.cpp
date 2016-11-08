//#include <QtGui/QGuiApplication>
//#include <QtQml/QQmlEngine>
//#include <QtQml/QQmlContext>

#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <memory>

#include "samplelistener.h"
#include "fingerqmlinterface.h"
#include "qtquick2applicationviewer.h"

using namespace Leap;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
//    QtQuick2ApplicationViewer viewer;

    std::shared_ptr<FingerQMLInterface> qmlInterface(new FingerQMLInterface(&engine));
//    SampleListener listener(&viewer, qmlInterface);
//    viewer.setDelegate(&listener);

//    Controller leapController;
//    leapController.addListener(listener);

    engine.rootContext()->setContextProperty("_QmlInterface", qmlInterface.get());
    engine.load(QUrl(QLatin1String("qrc:/qml/AirSurprise/main.qml")));

    return app.exec();
}
