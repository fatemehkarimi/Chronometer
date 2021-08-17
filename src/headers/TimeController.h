#include "headers/Timer.h"
#include "headers/Controller.h"

class TimeController : public Controller
{
public:
    TimeController();
    virtual void setTime(QTime t);
    virtual void start();
    virtual void stop();
    virtual void reset();

private:
    Timer* timer;
};