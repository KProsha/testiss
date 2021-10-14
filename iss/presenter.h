#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>

#include "widget.h"
#include "mainmodel.h"

#include <QSortFilterProxyModel>

class Presenter: public QObject
{
    Q_OBJECT
public:
    Presenter(Widget* widget, MainModel* mainModel, QObject *parent = nullptr);

private slots:
    void onAddMainButtonClicked();
    void onRemoveMainListButtonClicked();

    void onSortAscButtonClicked();
    void onSortDescButtonClicked();
    void onRemoveSortedButtonClicked();

    void onFilterTextChange(const QString& text);
    void onResetFilterButton();
    void onRemoveFilterButton();

    void onMainListViewCurrentIndex(const QModelIndex &index);
    void onSortedListViewCurrentIndex(const QModelIndex &index);
    void onFilteredListViewCurrentIndex(const QModelIndex &index);

private:
    Widget* _widget;
    MainModel* _mainModel;

    int activeList;

    QSortFilterProxyModel* _sortModel;
    QSortFilterProxyModel* _filterModel;
};

#endif // PRESENTER_H
