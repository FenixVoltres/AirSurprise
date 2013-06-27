#ifndef FINGERQMLINTERFACE_H
#define FINGERQMLINTERFACE_H

#include <QObject>
#include <QPointF>

class FingerQMLInterface : public QObject
{
    Q_OBJECT
public:
    explicit FingerQMLInterface(QObject *parent = 0);

    Q_PROPERTY(QPointF position READ position WRITE setPosition)

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
    
};

#endif // FINGERQMLINTERFACE_H
