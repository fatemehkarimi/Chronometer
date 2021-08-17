#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QTime>

class Controller
{
public:
    virtual void setTime(QTime t) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reset() = 0;
};

#endif