#ifndef CHRONOVIEW_H
#define CHRONOVIEW_H

#include <QtWidgets>
#include "headers/Controller.h"
#include "headers/TabWindow.h"

class ChronoView : public QObject
{
    Q_OBJECT
public:
    ChronoView(Controller* c);
    QWidget* getWindow();

public slots:
    void handleStartButton();
    void handleLapButton();
    void handleResetButton();
    void setFontSizeForWindow();

private:
    TabWindow* window;
    Controller* controller;
    QMetaObject::Connection windowConnection;
};

#endif