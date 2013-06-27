#include <QMouseEvent>

#include "mousepointer.h"

MousePointer::MousePointer(std::shared_ptr<QMouseEvent> &event) :
    mMouseEvent(event)
{
}

QPointF MousePointer::pointerPosition() const
{
    return mMouseEvent->pos();
}
