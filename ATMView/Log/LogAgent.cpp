#include "LogAgent.h"
#include "GlogManager.h"

LogAgent* LogAgent::m_pInstance = nullptr;

LogAgent *LogAgent::instance()
{
    if (m_pInstance == nullptr)
    {
        m_pInstance = new LogAgent;
    }
    return m_pInstance;
}

void LogAgent::logInfo(QString fmt)
{
     LOG(INFO) << fmt.toLocal8Bit().data();
}

LogAgent::LogAgent(QObject *parent) : QObject(parent)
{

}
