#ifndef SAMPLELISTENER_H
#define SAMPLELISTENER_H

#include "leap/Leap.h"

class FingerQMLInterface;

class SampleListener : public Leap::Listener
{
public:
    SampleListener(FingerQMLInterface *interface);

protected:
    virtual void onConnect (const Leap::Controller &controller);
    virtual void onFrame (const Leap::Controller & controller);

private:
    bool hasLeftFinger(const Leap::Controller &controller);
    Leap::Finger leftFinger(const Leap::Controller &controller);

private:
    FingerQMLInterface* mQMLInterface;
};

#endif // SAMPLELISTENER_H
