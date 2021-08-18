#include "headers/TimeController.h"


TimeController::TimeController(Timer* t) {
    this->timer = t;
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