#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QRegExpValidator>
#include "headers/TimerWindow.h"

TimerWindow::TimerWindow(Controller* controller, Timer* timer) {
    this->timer = timer;
    this->controller = controller;
    this->timer->registerRemainingTimeObserver(this);

    this->timer_window = new QWidget();
    QVBoxLayout* main_layout = new QVBoxLayout(this->timer_window);
    QGridLayout* time_layout = new QGridLayout();
    QHBoxLayout* timeline_layout = new QHBoxLayout();
    QHBoxLayout* control_layout = new QHBoxLayout();

    QLineEdit* hour = this->setupTimeInput("hour");
    QLineEdit* minute = this->setupTimeInput("minute");
    QLineEdit* second = this->setupTimeInput("second");

    QLabel* semi_colon1 = new QLabel(":");
    QLabel* semi_colon2 = new QLabel(":");

    QProgressBar* time_line = this->getProgressBar();

    semi_colon1->setAlignment(Qt::AlignCenter);
    semi_colon2->setAlignment(Qt::AlignCenter);

    QPushButton* start_button = new QPushButton("Start", this->timer_window);
    QPushButton* reset_button = new QPushButton("Reset", this->timer_window);

    start_button->setObjectName("start");

    start_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    reset_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QObject::connect(start_button, &QPushButton::clicked,
                        this, &TimerWindow::handleStartButton);

    QObject::connect(reset_button, &QPushButton::clicked,
                        this, &TimerWindow::handleResetButton);

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

QLineEdit* TimerWindow::setupTimeInput(QString object_name)
{
    QLineEdit* input = new QLineEdit();
    input->setObjectName(object_name);
    input->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    input->setMaxLength(2);
    input->setAlignment(Qt::AlignCenter);
    QRegExp rx("[0-9]*");
    QRegExpValidator* validator = new QRegExpValidator(rx, input);
    input->setValidator(validator);
    input->setText("00");
    return input;
}

QProgressBar* TimerWindow::getProgressBar() {
    QProgressBar* progress_bar = new QProgressBar(this->timer_window);
    return progress_bar;
}

QTime TimerWindow::readInput() {
    QLineEdit* hour = this->timer_window->findChild <QLineEdit*>("hour");
    QLineEdit* minute = this->timer_window->findChild <QLineEdit*>("minute");
    QLineEdit* second = this->timer_window->findChild <QLineEdit*>("second");

    int value_h = hour->text().toInt();
    int value_m = minute->text().toInt();
    int value_s = second->text().toInt();

    return this->makeTimeInputStandard(value_h, value_m, value_s);
}

QTime TimerWindow::makeTimeInputStandard(int h, int m, int s) {
    m += (s / 60);
    s = s % 60;

    h += (m / 60);
    m = m % 60;

    // maximum supported time is 23 hour
    if(h >= 24){
        this->rejectInput();
        return QTime(0, 0, 0);
    }
    return QTime(h, m, s);
}

void TimerWindow::rejectInput() {
    QLineEdit* hour = this->timer_window->findChild <QLineEdit*>("hour");
    hour->setStyleSheet("color: red");
}

void TimerWindow::handleStartButton() {
    if(this->isStartButton)
        handleStartState();
    else
        handleStopState();

    this->isStartButton = !this->isStartButton;
    this->setStartButtonText();
}

void TimerWindow::handleStartState() {
    QTime input = this->readInput();
    if(input == QTime(0, 0, 0)){
        this->rejectInput();
        return;
    }
    this->controller->setTime(input);
    this->controller->start();
}

void TimerWindow::handleStopState() {
    this->controller->stop();
}

void TimerWindow::setStartButtonText() {
    QPushButton* start_btn = this->timer_window->findChild <QPushButton*>("start");
    if(this->isStartButton)
        start_btn->setText("Start");
    else
        start_btn->setText("Stop");
}

void TimerWindow::handleResetButton() {
    this->controller->reset();
}

void TimerWindow::timeElapsed(QTime remaining) {
    this->updateTime(remaining);
}

QString TimerWindow::makeOutputStandard(int o) {
    QString r = QString::number(o);
    if(o < 10)
        r = "0" + r;
    return r;
}

void TimerWindow::updateTime(QTime t) {
    QLineEdit* hour = this->timer_window->findChild <QLineEdit*>("hour");
    QLineEdit* minute = this->timer_window->findChild <QLineEdit*>("minute");
    QLineEdit* second = this->timer_window->findChild <QLineEdit*>("second");

    hour->setText(this->makeOutputStandard(t.hour()));
    minute->setText(this->makeOutputStandard(t.minute()));
    second->setText(this->makeOutputStandard(t.second()));
}