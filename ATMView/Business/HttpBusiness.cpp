#include "HttpBusiness.h"
#include "HttpAgent.h"
#include "DataModelReader.h"

HttpBusiness* HttpBusiness::m_pInstance = NULL;

HttpBusiness *HttpBusiness::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new HttpBusiness;
    }
    return m_pInstance;
}

void HttpBusiness::RequestOnOperatorLogin(QVariantMap operatorMap, QVariantMap headerMap)
{
    OperatorInfo operatorInfo = DataModelReader::instance()->operatorInfo(operatorMap);
    InterfaceInputHead headerInfo = DataModelReader::instance()->interfaceHead(headerMap);

    HttpAgent::instance()->RequestOnOperatorLogin(operatorInfo, headerInfo);
}

void HttpBusiness::RequestOnGetBaseInfo(UserBaseInfo userBaseInfo, InterfaceInputHead header)
{
    HttpAgent::instance()->RequestOnGetBaseInfo(userBaseInfo, header);
}

void HttpBusiness::RequestOnGetIdCardPic(IdCardPicData idCardPicData, InterfaceInputHead header)
{
    HttpAgent::instance()->RequestOnGetIdCardPic(idCardPicData, header);
}

void HttpBusiness::RequestOnIfCanIdentify(QString sysNo, InterfaceInputHead header)
{
    HttpAgent::instance()->RequestOnIfCanIdentify(sysNo, header);
}

void HttpBusiness::RequestOnBackendRecognize(BackendRecognizeData backendRecognizeData, InterfaceInputHead header)
{
    HttpAgent::instance()->RequestOnBackendRecognize(backendRecognizeData, header);
}

void HttpBusiness::RequestOnCompleteIdentify(CompleteIdentifyData completeIdentifyData, InterfaceInputHead header)
{
    HttpAgent::instance()->RequestOnCompleteIdentify(completeIdentifyData, header);
}

void HttpBusiness::RequestOnHeartbeat(QVariantMap heartBeatMap, QVariantMap headerMap)
{
    HeartbeatData heartbeatData = DataModelReader::instance()->heartbeatData(heartBeatMap);
    InterfaceInputHead interfaceHead = DataModelReader::instance()->interfaceHead(headerMap);

    HttpAgent::instance()->RequestOnHeartbeat(heartbeatData, interfaceHead);
}

HttpBusiness::HttpBusiness(QObject *parent) : QObject(parent)
{
    InitConnect();
}

HttpBusiness::~HttpBusiness()
{

}

void HttpBusiness::InitConnect()
{
    connect(HttpAgent::instance(), SIGNAL(RespondOnOperatorLogin(int, QString, QString)),
            this, SIGNAL(respondOnOperatorLogin(int, QString, QString)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnGetIdCardPic(int, QString, QString)),
            this, SIGNAL(respondOnGetIdCardPic(int, QString, QString)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnIfCanIdentify(int, QString, bool, QString)),
            this, SIGNAL(respondOnIfCanIdentify(int, QString, bool, QString)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnBackendRecognize(int, QString, int)),
            this, SIGNAL(respondOnBackendRecognize(int, QString, int)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnCompleteIdentify(int, QString, int)),
            this, SIGNAL(respondOnCompleteIdentify(int, QString, int)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnHeartbeat(int, QString)),
            this, SIGNAL(respondOnHeartbeat(int, QString)));

    qRegisterMetaType<ModelStatus>("ModelStatus");
    connect(HttpAgent::instance(), SIGNAL(RespondOnGetBaseInfo(int, QString, ModelStatus, QString)),
            this, SIGNAL(respondOnGetBaseInfo(int, QString, ModelStatus, QString)));
}
