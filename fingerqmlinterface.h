#ifndef FINGERQMLINTERFACE_H
#define FINGERQMLINTERFACE_H

#include <QObject>
#include <QPointF>

class FingerQMLInterface : public QObject
{
    Q_OBJECT
public:
    explicit FingerQMLInterface(QObject *parent = 0);

    Q_PROPERTY(bool pressed READ pressed WRITE setPressed)
    Q_PROPERTY(float holdPercentage READ holdPercentage WRITE setHoldPercentage)
    Q_PROPERTY(QPointF position READ position WRITE setPosition)

    bool pressed() const { return mPressed; }
    void setPressed(bool press)
    {
        if(mPressed == press)
            return;

        mPressed = press;
    }

    float holdPercentage() const { return mHoldPercentage; }
    void setHoldPercentage(float percent)
    {
        if(mHoldPercentage - percent < 0.001)
            return;

        mHoldPercentage = percent;
    }

    const QPointF& position() const { return mFingerPosition; }
    void setPosition(const QPointF& pos)
    {
        if(mFingerPosition == pos)
            return;

        mFingerPosition = pos;
    }
    
signals:
    
public slots:

private:
    QPointF mFingerPosition;
    float mHoldPercentage;
    bool mPressed;
};

#endif // FINGERQMLINTERFACE_H
