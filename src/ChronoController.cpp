#include <Chronometer/ChronoController.h>

ChronoController::ChronoController(Timer* t)
{
    this->timer = t;
    this->timer->setTimerAccuracy(Timer::MILISEC_10);
    this->timer->registerTimerObserver(this);
    this->maximum_time = QTime(23, 59, 59);

    QObject::connect(this, &ChronoController::startTimer, timer, &Timer::start);
    QObject::connect(this, &ChronoController::stopTimer, timer, &Timer::stop);

    this->timer_thread = new QThread();
    this->timer_thread->start();
    this->timer->moveToThread(timer_thread);

    this->view = new ChronoView(this, t);
}

QWidget* ChronoController::getView()
{
    return this->view->getWindow();
}

void ChronoController::start()
{
    if(!isTimerPending) {
        QMetaObject::invokeMethod(this->timer, "setInterval", Q_ARG(QTime, maximum_time));
        this->view->setStopButton();
        isTimerPending = true;
        isStartCommand = false;
        emit startTimer();
    }
    else {
        if(isStartCommand) {
            this->view->setStopButton();
            emit startTimer();
        }
        else {
            this->view->setStartButton(); 
            emit stopTimer();
        }
        isStartCommand = !isStartCommand;
    }
}
void ChronoController::stop()
{
}
void ChronoController::reset()
{
}

void ChronoController::timeElapsed(QTime t)
{
    int e = t.msecsTo(maximum_time);
    QTime elapsed(0, 0, 0);
    elapsed = elapsed.addMSecs(e);
    this->view->setTimeLabel(elapsed);
}

void ChronoController::timerTimeout()
{
    this->start();
}
