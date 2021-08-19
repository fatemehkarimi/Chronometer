#include "headers/TimeController.h"

TimeController::TimeController(Timer* t) {
    this->timer = t;
    this->timer_window = new TimerWindow(this, t);
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

QWidget* TimeController::getView() {
    return this->timer_window->getWindow();
}