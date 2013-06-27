#include "holdgesturerecogniser.h"

#define DEAD_ZONE 10

HoldGestureRecogniser::HoldGestureRecogniser() :
    mIsPressed(false)
{
}

bool HoldGestureRecogniser::recognise(const Leap::Finger& finger)
{
    QPointF actPosition(finger.tipPosition().x, finger.tipPosition().y);
    if(pointDistSqr(actPosition, mStartPosition) < DEAD_ZONE)
    {

    }
    else
    {
        reset(finger);
    }

    return false;
}

void HoldGestureRecogniser::reset(const Leap::Finger& finger)
{
    mStartTime = std::chrono::system_clock::now();
    mStartPosition = QPointF(finger.tipPosition().x, finger.tipPosition().y);
}

float HoldGestureRecogniser::pointDistSqr(QPointF &p1, QPointF &p2)
{
    float dx = p1.rx() - p2.rx();
    float dy = p1.ry() - p2.ry();

    return dx*dx + dy*dy;
}
