#include <QMouseEvent>

#include "mousepointer.h"

MousePointer::MousePointer(QPointF mousePosition) :
    mMousePosition(mousePosition)
{
}

QPointF MousePointer::pointerPosition() const
{
    return mMousePosition;
}
