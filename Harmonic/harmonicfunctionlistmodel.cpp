#include "harmonicfunctionlistmodel.h"

CHarmonicFunctionListModel::CHarmonicFunctionListModel(QObject *parent = 0)
    :QAbstractListModel(parent)
{
}

int CHarmonicFunctionListModel::rowCount(const QModelIndex &parent) const
{
    return m_functions.count();
}

QVariant CHarmonicFunctionListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= m_functions.size())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        return m_functions.at(index.row())->ToString();
    }
    else
    {
        return QVariant();
    }
}

bool CHarmonicFunctionListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        m_functions.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

QVariant CHarmonicFunctionListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Horizontal)
    {
        return QString("%1").arg(section);
    }
    else
    {
        return QString("%1").arg(section);
    }
}

Qt::ItemFlags CHarmonicFunctionListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
           return Qt::ItemIsEnabled;
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool CHarmonicFunctionListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; i < count; ++i)
    {
        m_functions.removeAt(row);
    }

    endInsertRows();
    return true;
}

bool CHarmonicFunctionListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; i < count; ++i)
    {
        m_functions.insert(row, nullptr);
    }

    endInsertRows();
    return true;
}

