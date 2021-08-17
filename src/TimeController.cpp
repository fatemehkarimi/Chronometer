#include "headers/TimeController.h"


TimeController::TimeController() {
    this->timer = new Timer();
}

void TimeController::setTime(QTime t) {
    this->timer->setInterval(t);
}

void TimeController::start() {
    this->timer->start();
}

void TimeController::stop() {
    this->timer->stop();
}

void TimeController::reset() {}