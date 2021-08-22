#ifndef CHRONOVIEW_H
#define CHRONOVIEW_H

#include <QtWidgets>

class ChronoView
{
public:
    ChronoView();
    QWidget* getWindow();

private:
    QWidget* window;
};

#endif