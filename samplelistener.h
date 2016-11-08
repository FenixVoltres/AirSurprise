﻿#ifndef SAMPLELISTENER_H
#define SAMPLELISTENER_H

#include <QObject>
#include <memory>
#include <QTouchEvent>

//#include "leap/Leap.h"
#include "InputEventDelegate.h"
#include "gestures/holdgesturerecogniser.h"

class QQuickWindow;
class FingerQMLInterface;

class SampleListener : public QObject
{
    Q_OBJECT
public:
    SampleListener(FingerQMLInterface* qmlInterface, QObject* parent = nullptr);

    virtual void reactOnKeyPressed(QKeyEvent *event);
    virtual void reactOnMouseMoved(QMouseEvent *event);
    virtual void reactOnTouch(QTouchEvent* event);

public slots:
    void onTimerFired();

private:
    void sendMouseToQML();
    void sendFingerToQML(const PointerAdapter &pointer);

private:
    bool mLeapConnected;
    bool mKeyboardOverride;
    HoldGestureRecogniser mHoldRecogniser;

    FingerQMLInterface* mQMLInterface;
    QPointF mLastMousePos;
};

#endif // SAMPLELISTENER_H
