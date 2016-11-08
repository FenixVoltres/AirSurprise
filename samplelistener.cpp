#include <memory>
#include <QDebug>
#include <QKeyEvent>
#include <QQuickWindow>
#include <QTimer>

#include "samplelistener.h"
#include "fingerqmlinterface.h"
#include "gestures/mousepointer.h"
//#include "gestures/fingerpointer.h"

//using namespace Leap;

SampleListener::SampleListener(QQuickWindow* quickWindow,
                               const std::shared_ptr<FingerQMLInterface>& qmlInterface) :
    QObject(quickWindow)
    , mLeapConnected(false)
    , mKeyboardOverride(false)
    , mQMLInterface(qmlInterface)
    , mQuickWindow(quickWindow)
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerFired()));
    timer->start(10);
}

//void SampleListener::onConnect (const Leap::Controller & controller)
//{
//    Listener::onConnect(controller);
//    mLeapConnected = true;
//}

//void SampleListener::onFrame(const Controller &controller)
//{
//    Listener::onFrame(controller);

//    std::shared_ptr<PointerAdapter> pointer;
//    if(mKeyboardOverride && mLastMouseEvent.get())
//        pointer.reset(new MousePointer(mLastMouseEvent));
//    else if(hasLeftFinger(controller))
//        pointer.reset(new FingerPointer(mQuickWindow));//, leftFinger(controller)));

//    if(pointer.get())
//    {
//        mHoldRecogniser.recognise(*pointer);
//        sendFingerToQML(*pointer);
//    }
//}

void SampleListener::onTimerFired()
{
    if(mLeapConnected)
        return;

    if(mLastMouseEvent)
    {
        std::shared_ptr<PointerAdapter> pointer(new MousePointer(mLastMouseEvent));
        mHoldRecogniser.recognise(*pointer);
        sendFingerToQML(*pointer);
    }
}

//bool SampleListener::hasLeftFinger(const Controller &controller) const
//{
//    return controller.frame().fingers().count() > 0;
//}

//Finger SampleListener::leftFinger(const Controller &controller) const
//{
//    return controller.frame().fingers().leftmost();
//}

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
