#include <QDebug>

#include "holdgesturerecogniser.h"

#define DEAD_ZONE 100
#define START_MILIS_TREASHOLD 300
#define FINISH_MILLIS_TREASHOLD 1500

using namespace std;

HoldGestureRecogniser::HoldGestureRecogniser() :
    mIsPressed(false),
    mHoldPercentage(0.0)
{
}

bool HoldGestureRecogniser::recognise(const Leap::Finger& finger)
{
    QPointF actPosition(finger.tipPosition().x, finger.tipPosition().y);
    if(pointDistSqr(actPosition, mStartPosition) < DEAD_ZONE)
    {
        TimePoint actTime = chrono::system_clock::now();
        int elapsedMillis = chrono::duration_cast<chrono::milliseconds>(actTime - mStartTime).count();
        mHoldPercentage = 0.0;

        if(isStartTreasholdPassed(elapsedMillis))
            calculateHoldPercentage(elapsedMillis);

        if(isFinishTreasholdPassed(elapsedMillis))
            toggleGesture(finger);

    }
    else
    {
        reset(finger);
    }

    return false;
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

void HoldGestureRecogniser::toggleGesture(const Leap::Finger& finger)
{
    reset(finger);

    mIsPressed = !mIsPressed;
    mHoldPercentage = 0.0;
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
