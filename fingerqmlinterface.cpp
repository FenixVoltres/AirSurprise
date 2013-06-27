#include "fingerqmlinterface.h"

FingerQMLInterface::FingerQMLInterface(QObject *parent) :
    QObject(parent)
  , mFingerPosition(0.f, 0.f)
  , mHoldPercentage(0.f)
  , mPressed(false)
{
}
