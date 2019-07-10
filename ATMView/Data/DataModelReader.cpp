#include "DataModelReader.h"
#include "UserConfig.h"

DataModelReader* DataModelReader::m_pInstance = NULL;

DataModelReader *DataModelReader::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new DataModelReader;
    }
    return m_pInstance;
}

QVariantMap DataModelReader::getInterfaceHead() const
{
    QVariantMap map;
    map.clear();

    map.insert("sessionId", m_interfaceInputHead.sessionId);
    map.insert("terminalId", m_interfaceInputHead.terminalId);
    map.insert("terminalType", m_interfaceInputHead.terminalType);
    map.insert("terminalVersion", m_interfaceInputHead.terminalVersion);
    map.insert("sysType", m_interfaceInputHead.sysType);
    map.insert("sysVersion", m_interfaceInputHead.sysVersion);
    map.insert("userId", m_interfaceInputHead.userId);
    map.insert("portalVersion", m_interfaceInputHead.portalVersion);
    map.insert("invokeTime", m_interfaceInputHead.invokeTime);

    return map;
}

QVariantMap DataModelReader::getOperatorInfo() const
{
    QVariantMap map;
    map.clear();

    map.insert("userId", m_operatorInfo.userId);
    map.insert("passwd", m_operatorInfo.passwd);
    map.insert("userName", m_operatorInfo.userName);
    map.insert("idCard", m_operatorInfo.idCard);
    map.insert("type", m_operatorInfo.type);

    return map;
}

InterfaceInputHead &DataModelReader::setInterfaceHead(QVariantMap map)
{
    m_interfaceInputHead.sessionId = map.value("sessionId").toString();
    m_interfaceInputHead.terminalId = map.value("terminalId").toString();
    m_interfaceInputHead.terminalType = map.value("terminalType").toString();
    m_interfaceInputHead.terminalVersion = map.value("terminalVersion").toString();
    m_interfaceInputHead.sysType = map.value("sysType").toString();
    m_interfaceInputHead.sysVersion = map.value("sysVersion").toString();
    m_interfaceInputHead.userId = map.value("userId").toString();
    m_interfaceInputHead.portalVersion = map.value("portalVersion").toString();
    m_interfaceInputHead.invokeTime = map.value("invokeTime").toString();

    return m_interfaceInputHead;
}

OperatorInfo &DataModelReader::setOperatorInfo(QVariantMap map)
{
    m_operatorInfo.userId = map.value("userId").toString();
    m_operatorInfo.passwd = map.value("passwd").toString();
    m_operatorInfo.userName = map.value("userName").toString();
    m_operatorInfo.idCard = map.value("idCard").toString();
    m_operatorInfo.type = map.value("type").toString();

    return m_operatorInfo;
}

DataModelReader::DataModelReader(QObject *parent) : QObject(parent)
{
    INSTANCE_USER_CONFIG->getOperatorInfo(m_operatorInfo.userId, m_operatorInfo.passwd);

    m_interfaceInputHead.userId = m_operatorInfo.userId;
    m_interfaceInputHead.terminalVersion = INSTANCE_USER_CONFIG->getVersion();
    m_interfaceInputHead.terminalId = INSTANCE_USER_CONFIG->getMac();
}
