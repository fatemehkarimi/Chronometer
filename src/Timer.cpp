#include "headers/Timer.h"

Timer::Timer() {
    this->base_timer = new QTimer(this);
    this->main_timer = new QTimer(this);

    QObject::connect(this->main_timer, &QTimer::timeout, this, &Timer::timeout);
    QObject::connect(this->base_timer, &QTimer::timeout, this, &Timer::timeElapsed);
}

void Timer::setInterval(QTime t) {
    int msecs = QTime(0, 0, 0).msecsTo(t);
    this->interval = msecs;
}

void Timer::timeout() {
    this->main_timer->stop();
}

void Timer::timeElapsed() {
    if(!this->main_timer->isActive())
        this->base_timer->stop();
    QTime remaining(0, 0, 0);
    remaining = remaining.addSecs(int(this->main_timer->remainingTime() / 1000));
    emit remainingTime(remaining);
}

void Timer::start() {
    this->main_timer->start(this->interval);
    this->base_timer->start(1000);
}

void Timer::stop() {
    this->main_timer->stop();
    this->base_timer->stop();
}

void Timer::registerRemainingTimeObserver(TimerObserver* observer) {
    QObject::connect(this, &Timer::remainingTime, observer, &TimerObserver::timeElapsed);
}