#include "leap/Leap.h"
#include "fingerpointer.h"

FingerPointer::FingerPointer(const Leap::Finger& finger) :
    mFinger(finger)
{
}

QPointF FingerPointer::pointerPosition() const
{
    QPointF pos(mFinger.stabilizedTipPosition().x, mFinger.stabilizedTipPosition().y);

    pos.setX((pos.x() + 120) * (1024. / 240.));
    pos.setY((200.-pos.y()) * (640./200.));

    return pos;
}
