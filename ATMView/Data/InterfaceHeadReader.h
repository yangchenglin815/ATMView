#ifndef INTERFACEHEADREADER_H
#define INTERFACEHEADREADER_H

#include <QObject>
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>
#include <QJsonObject>
#include <QDateTime>
#include "HttpStructData.h"

class InterfaceHeadReader : public QObject
{
    Q_OBJECT
public:

    static InterfaceHeadReader* instance();

    Q_INVOKABLE QVariantMap getInterfaceHead() const;

    InterfaceInputHead & setInterfaceHead(QVariantMap map);

signals:

public slots:

private:
    explicit InterfaceHeadReader(QObject *parent = nullptr);

private:
    static InterfaceHeadReader* m_pInstance;
    InterfaceInputHead m_interfaceInputHead;
};

#endif // INTERFACEHEADREADER_H
