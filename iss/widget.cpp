#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

QPushButton* Widget::addMainButton() const
{
    return ui->addMainButton;
}

QLineEdit* Widget::mainLineEdit() const
{
    return ui->mainLineEdit;
}

QPushButton* Widget::sortAscButton() const
{
    return ui->sortAscButton;
}

QPushButton* Widget::resetFilterButton() const
{
    return ui->resetFilterButton;
}

QPushButton* Widget::sortDescButton() const
{
    return ui->sortDescButton;
}

ListView* Widget::sortedListView() const
{
    return ui->sortedListView;
}

QLineEdit* Widget::filterLineEdit() const
{
    return ui->filterLineEdit;
}

QPushButton* Widget::removeSortedButton() const
{
    return ui->removeSortedButton;
}

QPushButton* Widget::removeFilteredButton() const
{
    return ui->removeFilteredButton;
}

ListView* Widget::filteredListView() const
{
    return ui->filteredListView;
}

ListView* Widget::mainListView() const
{
    return ui->mainListView;
}

QPushButton* Widget::removeMainListButton() const
{
    return ui->removeMainListButton;
}

