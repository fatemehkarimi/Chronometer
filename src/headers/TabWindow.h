#ifndef TABWINDOW_H
#define TABWINDOW_H

#include <QtWidgets>

class TabWindow : public QWidget
{
    Q_OBJECT

public:
    void showEvent(QShowEvent* event);

signals:
    void windowDisplayed();
};

#endif