#ifndef HOLDGESTURERECOGNISER_H
#define HOLDGESTURERECOGNISER_H

#include <QPointF>
#include <chrono>

#include "leap/Leap.h"

typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

class HoldGestureRecogniser
{
public:
    HoldGestureRecogniser();

    bool recognise(const Leap::Finger&finger);
    void reset(const Leap::Finger &finger);

    bool isPressed() const { return mIsPressed; }
    float holdPercentage() const { return mHoldPercentage; }

private:
    float pointDistSqr(QPointF &p1, QPointF &p2);

private:
    bool mIsPressed;
    float mHoldPercentage;

    QPointF mStartPosition;
    TimePoint mStartTime;
};

#endif // HOLDGESTURERECOGNISER_H
