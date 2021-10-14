#include "mainmodel.h"

MainModel::MainModel(QObject *parent) : QAbstractListModel(parent)
{

}

void MainModel::addData(const QString& data)
{
    beginResetModel();

    _data.append(data);

    endResetModel();
}

void MainModel::removeData(int index)
{
    beginResetModel();

    _data.removeAt(index);

    endResetModel();
}

int MainModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)

    return _data.size();
}

QVariant MainModel::data(const QModelIndex& index, int role) const
{
    if(role != Qt::DisplayRole) return QVariant();

    return _data.at(index.row());
}
