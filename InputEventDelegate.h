#ifndef KEYPRESSEDDELEGATE_H
#define KEYPRESSEDDELEGATE_H

#include <QObject>

class QKeyEvent;
class QMouseEvent;
class SampleListener;

class InputEventDelegate: public QObject
{
    Q_OBJECT

public:
    InputEventDelegate(SampleListener* listener, QObject* parent = nullptr);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

    SampleListener* mListener;
};

#endif // KEYPRESSEDDELEGATE_H
