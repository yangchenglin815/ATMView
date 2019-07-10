#include "OperatorReader.h"
#include "UserConfig.h"

OperatorReader* OperatorReader::m_pInstance = NULL;

OperatorReader *OperatorReader::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new OperatorReader;
    }
    return m_pInstance;
}

OperatorReader::OperatorReader(QObject *parent)
    : QObject(parent)
{
    INSTANCE_USER_CONFIG->getOperatorInfo(m_operatorInfo.userId, m_operatorInfo.passwd);
    m_operatorInfo.type = "1";
}

OperatorReader::~OperatorReader()
{

}

QVariantMap OperatorReader::getOperatorInfo()
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

OperatorInfo &OperatorReader::setOperatorInfo(QVariantMap map)
{
    m_operatorInfo.userId = map.value("userId").toString();
    m_operatorInfo.passwd = map.value("passwd").toString();
    m_operatorInfo.userName = map.value("userName").toString();
    m_operatorInfo.idCard = map.value("idCard").toString();
    m_operatorInfo.type = map.value("type").toString();

    return m_operatorInfo;
}

