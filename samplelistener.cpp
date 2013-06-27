#include <QDebug>
#include <QKeyEvent>

#include "samplelistener.h"
#include "fingerqmlinterface.h"
#include "holdgesturerecogniser.h"

using namespace Leap;

SampleListener::SampleListener(FingerQMLInterface* interface) :
    Listener(),
    mQMLInterface(interface),
    mKeyboardOverride(false)
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

    if(mKeyboardOverride)
    {
//        mMouseHoldRecogniser.recognise(mLastMouseEvent);
//        sendMouseToQML();
    }
    else if(hasLeftFinger(controller))
    {
        mHoldRecogniser.recognise(leftFinger(controller));
        sendFingerToQML(leftFinger(controller));
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

void SampleListener::sendMouseToQML()
{

}

void SampleListener::sendFingerToQML(const Finger &finger)
{
    QPointF pos(finger.stabilizedTipPosition().x, finger.stabilizedTipPosition().y);

    pos.setX((pos.x() + 120) * (1024. / 240.));
    pos.setY((200.-pos.y()) * (640./200.));

    qDebug() << "Pressed " << mHoldRecogniser.isPressed();
    qDebug() << "Hold percentage " << mHoldRecogniser.holdPercentage();

    mQMLInterface->setPosition(pos);
    mQMLInterface->setHoldPercentage(mHoldRecogniser.holdPercentage());
    mQMLInterface->setPressed(mHoldRecogniser.isPressed());
}

void SampleListener::reactOnMouseMoved(QMouseEvent *event)
{
//    if(!mKeyboardOverride)
//        return;

//    mQMLInterface->setPosition(event->pos());
//    mQMLInterface->setHoldPercentage(0);
//    mQMLInterface->setPressed(false);
}

void SampleListener::reactOnKeyPressed(QKeyEvent *event)
{
    if(event->modifiers() & Qt::KeyboardModifier::ShiftModifier)
    {
        mKeyboardOverride = !mKeyboardOverride;
    }
}

