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
    Q_INVOKABLE QVariantMap getModelStatus() const;

    InterfaceInputHead & interfaceHead();
    OperatorInfo &  operatorInfo();
    HeartbeatData & heartbeatData();
    UserBaseInfo & userBaseInfo();
    IdCardPicData & idCardPicData();

    void setInterfaceHead(InterfaceInputHead interfaceHead);
    void setOperatorInfo(OperatorInfo operatorInfo);
    void setHeartbeatData(HeartbeatData heartbeatData);
    void setUserBaseInfo(UserBaseInfo userBaseInfo);
    void setIdCardPicData(IdCardPicData idCardPicData);
    void setModelStatus(ModelStatus modelStatus);

    Q_INVOKABLE void setInterfaceHead(QVariantMap map);
    Q_INVOKABLE void setOperatorInfo(QVariantMap map);
    Q_INVOKABLE void setHeartbeatData(QVariantMap map);
    Q_INVOKABLE void setModelStatus(QVariantMap map);

private:
    explicit DataModelReader(QObject *parent = nullptr);

signals:

public slots:

private:
    static DataModelReader* m_pInstance;

    InterfaceInputHead m_interfaceInputHead;
    OperatorInfo m_operatorInfo;
    HeartbeatData m_heartbeatData;
    UserBaseInfo m_userBaseInfo;
    IdCardPicData m_idCardPicData;
    ModelStatus m_modelStatus;
};

#endif // DATAMODELREADER_H
