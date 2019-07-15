#include "ComBusiness.h"
#include "DataModelReader.h"

ComBusiness* ComBusiness::m_pInstance = NULL;

ComBusiness *ComBusiness::instance()
{
    if (m_pInstance == NULL)
    {
        m_pInstance = new ComBusiness;
    }
    return m_pInstance;
}

void ComBusiness::ReadIdCard()
{
    ReadIdCardThread* thread = new ReadIdCardThread(this);
    qRegisterMetaType<AuthReadCardResult>("AuthReadCardResult");
    connect(thread, SIGNAL(readIdCardFailed(int)), this, SLOT(onReadCardFailed(int)));
    connect(thread, SIGNAL(readIdCardSuccessed(AuthReadCardResult)), this, SLOT(onReadCardSuccessed(AuthReadCardResult)));
    thread->start();
}

ComBusiness::ComBusiness(QObject *parent) : QObject(parent)
{
    InitConnect();
}

void ComBusiness::InitConnect()
{

}

void ComBusiness::onReadCardFailed(int errCode)
{
    QString tipText;
    switch (errCode)
    {
    case E_SI_CONNECT_FAILED:
        tipText = Str_SiConnectFailed;
        break;
    case E_SI_READ_FAILED:
        tipText = Str_SiReadFailed;
        break;
    case E_ID_CONNECT_FAILED:
        tipText = Str_IdConnectFailed;
        break;
    case E_ID_AUTHENTICATE_FAILED:
        tipText = Str_IdAuthenticateFailed;
        break;
    case E_ID_READ_FAILED:
        tipText = Str_IdReadFailed;
        break;
    }
    emit sigOnReadCardFailed(tipText);
}

void ComBusiness::onReadCardSuccessed(AuthReadCardResult authReadCardResult)
{
    UserBaseInfo info;
    info.name = authReadCardResult.name;
    info.idCard = authReadCardResult.certificateNumber;
    info.cardType = "0";

    DataModelReader::instance()->setUserBaseInfo(info);
    emit sigOnReadCardSuccess();
}
