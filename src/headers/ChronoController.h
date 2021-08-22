#ifndef CHRONOCONTROLLER_H
#define CHRONOCONTROLLER_H

#include "headers/Controller.h"
#include "headers/ChronoView.h"

class ChronoController : public Controller
{
public:
    ChronoController();
    virtual void start();
    virtual void stop();
    virtual void reset();
    virtual QWidget* getView();

private:
    ChronoView* view;
};

#endif