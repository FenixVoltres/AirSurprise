#ifndef KEYPRESSEDDELEGATE_H
#define KEYPRESSEDDELEGATE_H

class QKeyEvent;
class QMouseEvent;

class InputEventDelegate
{
public:
    virtual void reactOnKeyPressed(QKeyEvent *) = 0;
    virtual void reactOnMouseMoved(QMouseEvent *) = 0;
};

#endif // KEYPRESSEDDELEGATE_H
