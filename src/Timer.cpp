#include "headers/Timer.h"

Timer::Timer() {
    this->base_timer = new QTimer(this);
    QObject::connect(this->base_timer, &QTimer::timeout, this, &Timer::timeElapsed);
}

void Timer::setInterval(QTime t) {
    int msecs = QTime(0, 0, 0).msecsTo(t);
    this->interval = msecs / 1000;
}

void Timer::timeout() {
    this->base_timer->stop();
}

void Timer::timeElapsed() {
    if(this->interval == 0)
        this->timeout();
    else
        this->interval -= 1;
        
    QTime remaining(0, 0, 0);
    remaining = remaining.addSecs(this->interval);
    emit remainingTime(remaining);
}

void Timer::start() {
    this->base_timer->start(1000);
}

void Timer::stop() {
    this->base_timer->stop();
}

void Timer::registerRemainingTimeObserver(TimerObserver* observer) {
    QObject::connect(this, &Timer::remainingTime, observer, &TimerObserver::timeElapsed);
}