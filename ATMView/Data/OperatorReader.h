#ifndef OPERATORREADER_H
#define OPERATORREADER_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>
#include <QJsonObject>
#include "HttpStructData.h"

class OperatorReader : public QObject
{
    Q_OBJECT
public:

    static OperatorReader* instance();

    Q_INVOKABLE QVariantMap getOperatorInfo(void);

    OperatorInfo &  setOperatorInfo(QVariantMap map);

signals:

public slots:


private:
    OperatorReader(QObject *parent = nullptr);
    ~OperatorReader();

private:
    static OperatorReader* m_pInstance;
    OperatorInfo m_operatorInfo;
};

#endif // OPERATORREADER_H
