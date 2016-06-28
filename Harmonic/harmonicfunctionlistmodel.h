#ifndef CHARMONICFUNCTIONLISTMODEL_H
#define CHARMONICFUNCTIONLISTMODEL_H
#include <QAbstractListModel>
#include <QVector>
#include <QVariant>
#include <QModelIndex>
#include "charmonicequation.h"


class CHarmonicFunctionListModel : public QAbstractListModel
{
public:
    CHarmonicFunctionListModel(QObject *parent = 0);

public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool removeRows(int row, int count, const QModelIndex &parent);
    bool insertRows(int row, int count, const QModelIndex &parent);

private:
    QVector<std::shared_ptr<CHarmonicEquation>> m_functions;


};

#endif // CHARMONICFUNCTIONLISTMODEL_H
