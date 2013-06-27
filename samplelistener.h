#ifndef SAMPLELISTENER_H
#define SAMPLELISTENER_H

#include <memory>

#include "leap/Leap.h"
#include "inputeventdelegate.h"
#include "gestures/holdgesturerecogniser.h"

class FingerQMLInterface;

class SampleListener : public Leap::Listener, public InputEventDelegate
{
public:
    SampleListener(const std::shared_ptr<FingerQMLInterface>& interface);

    virtual void reactOnKeyPressed(QKeyEvent *event);
    virtual void reactOnMouseMoved(QMouseEvent *event);

protected:
    virtual void onConnect (const Leap::Controller &controller);
    virtual void onFrame (const Leap::Controller & controller);

private:
    void sendMouseToQML();
    void sendFingerToQML(const PointerAdapter &pointer);

    bool hasLeftFinger(const Leap::Controller &controller) const;
    Leap::Finger leftFinger(const Leap::Controller &controller) const;

private:
    bool mKeyboardOverride;
    HoldGestureRecogniser mHoldRecogniser;

    std::shared_ptr<FingerQMLInterface> mQMLInterface;
    std::shared_ptr<QMouseEvent> mLastMouseEvent;
};

#endif // SAMPLELISTENER_H
