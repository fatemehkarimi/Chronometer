#include "headers/TabWindow.h"

void TabWindow::showEvent(QShowEvent* event) {
    QWidget::showEvent(event);
    emit windowDisplayed();
}