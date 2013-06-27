#ifndef SAMPLELISTENER_H
#define SAMPLELISTENER_H

#include "leap/Leap.h"
#include "inputeventdelegate.h"
#include "holdgesturerecogniser.h"

class FingerQMLInterface;

class SampleListener : public Leap::Listener, public InputEventDelegate
{
public:
    SampleListener(FingerQMLInterface *interface);

    virtual void reactOnKeyPressed(QKeyEvent *event);
    virtual void reactOnMouseMoved(QMouseEvent *event);

protected:
    virtual void onConnect (const Leap::Controller &controller);
    virtual void onFrame (const Leap::Controller & controller);

private:
    void sendMouseToQML();
    void sendFingerToQML(const Leap::Finger &finger);

    bool hasLeftFinger(const Leap::Controller &controller) const;
    Leap::Finger leftFinger(const Leap::Controller &controller) const;

private:
    FingerQMLInterface* mQMLInterface;
    HoldGestureRecogniser mHoldRecogniser;

    bool mKeyboardOverride;
};

#endif // SAMPLELISTENER_H
