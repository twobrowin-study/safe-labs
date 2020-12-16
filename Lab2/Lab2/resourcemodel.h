#ifndef RESOURCEMODEL_H
#define RESOURCEMODEL_H

#include <QMainWindow>
#include <QAbstractListModel>
#include <QDir>

class ResourceModel : public QAbstractListModel
{
    Q_OBJECT
private:
    QDir dir;

public:
    ResourceModel(QString resource, QObject *parent = nullptr): QAbstractListModel(parent) { dir.setPath(resource); }

    QString getResourceName() { return dir.path(); }

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index = QModelIndex(), int role = 0) const;
};

#endif // RESOURCEMODEL_H
