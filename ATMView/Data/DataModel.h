#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QJsonValueRef>
#include <QVariant>
#include <QHash>
#include "OperatorReader.h"

class DataModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(OperatorReader* operatorInfo READ operatorInfo WRITE setOperatorInfo NOTIFY operatorInfoChanged)
public:
    enum ReaderRole {
        UserIdRole = Qt::DisplayRole,  //0
        PasswdRole = Qt::UserRole,
        UserNameRole,
        IdCardRole,
        TypeRole
    };
    Q_ENUMS(ReaderRole)

   DataModel(QObject *parent = nullptr) {Q_UNUSED(parent);}

   int rowCount(const QModelIndex & = QModelIndex()) const;
   QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
   QHash<int, QByteArray> roleNames() const;

   Q_INVOKABLE QVariantMap get(int row) const;
   Q_INVOKABLE void append(const QString &userId, const QString &passwd, const QString &userName,
                           const QString &idCard, const QString &type);
   Q_INVOKABLE void set(int row, const QString &userId, const QString &passwd, const QString &userName,
                            const QString &idCard, const QString &type);
   Q_INVOKABLE void remove(int row);
   Q_INVOKABLE OperatorReader* data() const;
   Q_INVOKABLE void setData(OperatorReader* r);

signals:
   void operatorInfoChanged();

public:
   QList<OperatorReader*> m_datas;
   OperatorReader* m_data;
};

#endif // DATAMODEL_H
