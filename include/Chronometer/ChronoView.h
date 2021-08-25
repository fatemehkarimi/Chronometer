#ifndef CHRONOMETER_CHRONOVIEW_H
#define CHRONOMETER_CHRONOVIEW_H

#include <QtWidgets>

#include <Chronometer/Controller.h>
#include <Chronometer/TabWindow.h>

class ChronoView : public QObject {
    Q_OBJECT
public:
    explicit ChronoView(Controller* c);
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

#endif // CHRONOMETER_CHRONOVIEW_H
