#include "holdgesturerecogniser.h"

HoldGestureRecogniser::HoldGestureRecogniser() :
    mIsPressed(false)
{
}

bool HoldGestureRecogniser::recognise(const Leap::Finger&)
{
    return false;
}

bool HoldGestureRecogniser::isPressed() const
{
    return false;
}
