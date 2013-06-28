#ifndef FINGERPOINTER_H
#define FINGERPOINTER_H

#include "leap/Leap.h"
#include "pointeradapter.h"

class QQuickWindow;

class FingerPointer : public PointerAdapter
{
public:
    FingerPointer(const QQuickWindow* window, const Leap::Finger& finger);

    QPointF pointerPosition() const;

private:
    const Leap::Finger mFinger;
    const QQuickWindow *mWindow;
};

#endif // FINGERPOINTER_H
