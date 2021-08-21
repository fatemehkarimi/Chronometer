#include "headers/TimeController.h"

TimeController::TimeController(Timer* t) {
    this->timer = t;
    this->timer_window = new TimerWindow(this, t);
    this->timer->registerTimerObserver(this);
}

void TimeController::setTime(QTime t) {
    this->timer->setInterval(t);
    this->currentInterval = t;
}

void TimeController::start() {
    QTime t = this->timer_window->readInput();
    QTime zero_t = QTime(0, 0, 0);
    if(t == zero_t)
        return;

    if(!this->isTimerPendig) {
        this->setTime(t);
        this->timer->start();
        this->isTimerPendig = true;
        this->isStartCommand = false;
        timer_window->setStopButton();
        timer_window->resetProgressBar();
        timer_window->setProgressBarMaximum(zero_t.msecsTo(t) / 1000);
    }
    else {
        if(this->isStartCommand){
            this->timer->start();
            timer_window->setStopButton();
        }
        else {
            this->timer->stop();
            timer_window->setStartButton();
        }
        this->isStartCommand = !this->isStartCommand;
    }
}

void TimeController::stop() {
    this->timer->stop();
}

void TimeController::reset() {
    this->timer->stop();
    this->timer->clear();
    this->timer->setInterval(this->currentInterval);
    this->timer_window->updateTime(this->currentInterval);
    this->isTimerPendig = false;
    this->isStartCommand = true;
    timer_window->setStartButton();
    timer_window->resetProgressBar();
}

QWidget* TimeController::getView() {
    return this->timer_window->getWindow();
}

void TimeController::timerTimeout() {
    this->isTimerPendig = false;
    timer_window->setStartButton();
}