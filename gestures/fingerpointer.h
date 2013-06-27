#ifndef FINGERPOINTER_H
#define FINGERPOINTER_H

#include "leap/Leap.h"
#include "pointeradapter.h"

class FingerPointer : public PointerAdapter
{
public:
    FingerPointer(const Leap::Finger& finger);

    QPointF pointerPosition() const;

private:
    const Leap::Finger mFinger;
};

#endif // FINGERPOINTER_H
