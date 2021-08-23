#include <Chronometer/ChronoController.h>

ChronoController::ChronoController()
{
    this->view = new ChronoView(this);
}

QWidget* ChronoController::getView()
{
    return this->view->getWindow();
}

void ChronoController::start() { }
void ChronoController::stop() { }
void ChronoController::reset() { }
