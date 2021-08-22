#include "headers/ChronoView.h"

ChronoView::ChronoView() {
    this->window = new QWidget();
}

QWidget* ChronoView::getWindow() {
    return this->window;
}