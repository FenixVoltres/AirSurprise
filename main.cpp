#include <QtGui/QGuiApplication>
#include <memory>

#include "leap/Leap.h"
#include "samplelistener.h"
#include "fingerqmlinterface.h"
#include "qtquick2applicationviewer.h"

using namespace Leap;
using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Leap::Controller leapController;
    auto_ptr<FingerQMLInterface> qmlInterface(new FingerQMLInterface());
    auto_ptr<Listener> listener(new SampleListener(qmlInterface.get()));

    leapController.addListener(*listener);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/AirSurprise/main.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.showExpanded();

    return app.exec();
}
