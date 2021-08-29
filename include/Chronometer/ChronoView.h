#ifndef CHRONOMETER_CHRONOVIEW_H
#define CHRONOMETER_CHRONOVIEW_H

#include <QtWidgets>
#include <Chronometer/Timer.h>
#include <Chronometer/Controller.h>
#include <Chronometer/TabWindow.h>

class ChronoView : public QObject {
    Q_OBJECT
public:
    explicit ChronoView(Controller* c, Timer* t);
    void setTimeLabel(QTime t);
    QWidget* getWindow();

public slots:
    void handleStartButton();
    void handleLapButton();
    void handleResetButton();
    void setFontSizeForWindow();

private:
    Timer* timer;
    TabWindow* window;
    Controller* controller;
    QMetaObject::Connection windowConnection;
};

#endif // CHRONOMETER_CHRONOVIEW_H
