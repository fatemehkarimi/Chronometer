#ifndef CHRONOMETER_CONTROLLER_H
#define CHRONOMETER_CONTROLLER_H

#include <QtWidgets>

class Controller {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reset() = 0;
    virtual QWidget* getView() = 0;
};

#endif // CHRONOMETER_CONTROLLER_H
