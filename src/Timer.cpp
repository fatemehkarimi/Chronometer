#include <Chronometer/Timer.h>

Timer::Timer()
{
    this->base_timer = new QTimer(this);
    this->base_timer->setTimerType(Qt::PreciseTimer);
    QObject::connect(this->base_timer, &QTimer::timeout, this, &Timer::timeElapsed);
}

void Timer::setInterval(QTime t)
{
    int msecs = QTime(0, 0, 0).msecsTo(t);
    this->interval = msecs / this->acc;
}

void Timer::setTimerAccuracy(ACCURACY a) {
    this->acc = a;
}

Timer::ACCURACY Timer::getAccuracy() {
    return this->acc;
}

void Timer::timeElapsed()
{
    this->interval -= 1;
    if (this->interval == 0) {
        this->base_timer->stop();
        emit timeout();
        return;
    }

    if (this->base_timer->interval() != acc) {
        this->base_timer->setInterval(acc);
        this->base_timer->start();
    }

    QTime remaining(0, 0, 0);
    remaining = remaining.addMSecs(this->interval * this->acc);
    emit remainingTime(remaining);
}

void Timer::start()
{
    if (this->remaining_time > 0) {
        this->base_timer->setInterval(remaining_time);
        this->base_timer->start();
        this->remaining_time = 0;
    } else {
        this->base_timer->setInterval(acc);
        this->base_timer->start();
    }

    QTime remaining(0, 0, 0);
    remaining = remaining.addMSecs(this->interval * this->acc);
    emit remainingTime(remaining);
}

void Timer::stop()
{
    this->remaining_time = this->base_timer->remainingTime();
    this->base_timer->stop();
}

void Timer::clear()
{
    this->remaining_time = 0;
    this->interval = 0;
}

void Timer::registerTimerObserver(TimerObserver* observer)
{
    QObject::connect(this, &Timer::remainingTime, observer, &TimerObserver::timeElapsed);
    QObject::connect(this, &Timer::timeout, observer, &TimerObserver::timerTimeout);
}
