#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QAbstractListModel>

class MainModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MainModel(QObject *parent = nullptr);

    void addData(const QString& data);
    void removeData(int index);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

signals:

private:
    QStringList _data;


};

#endif // MAINMODEL_H
