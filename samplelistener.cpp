#include <QDebug>

#include "samplelistener.h"
#include "fingerqmlinterface.h"
#include "holdgesturerecogniser.h"

using namespace Leap;

SampleListener::SampleListener(FingerQMLInterface* interface) :
    Listener(),
    mQMLInterface(interface)
{
}

void SampleListener::onConnect (const Leap::Controller & controller)
{
    Listener::onConnect(controller);
    qDebug() << "test";
}

void SampleListener::onFrame(const Controller &controller)
{
    Listener::onFrame(controller);

    qDebug() << "Frame hand " << controller.frame().hands().count();
    qDebug() << "Frame fingers " << controller.frame().fingers().count();

    if(hasLeftFinger(controller))
        sendFingerToQML(controller);

    if(mHoldRecogniser.recognise(leftFinger(controller)))
    {
        mQMLInterface->setPressed(mHoldRecogniser.isPressed());
    }
}

bool SampleListener::hasLeftFinger(const Controller &controller) const
{
    return controller.frame().fingers().count() > 0;
}

Finger SampleListener::leftFinger(const Controller &controller) const
{
    return controller.frame().fingers().leftmost();
}

void SampleListener::sendFingerToQML(const Controller &controller)
{
    Finger finger = leftFinger(controller);
    QPointF pos(finger.tipPosition().x, finger.tipPosition().y);

    mQMLInterface->setPosition(pos);
    qDebug() << pos.rx() << " " << pos.ry();
}
