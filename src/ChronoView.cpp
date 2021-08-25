#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStringList>
#include <QTableWidget>
#include <QVBoxLayout>

#include <Chronometer/ChronoView.h>

ChronoView::ChronoView(Controller* c)
{
    this->window = new TabWindow();
    this->controller = c;

    this->windowConnection = QObject::connect(this->window,
        &TabWindow::windowDisplayed, this, &ChronoView::setFontSizeForWindow);

    QVBoxLayout* main_layout = new QVBoxLayout(this->window);
    QHBoxLayout* control_layout = new QHBoxLayout();

    QLabel* time_label = new QLabel();
    time_label->setText("00:00:00.000");
    time_label->setObjectName("time_label");
    time_label->setAlignment(Qt::AlignCenter);
    time_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* start_button = new QPushButton("Start", this->window);
    QPushButton* lap_button = new QPushButton("Lap", this->window);
    QPushButton* reset_button = new QPushButton("Reset", this->window);

    QObject::connect(start_button, &QPushButton::clicked, this, &ChronoView::handleStartButton);
    QObject::connect(lap_button, &QPushButton::clicked, this, &ChronoView::handleLapButton);
    QObject::connect(reset_button, &QPushButton::clicked, this, &ChronoView::handleResetButton);

    start_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lap_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    reset_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QTableWidget* record_table = new QTableWidget(this->window);
    record_table->insertColumn(0);
    record_table->insertColumn(0);
    record_table->setHorizontalHeaderLabels(QStringList() << ""
                                                          << "");
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

void ChronoView::setTimeLabel(QTime t) {
    QLabel* time_label = this->window->findChild <QLabel*>("time_label");
    // qDebug() << t.hour() << " " << t.minute() << " " << t.second() << " " << t.msec();
    QString time = t.toString("HH:mm:ss.zzz");
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
    // this should be handled in view
}

void ChronoView::handleResetButton() {
    this->controller->reset();
}
