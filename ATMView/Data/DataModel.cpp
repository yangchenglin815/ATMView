#include "DataModel.h"


int DataModel::rowCount(const QModelIndex &) const
{
    return m_datas.count();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < rowCount())
    {
        switch (role) {
        case UserIdRole: return m_datas.at(index.row())->userId();
        case PasswdRole: return  m_datas.at(index.row())->passwd();
        case UserNameRole: return m_datas.at(index.row())->userName();
        case IdCardRole: return m_datas.at(index.row())->idCard();
        case TypeRole: return m_datas.at(index.row())->type();
        default: return QVariant();
        }
    }
}

QHash<int, QByteArray> DataModel::roleNames() const
{
    static const QHash<int, QByteArray> roles{
        {UserIdRole, "userId"},
        {PasswdRole, "passwd"},
        {UserNameRole, "userName"},
        {IdCardRole, "idCard"},
        {TypeRole, "type"}
    };
    return roles;
}

QVariantMap DataModel::get(int row) const
{
    OperatorReader *reader = m_datas.value(row);
    return { {"userId", reader->userId()},
        {"passwd", reader->passwd()},
        {"userName", reader->userName()},
        {"idCard", reader->idCard()},
        {"type", reader->type()}};
}

void DataModel::append(const QString &userId, const QString &passwd, const QString &userName, const QString &idCard, const QString &type)
{
    int row = m_datas.count();
    beginInsertRows(QModelIndex(), row, row);
    OperatorReader *r = new OperatorReader(userId, passwd, userName, idCard, type);
    m_datas.append(r);
    endInsertRows();
}

void DataModel::set(int row, const QString &userId, const QString &passwd, const QString &userName, const QString &idCard, const QString &type)
{
    if (row < 0 || row >= m_datas.count())
        return;
    OperatorReader *r = new OperatorReader(userId, passwd, userName, idCard, type);
    m_datas.replace(row, r);
    dataChanged(index(row, 0), index(row, 0), { UserIdRole, PasswdRole, UserNameRole, IdCardRole, TypeRole});
}

void DataModel::remove(int row)
{
    if (row < 0 || row >= m_datas.count())
        return;
    beginRemoveRows(QModelIndex(), row, row);
    m_datas.removeAt(row);
    endRemoveRows();
}

OperatorReader *DataModel::data() const
{
    return m_data;
}

void DataModel::setData(OperatorReader *r)
{
    m_data = r;
    emit operatorInfoChanged();
}
