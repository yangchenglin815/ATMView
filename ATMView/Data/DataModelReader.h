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

    InterfaceInputHead & setInterfaceHead(QVariantMap map);
    OperatorInfo &  setOperatorInfo(QVariantMap map);

private:
    explicit DataModelReader(QObject *parent = nullptr);

signals:

public slots:

private:
    static DataModelReader* m_pInstance;

    InterfaceInputHead m_interfaceInputHead;
    OperatorInfo m_operatorInfo;
};

#endif // DATAMODELREADER_H
