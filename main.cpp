//#include <QtGui/QGuiApplication>
//#include <QtQml/QQmlEngine>
//#include <QtQml/QQmlContext>

#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QQmlContext>

#include "InputEventDelegate.h"

#include "samplelistener.h"
#include "fingerqmlinterface.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    FingerQMLInterface qmlInterface;
    SampleListener listener(&qmlInterface);
    InputEventDelegate inputEventDelegate(&listener);


    engine.rootContext()->setContextProperty("_QmlInterface", &qmlInterface);

    engine.load(QUrl(QLatin1String("qrc:/qml/AirSurprise/main.qml")));
    engine.rootObjects()[0]->installEventFilter(&inputEventDelegate);

    return app.exec();
}
