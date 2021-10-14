#include "listview.h"

ListView::ListView(QWidget *parent): QListView(parent)
{

}

void ListView::currentChanged(const QModelIndex& current, const QModelIndex& previous)
{
   emit sigCurrentIndex(current);

   QListView::currentChanged(current, previous);
}
