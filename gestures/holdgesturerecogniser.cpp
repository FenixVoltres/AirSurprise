#include <QDebug>

#include "gestures/holdgesturerecogniser.h"

#define START_MILIS_TREASHOLD 300
#define FINISH_MILLIS_TREASHOLD 1200

using namespace std;

const int HoldGestureRecogniser::sDeadZone = 200;

HoldGestureRecogniser::HoldGestureRecogniser() :
    mIsPressed(false),
    mHoldPercentage(0.0)
{
}

bool HoldGestureRecogniser::recognise(const PointerAdapter &pointer)
{
    QPointF actPosition = pointer.pointerPosition();
    if(pointDistSqr(actPosition, mStartPosition) < sDeadZone)
    {
        TimePoint actTime = chrono::system_clock::now();
        int elapsedMillis = chrono::duration_cast<chrono::milliseconds>(actTime - mStartTime).count();
        mHoldPercentage = 0.0;

        if(isStartTreasholdPassed(elapsedMillis))
            calculateHoldPercentage(elapsedMillis);

        if(isFinishTreasholdPassed(elapsedMillis))
            toggleGesture(pointer);

    }
    else
    {
        reset(pointer);
    }

    return false;
}

void HoldGestureRecogniser::reset(const PointerAdapter& pointer)
{
    mStartTime = std::chrono::system_clock::now();
    mStartPosition = pointer.pointerPosition();
}

bool HoldGestureRecogniser::isStartTreasholdPassed(int milliseconds) const
{
    return milliseconds > START_MILIS_TREASHOLD;
}

bool HoldGestureRecogniser::isFinishTreasholdPassed(int milliseconds) const
{
    return milliseconds > FINISH_MILLIS_TREASHOLD;
}

void HoldGestureRecogniser::calculateHoldPercentage(int milliseconds)
{
    mHoldPercentage = (float)((milliseconds - START_MILIS_TREASHOLD)) /
            (float)((FINISH_MILLIS_TREASHOLD - START_MILIS_TREASHOLD));
}

void HoldGestureRecogniser::toggleGesture(const PointerAdapter& pointer)
{
    reset(pointer);

    mIsPressed = !mIsPressed;
    mHoldPercentage = 0.0;
}

float HoldGestureRecogniser::pointDistSqr(QPointF &p1, QPointF &p2)
{
    float dx = p1.rx() - p2.rx();
    float dy = p1.ry() - p2.ry();

    return dx*dx + dy*dy;
}
