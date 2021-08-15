#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
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

    QProgressBar* time_line = this->getProgressBar();

    semi_colon1->setAlignment(Qt::AlignCenter);
    semi_colon2->setAlignment(Qt::AlignCenter);

    QPushButton* start_button = new QPushButton("Start", this->timer_window);
    QPushButton* reset_button = new QPushButton("Reset", this->timer_window);
    start_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    reset_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->designTimeLayout(time_layout);

    time_layout->addWidget(hour, 1, 1);
    time_layout->addWidget(minute, 1, 3);
    time_layout->addWidget(second, 1, 5);
    time_layout->addWidget(semi_colon1, 1, 2);
    time_layout->addWidget(semi_colon2, 1, 4);

    timeline_layout->addWidget(time_line);

    control_layout->addWidget(start_button);
    control_layout->addWidget(reset_button);

    main_layout->addLayout(time_layout);
    main_layout->addLayout(timeline_layout);
    main_layout->addLayout(control_layout);

    main_layout->setStretchFactor(time_layout, 4);
    main_layout->setStretchFactor(timeline_layout, 1);
    main_layout->setStretchFactor(control_layout, 1);
    main_layout->addStretch(1);
}

QWidget* TimerWindow::getWindow() {
    return this->timer_window;
}

void TimerWindow::designTimeLayout(QGridLayout* time_layout)
{
    // row stretch
    time_layout->setRowStretch(0, 1);
    time_layout->setRowStretch(1, 3);
    time_layout->setRowStretch(2, 1);

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
    input->setPlaceholderText("00");
    return input;
}

QProgressBar* TimerWindow::getProgressBar() {
    QProgressBar* progress_bar = new QProgressBar(this->timer_window);
    return progress_bar;
}