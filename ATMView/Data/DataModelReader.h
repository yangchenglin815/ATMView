#ifndef DATAMODELREADER_H
#define DATAMODELREADER_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>

#include "HttpStructData.h"

class DataModelReader : public QObject
{
    Q_OBJECT
public:
    static DataModelReader* instance();

    Q_INVOKABLE QVariantMap getInterfaceHead() const;
    Q_INVOKABLE QVariantMap getOperatorInfo() const;
    Q_INVOKABLE QVariantMap getHeartbeatInfo() const;

    InterfaceInputHead & interfaceHead(QVariantMap map);
    OperatorInfo &  operatorInfo(QVariantMap map);
    HeartbeatData & heartbeatData(QVariantMap map);

    Q_INVOKABLE void setInterfaceHead(QVariantMap map);
    Q_INVOKABLE void setOperatorInfo(QVariantMap map);
    Q_INVOKABLE void setHeartbeatData(QVariantMap map);

private:
    explicit DataModelReader(QObject *parent = nullptr);

signals:

public slots:

private:
    static DataModelReader* m_pInstance;

    InterfaceInputHead m_interfaceInputHead;
    OperatorInfo m_operatorInfo;
    HeartbeatData m_heartbeatData;
};

#endif // DATAMODELREADER_H
