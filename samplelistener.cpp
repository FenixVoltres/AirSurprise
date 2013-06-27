#include <memory>
#include <QDebug>
#include <QKeyEvent>

#include "samplelistener.h"
#include "fingerqmlinterface.h"
#include "gestures/mousepointer.h"
#include "gestures/fingerpointer.h"

using namespace Leap;

SampleListener::SampleListener(const std::shared_ptr<FingerQMLInterface>& interface) :
    Listener(),
    mQMLInterface(interface),
    mKeyboardOverride(false)
{
}

void SampleListener::onConnect (const Leap::Controller & controller)
{
    Listener::onConnect(controller);
    qDebug() << "onConnect";
}

void SampleListener::onFrame(const Controller &controller)
{
    Listener::onFrame(controller);

    std::shared_ptr<PointerAdapter> pointer;
    if(mKeyboardOverride && mLastMouseEvent.get())
        pointer.reset(new MousePointer(mLastMouseEvent));
    else if(hasLeftFinger(controller))
        pointer.reset(new FingerPointer(leftFinger(controller)));

    if(pointer.get())
    {
        mHoldRecogniser.recognise(*pointer);
        sendFingerToQML(*pointer);
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

void SampleListener::sendFingerToQML(const PointerAdapter &pointer)
{
//    qDebug() << "Pressed " << mHoldRecogniser.isPressed();
//    qDebug() << "Hold percentage " << mHoldRecogniser.holdPercentage();

    mQMLInterface->setPosition(pointer.pointerPosition());
    mQMLInterface->setHoldPercentage(mHoldRecogniser.holdPercentage());
    mQMLInterface->setPressed(mHoldRecogniser.isPressed());
}

void SampleListener::reactOnMouseMoved(QMouseEvent *event)
{
    mLastMouseEvent.reset(new QMouseEvent(*event));
}

void SampleListener::reactOnKeyPressed(QKeyEvent *event)
{
    if(event->modifiers() & Qt::KeyboardModifier::ShiftModifier)
    {
        mKeyboardOverride = !mKeyboardOverride;
    }
}

