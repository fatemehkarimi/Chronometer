#include "headers/ChronoView.h"

ChronoView::ChronoView(Controller* c) {
    this->window = new QWidget();
    this->controller = c;
}

QWidget* ChronoView::getWindow() {
    return this->window;
}