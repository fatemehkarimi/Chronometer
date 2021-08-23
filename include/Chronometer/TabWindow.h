#ifndef CHRONOMETER_TABWINDOW_H
#define CHRONOMETER_TABWINDOW_H

#include <QtWidgets>

class TabWindow : public QWidget {
    Q_OBJECT

public:
    void showEvent(QShowEvent* event);

signals:
    void windowDisplayed();
};

#endif // CHRONOMETER_TABWINDOW_H
