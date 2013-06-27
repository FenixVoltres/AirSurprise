#ifndef SAMPLELISTENER_H
#define SAMPLELISTENER_H

#include <QObject>
#include <memory>

#include "leap/Leap.h"
#include "inputeventdelegate.h"
#include "gestures/holdgesturerecogniser.h"

class QQuickWindow;
class FingerQMLInterface;

class SampleListener : public QObject, public Leap::Listener, public InputEventDelegate
{
    Q_OBJECT
public:
    SampleListener(QQuickWindow* quickWindow, const std::shared_ptr<FingerQMLInterface>& qmlInterface);

    virtual void reactOnKeyPressed(QKeyEvent *event);
    virtual void reactOnMouseMoved(QMouseEvent *event);

public slots:
    void onTimerFired();

protected:
    virtual void onConnect (const Leap::Controller &controller);
    virtual void onFrame (const Leap::Controller & controller);

private:
    void sendMouseToQML();
    void sendFingerToQML(const PointerAdapter &pointer);

    bool hasLeftFinger(const Leap::Controller &controller) const;
    Leap::Finger leftFinger(const Leap::Controller &controller) const;

private:
    bool mLeapConnected;
    bool mKeyboardOverride;
    HoldGestureRecogniser mHoldRecogniser;

    std::shared_ptr<FingerQMLInterface> mQMLInterface;
    std::shared_ptr<QMouseEvent> mLastMouseEvent;
};

#endif // SAMPLELISTENER_H
