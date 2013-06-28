#include <QQuickWindow>
#include "leap/Leap.h"
#include "fingerpointer.h"

FingerPointer::FingerPointer(const QQuickWindow *window, const Leap::Finger& finger) :
    mFinger(finger)
  , mWindow(window)
{
}

QPointF FingerPointer::pointerPosition() const
{
    QPointF pos(mFinger.stabilizedTipPosition().x, mFinger.stabilizedTipPosition().y);

    pos.setX((pos.x() + 120) * (mWindow->geometry().width() / 240.));
    pos.setY((350.-pos.y()) * (mWindow->geometry().height() / 350.));

    return pos;
}
