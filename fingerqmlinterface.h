#ifndef FINGERQMLINTERFACE_H
#define FINGERQMLINTERFACE_H

#include <QObject>
#include <QPointF>
#include <QDebug>

class FingerQMLInterface : public QObject
{
    Q_OBJECT

public:
    explicit FingerQMLInterface(QObject *parent = 0);

    Q_PROPERTY(float holdPercentage READ holdPercentage WRITE setHoldPercentage NOTIFY holdPercentageChanged)
    Q_PROPERTY(QPointF position     READ position       WRITE setPosition       NOTIFY positionChanged)
    Q_PROPERTY(bool pressed         READ pressed        WRITE setPressed        NOTIFY pressedChanged)

    float holdPercentage() const { return mHoldPercentage; }
    void setHoldPercentage(float percent)
    {
        if (abs(mHoldPercentage - percent) < 0.001)
            return;

        mHoldPercentage = percent;
        emit holdPercentageChanged();
    }

    const QPointF& position() const { return mFingerPosition; }
    void setPosition(const QPointF& pos)
    {
        if (mFingerPosition == pos)
            return;

        mFingerPosition = pos;
        emit positionChanged();
    }

    bool pressed() const { return mPressed; }
    void setPressed(bool press)
    {
        if (mPressed == press)
            return;

        mPressed = press;
        emit pressedChanged();
    }
    
signals:
    void holdPercentageChanged();
    void positionChanged();
    void pressedChanged();

private:
    QPointF mFingerPosition;
    float   mHoldPercentage;
    bool    mPressed;
};

#endif // FINGERQMLINTERFACE_H
