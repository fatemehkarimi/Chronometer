#include <Chronometer/ChronoController.h>

ChronoController::ChronoController(Timer* t)
{
    this->timer = t;
    this->view = new ChronoView(this);
    this->timer->registerTimerObserver(this);
}

QWidget* ChronoController::getView()
{
    return this->view->getWindow();
}

void ChronoController::start()
{
}
void ChronoController::stop()
{
}
void ChronoController::reset()
{
}

void ChronoController::timeElapsed(QTime)
{
}

void ChronoController::timerTimeout()
{
}
