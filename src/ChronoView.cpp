#include <QLabel>
#include <QStringList>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include "headers/ChronoView.h"

ChronoView::ChronoView(Controller* c) {
    this->window = new QWidget();
    this->controller = c;

    QVBoxLayout* main_layout = new QVBoxLayout(this->window);
    QHBoxLayout* control_layout = new QHBoxLayout();

    QLabel* time_display = new QLabel();
    time_display->setAlignment(Qt::AlignCenter);
    time_display->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* start_button = new QPushButton("Start", this->window);
    QPushButton* lap_button = new QPushButton("Lap", this->window);
    QPushButton* reset_button = new QPushButton("Reset", this->window);

    start_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lap_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    reset_button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QTableWidget* record_table = new QTableWidget(this->window);
    record_table->insertColumn(0);
    record_table->insertColumn(0);
    record_table->setHorizontalHeaderLabels(QStringList() << "" << "");
    QHeaderView* header = record_table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    control_layout->addWidget(start_button);
    control_layout->addWidget(lap_button);
    control_layout->addWidget(reset_button);
    main_layout->addWidget(time_display);
    main_layout->addLayout(control_layout);
    main_layout->addWidget(record_table);
    main_layout->addStretch(1);

    main_layout->setStretchFactor(time_display, 2);
    main_layout->setStretchFactor(control_layout, 1);
    main_layout->setStretchFactor(record_table, 3);
}

QWidget* ChronoView::getWindow() {
    return this->window;
}