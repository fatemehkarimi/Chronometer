#ifndef CHRONOMETER_CHRONOCONTROLLER_H
#define CHRONOMETER_CHRONOCONTROLLER_H

#include <Chronometer/ChronoView.h>
#include <Chronometer/Controller.h>

class ChronoController : public Controller {
public:
    ChronoController();
    virtual void start();
    virtual void stop();
    virtual void reset();
    virtual QWidget* getView();

private:
    ChronoView* view;
};

#endif // CHRONOMETER_CHRONOCONTROLLER_H
