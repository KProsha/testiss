#include "presenter.h"

#include "listview.h"

Presenter::Presenter(Widget* widget, MainModel* mainModel, QObject* parent): QObject(parent),
    _widget(widget),
    _mainModel(mainModel)
{
    activeList = -1;

    _sortModel = new QSortFilterProxyModel(this);
    _filterModel = new QSortFilterProxyModel(this);

    _sortModel->setSourceModel(_mainModel);
    _filterModel->setSourceModel(_sortModel);

    _widget->mainListView()->setModel(_mainModel);
    _widget->sortedListView()->setModel(_sortModel);
    _widget->filteredListView()->setModel(_filterModel);

    connect(_widget->addMainButton(), &QPushButton::clicked, this, &Presenter::onAddMainButtonClicked);
    connect(_widget->removeMainListButton(), &QPushButton::clicked, this, &Presenter::onRemoveMainListButtonClicked);

    connect(_widget->sortAscButton(), &QPushButton::clicked, this, &Presenter::onSortAscButtonClicked);
    connect(_widget->sortDescButton(), &QPushButton::clicked, this, &Presenter::onSortDescButtonClicked);
    connect(_widget->removeSortedButton(), &QPushButton::clicked, this, &Presenter::onRemoveSortedButtonClicked);

    connect(_widget->filterLineEdit(), &QLineEdit::textChanged, this, &Presenter::onFilterTextChange);
    connect(_widget->resetFilterButton(), &QPushButton::clicked, this, &Presenter::onResetFilterButton);
    connect(_widget->removeFilteredButton(), &QPushButton::clicked, this, &Presenter::onRemoveFilterButton);

    connect(_widget->mainListView(), &ListView::sigCurrentIndex, this, &Presenter::onMainListViewCurrentIndex);
    connect(_widget->sortedListView(), &ListView::sigCurrentIndex, this, &Presenter::onSortedListViewCurrentIndex);
    connect(_widget->filteredListView(), &ListView::sigCurrentIndex, this, &Presenter::onFilteredListViewCurrentIndex);
}

void Presenter::onAddMainButtonClicked()
{
    _mainModel->addData(_widget->mainLineEdit()->text());
    _widget->mainLineEdit()->clear();
}

void Presenter::onRemoveMainListButtonClicked()
{
    _mainModel->removeData(_widget->mainListView()->currentIndex().row());
}

void Presenter::onSortAscButtonClicked()
{
    _sortModel->sort(0,Qt::AscendingOrder);
}

void Presenter::onSortDescButtonClicked()
{
    _sortModel->sort(0,Qt::DescendingOrder);
}

void Presenter::onRemoveSortedButtonClicked()
{
    auto sortedListViewIndex = _widget->sortedListView()->currentIndex();

    int index = _sortModel->mapToSource(sortedListViewIndex).row();

    _mainModel->removeData(index);
}

void Presenter::onFilterTextChange(const QString& text)
{
    _filterModel->setFilterRegularExpression(text);
}

void Presenter::onResetFilterButton()
{
    _widget->filterLineEdit()->clear();
}

void Presenter::onRemoveFilterButton()
{
    auto filteredListViewIndex = _widget->filteredListView()->currentIndex();
    auto sortedListViewIndex = _filterModel->mapToSource(filteredListViewIndex);

    int index = _sortModel->mapToSource(sortedListViewIndex).row();

    _mainModel->removeData(index);
}

void Presenter::onMainListViewCurrentIndex(const QModelIndex& index)
{
    if(activeList != -1) return;
    activeList = 0;

    auto sortedListViewIndex = _sortModel->mapFromSource(index);
    auto filteredListViewIndex = _filterModel->mapFromSource(sortedListViewIndex);

    _widget->sortedListView()->setCurrentIndex(sortedListViewIndex);
    _widget->filteredListView()->setCurrentIndex(filteredListViewIndex);

    activeList = -1;
}

void Presenter::onSortedListViewCurrentIndex(const QModelIndex& index)
{
    if(activeList != -1) return;
    activeList = 1;

    auto mainListViewIndex = _sortModel->mapToSource(index);
    auto filteredListViewIndex = _filterModel->mapFromSource(index);

    _widget->mainListView()->setCurrentIndex(mainListViewIndex);
    _widget->filteredListView()->setCurrentIndex(filteredListViewIndex);

    activeList = -1;
}

void Presenter::onFilteredListViewCurrentIndex(const QModelIndex& index)
{
    if(activeList != -1) return;
    activeList = 2;

    auto sortedListViewIndex = _filterModel->mapToSource(index);
    auto mainListViewIndex = _sortModel->mapToSource(sortedListViewIndex);

    _widget->sortedListView()->setCurrentIndex(sortedListViewIndex);
    _widget->mainListView()->setCurrentIndex(mainListViewIndex);

    activeList = -1;
}
