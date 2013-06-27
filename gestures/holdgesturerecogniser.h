#ifndef HOLDGESTURERECOGNISER_H
#define HOLDGESTURERECOGNISER_H

#include <QPointF>
#include <chrono>

#include "leap/Leap.h"
#include "pointeradapter.h"

typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

class HoldGestureRecogniser
{
public:
    HoldGestureRecogniser();

    bool recognise(const PointerAdapter& pointer);
    void reset(const PointerAdapter& pointer);

    bool isPressed() const { return mIsPressed; }
    float holdPercentage() const { return mHoldPercentage; }

protected:
    bool isStartTreasholdPassed(int milliseconds) const;
    bool isFinishTreasholdPassed(int milliseconds) const;

    void calculateHoldPercentage(int milliseconds);
    void toggleGesture(const PointerAdapter &pointer);

    float pointDistSqr(QPointF &p1, QPointF &p2);

protected:
    bool mIsPressed;
    float mHoldPercentage;

    QPointF mStartPosition;
    TimePoint mStartTime;

    const static int sDeadZone;
};

#endif // HOLDGESTURERECOGNISER_H
