#include <Chronometer/ChronoController.h>

ChronoController::ChronoController(Timer* t)
{
    this->timer = t;
    this->view = new ChronoView(this);
    this->timer->setTimerUnit(Timer::MILISECOND);
    this->timer->registerTimerObserver(this);
    this->second = QTime(0, 0, 0);
    this->second = second.addSecs(1);
}

QWidget* ChronoController::getView()
{
    return this->view->getWindow();
}

void ChronoController::start()
{
    this->timer->setInterval(second);
    this->timer->start();
}
void ChronoController::stop()
{
}
void ChronoController::reset()
{
}

void ChronoController::timeElapsed(QTime t)
{
    int e = t.msecsTo(second);
    QTime elapsed(0, 0, 0);
    elapsed = elapsed.addSecs(secondsElapsed);
    elapsed = elapsed.addMSecs(e);
    this->view->setTimeLabel(elapsed);
}

void ChronoController::timerTimeout()
{
    ++this->secondsElapsed;
    this->timer->setInterval(second);
    this->timer->start();
}
