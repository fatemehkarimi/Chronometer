#include <Chronometer/ChronoController.h>

ChronoController::ChronoController(Timer* t)
{
    this->timer = t;
    this->view = new ChronoView(this);
    this->timer->setTimerAccuracy(Timer::MILISEC_1);
    this->timer->registerTimerObserver(this);
    this->second = QTime(0, 0, 0);
    this->second = second.addSecs(1);

    QObject::connect(this, &ChronoController::startTimer, timer, &Timer::start);

    this->timer_thread = new QThread();
    this->timer_thread->start();
    this->timer->moveToThread(timer_thread);
}

QWidget* ChronoController::getView()
{
    return this->view->getWindow();
}

void ChronoController::start()
{
    QMetaObject::invokeMethod(this->timer, 
                                "setInterval", Q_ARG(QTime, second));

    diff = QDateTime::currentSecsSinceEpoch();
    emit startTimer();
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
    // qDebug() << "diff = " << diff - QDateTime::currentSecsSinceEpoch();
    if((QDateTime::currentSecsSinceEpoch() - diff) != 1) {
        qDebug() << "Error";
    }
    diff = QDateTime::currentMSecsSinceEpoch();

    ++this->secondsElapsed;
    this->start();
}
