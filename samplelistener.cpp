#include "samplelistener.h"
#include <QDebug>

using namespace Leap;

SampleListener::SampleListener() : Listener()
{
}

void SampleListener::onConnect (const Leap::Controller & controller)
{
    Listener::onConnect(controller);
    qDebug() << "test";
}

void SampleListener::onFrame(const Controller &controller)
{
    Listener::onFrame(controller);

    qDebug() << "Frame";
}
