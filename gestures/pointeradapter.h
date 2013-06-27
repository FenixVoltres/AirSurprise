#ifndef POINTERADAPTER_H
#define POINTERADAPTER_H

#include <QPointF>

class PointerAdapter
{
public:
    virtual QPointF pointerPosition() const = 0;
};

#endif // POINTERADAPTER_H

