﻿#include "InputEventDelegate.h"

#include <Qt>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>

#include "samplelistener.h"

InputEventDelegate::InputEventDelegate(SampleListener* listener, QObject* parent)
    : QObject(parent)
    , mListener(listener)
{

}

bool InputEventDelegate::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        qDebug("Ate key press %d", keyEvent->key());
        mListener->reactOnKeyPressed(keyEvent);
    }
    else if(event->type() == QEvent::MouseMove)
    {
        QMouseEvent *keyEvent = static_cast<QMouseEvent*>(event);
        qDebug("Ate mouse move %d", keyEvent->x());
        mListener->reactOnMouseMoved(keyEvent);
    }
    else if(event->type() == QEvent::TouchUpdate)
    {
        QTouchEvent* touchEvent = static_cast<QTouchEvent*>(event);
        qDebug("Ate touch at %d, %d", touchEvent->touchPoints()[0].pos().x(), touchEvent->touchPoints()[0].pos().y());
        mListener->reactOnTouch(touchEvent);
    }
    // standard event processing
    return QObject::eventFilter(obj, event);
}