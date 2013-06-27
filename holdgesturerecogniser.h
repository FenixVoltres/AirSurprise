#ifndef HOLDGESTURERECOGNISER_H
#define HOLDGESTURERECOGNISER_H

#include "leap/Leap.h"

class HoldGestureRecogniser
{
public:
    HoldGestureRecogniser();

    bool recognise(const Leap::Finger&);
    bool isPressed() const;

private:
    bool mIsPressed;
};

#endif // HOLDGESTURERECOGNISER_H
