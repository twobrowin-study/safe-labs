#include "resourcemodel.h"


int ResourceModel::rowCount(const QModelIndex &) const
{
    return static_cast<int>(dir.count()-2);
}

QVariant ResourceModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
       return dir[index.row()+2];
    return QVariant();
}
