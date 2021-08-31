#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStringList>
#include <QTableWidget>
#include <QVBoxLayout>

#include <Chronometer/ChronoView.h>

ChronoView::ChronoView(Controller* c, Timer* t)
{
    this->window = new TabWindow();
    this->controller = c;
    this->timer = t;

    this->windowConnection = QObject::connect(this->window,
        &TabWindow::windowDisplayed, this, &ChronoView::setFontSizeForWindow);

    QVBoxLayout* main_layout = new QVBoxLayout(this->window);
    QHBoxLayout* control_layout = new QHBoxLayout();

    QLabel* time_label = new QLabel();
    time_label->setObjectName("time_label");
    time_label->setAlignment(Qt::AlignCenter);
    time_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* start_button = new QPushButton("Start", this->window);
    start_button->setObjectName("start_button");

    QPushButton* lap_button = new QPushButton("Lap", this->window);
    QPushButton* reset_button = new QPushButton("Reset", this->window);


    QObject::connect(start_button, &QPushButton::clicked, this, &ChronoView::handleStartButton);
    QObject::connect(lap_button, &QPushButton::clicked, this, &ChronoView::handleLapButton);
    QObject::connect(reset_button, &QPushButton::clicked, this, &ChronoView::handleResetButton);

    start_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lap_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    reset_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QTableWidget* record_table = new QTableWidget(this->window);
    record_table->setObjectName("table");
    record_table->insertColumn(0);
    record_table->insertColumn(0);
    record_table->setHorizontalHeaderLabels(QStringList() << ""
                                                          << "Duration");
    QHeaderView* header = record_table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    control_layout->addWidget(start_button);
    control_layout->addWidget(lap_button);
    control_layout->addWidget(reset_button);
    main_layout->addWidget(time_label);
    main_layout->addLayout(control_layout);
    main_layout->addWidget(record_table);
    main_layout->addStretch(1);

    main_layout->setStretchFactor(time_label, 2);
    main_layout->setStretchFactor(control_layout, 1);
    main_layout->setStretchFactor(record_table, 3);

    setTimeLabel(QTime(0, 0, 0));
}

void ChronoView::setFontSizeForWindow()
{
    QLabel* time_label = this->window->findChild<QLabel*>("time_label");
    int height = time_label->height() * 0.5;

    QFont f;
    f.setPixelSize(height);
    time_label->setFont(f);
    QObject::disconnect(this->windowConnection);
}

QString ChronoView::getTimeString(QTime t) {
    QString time = t.toString("HH:mm:ss.zzz");
    Timer::ACCURACY acc = this->timer->getAccuracy();
    if(acc == Timer::SECOND)
        time.chop(4);
    else if(acc == Timer::MILISEC_100)
        time.chop(1);
    else if(acc == Timer::MILISEC_10)
        time.chop(2);
    return time;
}

void ChronoView::setTimeLabel(QTime t) {
    this->last_updated_time = t;
    QString time = getTimeString(t);
    QLabel* time_label = this->window->findChild <QLabel*>("time_label");
    time_label->setText(time);
}

QWidget* ChronoView::getWindow()
{
    return this->window;
}

void ChronoView::handleStartButton() {
    this->controller->start();
}

void ChronoView::handleLapButton() {
    QTableWidget* table = this->window->findChild <QTableWidget*>("table");
    table->insertRow(table->rowCount());

    QTime lap_duration = QTime(0, 0, 0);
    int msecs = lap_duration.msecsTo(this->last_updated_time) - lap_duration.msecsTo(this->last_recorded_lap);
    lap_duration = lap_duration.addMSecs(msecs);

    this->last_recorded_lap = this->last_updated_time;
    
    QTableWidgetItem* itm = new QTableWidgetItem(getTimeString(lap_duration));
    table->setItem(table->rowCount() - 1, 1, itm);
}

void ChronoView::handleResetButton() {
    this->controller->reset();
}

void ChronoView::setStartButton() {
    QPushButton* btn = this->window->findChild<QPushButton*>("start_button");
    btn->setText("Start");
}

void ChronoView::setStopButton() {
    QPushButton* btn = this->window->findChild<QPushButton*>("start_button");
    btn->setText("Stop");
}

void ChronoView::resetLap() {
    last_updated_time = last_recorded_lap = QTime(0, 0, 0);
}

void ChronoView::clearTable() {
    QTableWidget* table = this->window->findChild <QTableWidget*>("table");
    table->setRowCount(0);
    table->clearContents();
}