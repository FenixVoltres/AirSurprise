#ifndef SAMPLELISTENER_H
#define SAMPLELISTENER_H

#include "leap/Leap.h"

class SampleListener : public Leap::Listener
{
public:
    SampleListener();

    virtual void onConnect (const Leap::Controller &controller);
    virtual void onFrame (const Leap::Controller & controller);
};

#endif // SAMPLELISTENER_H
