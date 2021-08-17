#include <QTime>

class Controller
{
    virtual void setTime(QTime t) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reset() = 0;
};