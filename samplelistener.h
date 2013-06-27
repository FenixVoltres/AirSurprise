#ifndef SAMPLELISTENER_H
#define SAMPLELISTENER_H

#include "leap/Leap.h"
#include "holdgesturerecogniser.h"

class FingerQMLInterface;

class SampleListener : public Leap::Listener
{
public:
    SampleListener(FingerQMLInterface *interface);

protected:
    virtual void onConnect (const Leap::Controller &controller);
    virtual void onFrame (const Leap::Controller & controller);

private:
    bool hasLeftFinger(const Leap::Controller &controller) const;
    Leap::Finger leftFinger(const Leap::Controller &controller) const;
    void sendFingerToQML(const Leap::Finger &finger);

private:
    FingerQMLInterface* mQMLInterface;
    HoldGestureRecogniser mHoldRecogniser;
};

#endif // SAMPLELISTENER_H
