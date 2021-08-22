#ifndef CHRONOVIEW_H
#define CHRONOVIEW_H

#include <QtWidgets>
#include "headers/Controller.h"

class ChronoView
{
public:
    ChronoView(Controller* c);
    QWidget* getWindow();

private:
    QWidget* window;
    Controller* controller;
};

#endif