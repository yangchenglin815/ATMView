#include "InterfaceHeadReader.h"
#include "UserConfig.h"

InterfaceHeadReader* InterfaceHeadReader::m_pInstance = NULL;

InterfaceHeadReader::InterfaceHeadReader(QObject *parent) : QObject(parent)
{
    m_interfaceInputHead.terminalType = "20010";
    m_interfaceInputHead. sysType = "windows";
    m_interfaceInputHead.sysVersion = "windows7";
    m_interfaceInputHead.portalVersion = "1.0";

    QString passwd;
    INSTANCE_USER_CONFIG->getOperatorInfo(m_interfaceInputHead.userId, passwd);
    m_interfaceInputHead.terminalVersion = INSTANCE_USER_CONFIG->getVersion();
    m_interfaceInputHead.terminalId = INSTANCE_USER_CONFIG->getMac();
}

InterfaceHeadReader *InterfaceHeadReader::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new InterfaceHeadReader;
    }
    return m_pInstance;
}

QVariantMap InterfaceHeadReader::getInterfaceHead() const
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

InterfaceInputHead &InterfaceHeadReader::setInterfaceHead(QVariantMap map)
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
