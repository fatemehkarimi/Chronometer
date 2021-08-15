#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QRegExpValidator>
#include "headers/TimerWindow.h"

TimerWindow::TimerWindow() {
    this->timer_window = new QWidget();

    QVBoxLayout* main_layout = new QVBoxLayout(this->timer_window);
    QGridLayout* time_layout = new QGridLayout();
    QHBoxLayout* timeline_layout = new QHBoxLayout();
    QHBoxLayout* control_layout = new QHBoxLayout();

    QLineEdit* hour = this->getTimeInput();
    QLineEdit* minute = this->getTimeInput();
    QLineEdit* second = this->getTimeInput();

    QLabel* semi_colon1 = new QLabel(":");
    QLabel* semi_colon2 = new QLabel(":");

    semi_colon1->setAlignment(Qt::AlignCenter);
    semi_colon2->setAlignment(Qt::AlignCenter);

    this->designTimeLayout(time_layout);

    time_layout->addWidget(hour, 1, 1);
    time_layout->addWidget(minute, 1, 3);
    time_layout->addWidget(second, 1, 5);
    time_layout->addWidget(semi_colon1, 1, 2);
    time_layout->addWidget(semi_colon2, 1, 4);

    main_layout->addLayout(time_layout);
    main_layout->addLayout(timeline_layout);
    main_layout->addLayout(control_layout);
}

QWidget* TimerWindow::getWindow() {
    return this->timer_window;
}

void TimerWindow::designTimeLayout(QGridLayout* time_layout)
{
    // row stretch
    time_layout->setRowStretch(0, 3);
    time_layout->setRowStretch(1, 2);
    time_layout->setRowStretch(2, 3);

    // column stretch
    time_layout->setColumnStretch(0, 3);
    time_layout->setColumnStretch(1, 3);
    time_layout->setColumnStretch(2, 1);
    time_layout->setColumnStretch(3, 3);
    time_layout->setColumnStretch(4, 1);
    time_layout->setColumnStretch(5, 3);
    time_layout->setColumnStretch(6, 3);
}

QLineEdit* TimerWindow::getTimeInput()
{
    QLineEdit* input = new QLineEdit();
    input->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    input->setMaxLength(2);
    input->setAlignment(Qt::AlignCenter);
    QRegExp rx("[0-9]*");
    QRegExpValidator* validator = new QRegExpValidator(rx, input);
    input->setValidator(validator);
    return input;
}