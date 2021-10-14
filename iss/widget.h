#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

#include "listview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QPushButton *addMainButton() const;
    QLineEdit *mainLineEdit() const;
    QPushButton *sortAscButton() const;
    QPushButton *resetFilterButton() const;
    QPushButton *sortDescButton() const;
    ListView *sortedListView() const;
    QLineEdit *filterLineEdit() const;
    QPushButton *removeSortedButton() const;
    QPushButton *removeFilteredButton() const;
    ListView *filteredListView() const;
    ListView* mainListView() const;
    QPushButton *removeMainListButton()const;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
