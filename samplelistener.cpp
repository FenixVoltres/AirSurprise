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

SampleListener::SampleListener(FingerQMLInterface* qmlInterface,
                               QObject* parent)
    : QObject(parent)
    , mLeapConnected(false)
    , mKeyboardOverride(false)
    , mQMLInterface(qmlInterface)
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerFired()));
    timer->start(10);
}

void SampleListener::onTimerFired()
{
    if(mLeapConnected)
        return;

    if(!mLastMousePos.isNull())
    {
        std::shared_ptr<PointerAdapter> pointer(new MousePointer(mLastMousePos));
        mHoldRecogniser.recognise(*pointer);
        sendFingerToQML(*pointer);
    }
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
    mLastMousePos.setX(event->x());
    mLastMousePos.setY(event->y());
}

void SampleListener::reactOnKeyPressed(QKeyEvent *event)
{
    if(event->modifiers() & Qt::KeyboardModifier::ShiftModifier)
    {
        mKeyboardOverride = !mKeyboardOverride;
    }
}

void SampleListener::reactOnTouch(QTouchEvent* event)
{
    mLastMousePos = event->touchPoints()[0].pos();
}
