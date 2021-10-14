#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <QListView>

class ListView : public QListView
{
    Q_OBJECT
public:
    ListView(QWidget *parent = nullptr);

signals:
    void sigCurrentIndex(const QModelIndex &current);

protected slots:
    void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;
};

#endif // LISTVIEW_H
