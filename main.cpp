#include <QtGui/QGuiApplication>
#include <memory>
#include "qtquick2applicationviewer.h"

#include "samplelistener.h"
#include "leap/Leap.h"

using namespace Leap;
using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    auto_ptr<Listener> listener(new SampleListener());
    Leap::Controller leapController;

    leapController.addListener(*listener);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/AirSurprise/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
