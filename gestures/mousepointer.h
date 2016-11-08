#ifndef MOUSEPOINTER_H
#define MOUSEPOINTER_H

#include <memory>

#include "pointeradapter.h"

class QMouseEvent;

class MousePointer : public PointerAdapter
{
public:
    MousePointer(QPointF mousePosition);

    QPointF pointerPosition() const;

private:
    QPointF mMousePosition;
};

#endif // MOUSEPOINTER_H
