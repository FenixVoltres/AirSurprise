#ifndef MOUSEPOINTER_H
#define MOUSEPOINTER_H

#include <memory>

#include "pointeradapter.h"

class QMouseEvent;

class MousePointer : public PointerAdapter
{
public:
    MousePointer(std::shared_ptr<QMouseEvent>& event);

    QPointF pointerPosition() const;

private:
    std::shared_ptr<QMouseEvent> mMouseEvent;
};

#endif // MOUSEPOINTER_H
