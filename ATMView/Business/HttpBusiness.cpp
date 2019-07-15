#include "HttpBusiness.h"
#include "HttpAgent.h"
#include "DataModelReader.h"
#include "GlogManager.h"

HttpBusiness* HttpBusiness::m_pInstance = NULL;

HttpBusiness *HttpBusiness::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new HttpBusiness;
    }
    return m_pInstance;
}

void HttpBusiness::RequestOnOperatorLogin()
{
    OperatorInfo operatorInfo = DataModelReader::instance()->operatorInfo();
    InterfaceInputHead headerInfo = DataModelReader::instance()->interfaceHead();

    HttpAgent::instance()->RequestOnOperatorLogin(operatorInfo, headerInfo);
}

void HttpBusiness::RequestOnGetBaseInfo()
{
    UserBaseInfo userBaseInfo = DataModelReader::instance()->userBaseInfo();
    InterfaceInputHead headerInfo = DataModelReader::instance()->interfaceHead();

    HttpAgent::instance()->RequestOnGetBaseInfo(userBaseInfo, headerInfo);
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

void HttpBusiness::RequestOnHeartbeat()
{
    HeartbeatData heartbeatData = DataModelReader::instance()->heartbeatData();
    InterfaceInputHead interfaceHead = DataModelReader::instance()->interfaceHead();

    HttpAgent::instance()->RequestOnHeartbeat(heartbeatData, interfaceHead);
}

void HttpBusiness::RespondOnOperatorLogin(int nCode, QString sMsg, QString sessionId)
{
    if (nCode != e_success)
    {
        LOG(INFO)<<"OperatorLogin 请求出现异常 -- 错误码: "<<nCode<<", 错误信息: "<<sMsg.toLocal8Bit().data();
        sMsg = QStringLiteral("系统初始化异常--错误码:%1, 错误信息:%2").arg(nCode).arg(sMsg);
        emit respondSigOnNetworkErr(nCode, sMsg);
    }
    else
    {
        LOG(INFO)<<"OperatorLogin 请求成功";
        InterfaceInputHead interfaceHead = DataModelReader::instance()->interfaceHead();
        interfaceHead.sessionId = sessionId;
        DataModelReader::instance()->setInterfaceHead(interfaceHead);
    }
}

void HttpBusiness::RespondOnGetBaseInfo(int nCode, QString sMsg, ModelStatus modelStatus, QString sysNo)
{
    if (nCode != e_success)
    {
        LOG(INFO)<<"GetBaseInfo 请求出现异常 -- 错误码: "<<nCode<<", 错误信息: "<<sMsg.toLocal8Bit().data();
        sMsg = QStringLiteral("系统初始化异常--错误码:%1, 错误信息:%2").arg(nCode).arg(sMsg);
        emit respondSigOnNetworkErr(nCode, sMsg);
    }
    else
    {
        LOG(INFO)<<"GetBaseInfo 请求成功";
        UserBaseInfo userBaseInfo = DataModelReader::instance()->userBaseInfo();
        userBaseInfo.sysNo = sysNo;
        DataModelReader::instance()->setUserBaseInfo(userBaseInfo);

        IdCardPicData idCardPicData;
        idCardPicData.sysCode = "0";
        idCardPicData.sysNo = sysNo;
        DataModelReader::instance()->setIdCardPicData(idCardPicData);

        DataModelReader::instance()->setModelStatus(modelStatus);
        emit respondSigOnGetBaseInfo();
    }
}

void HttpBusiness::RespondOnGetIdCardPic(int nCode, QString sMsg, QString picData)
{

}

void HttpBusiness::RespondOnIfCanIdentify(int nCode, QString sMsg, bool successed, QString batchId)
{

}

void HttpBusiness::RespondOnBackendRecognize(int nCode, QString sMsg, int result)
{

}

void HttpBusiness::RespondOnCompleteIdentify(int nCode, QString sMsg, int result)
{

}

void HttpBusiness::RespondOnHeartbeat(int nCode, QString sMsg)
{
    HeartbeatData heartbeatData = DataModelReader::instance()->heartbeatData();
    if (nCode != e_success)
    {
        heartbeatData.offlineCount++;
        LOG(INFO)<<"Heartbeat 请求出现异常 -- 错误码: "<<nCode<<", 错误信息: "<<sMsg.toLocal8Bit().data();
    }
    else
    {
        LOG(INFO)<<"Heartbeat 请求成功";
        heartbeatData.offlineCount = 0;
        emit respondSigOnHeartbeat(true);
    }

    if (5 == heartbeatData.offlineCount)  //判断为离线
    {
        LOG(INFO)<<"设备已离线";
        emit respondSigOnHeartbeat(false);
    }
    DataModelReader::instance()->setHeartbeatData(heartbeatData);
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
            this, SLOT(RespondOnOperatorLogin(int, QString, QString)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnGetIdCardPic(int, QString, QString)),
            this, SLOT(RespondOnGetIdCardPic(int, QString, QString)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnIfCanIdentify(int, QString, bool, QString)),
            this, SLOT(RespondOnIfCanIdentify(int, QString, bool, QString)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnBackendRecognize(int, QString, int)),
            this, SLOT(RespondOnBackendRecognize(int, QString, int)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnCompleteIdentify(int, QString, int)),
            this, SLOT(RespondOnCompleteIdentify(int, QString, int)));
    connect(HttpAgent::instance(), SIGNAL(RespondOnHeartbeat(int, QString)),
            this, SLOT(RespondOnHeartbeat(int, QString)));

    qRegisterMetaType<ModelStatus>("ModelStatus");
    connect(HttpAgent::instance(), SIGNAL(RespondOnGetBaseInfo(int, QString, ModelStatus, QString)),
            this, SLOT(RespondOnGetBaseInfo(int, QString, ModelStatus, QString)));
}
