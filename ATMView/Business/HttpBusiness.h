#ifndef HTTPBUSINESS_H
#define HTTPBUSINESS_H

#include <QObject>
#include <QVariantMap>
#include "HttpStructData.h"

class HttpBusiness : public QObject
{
    Q_OBJECT
public:
    static HttpBusiness* instance();

    //经办人登录请求
    Q_INVOKABLE void RequestOnOperatorLogin();
    //获取人员信息请求
   Q_INVOKABLE void RequestOnGetBaseInfo();
    //获取人员身份证照片请求
   Q_INVOKABLE void RequestOnGetIdCardPic(IdCardPicData idCardPicData, InterfaceInputHead header);
    //获取人员是否可以认证请求
   Q_INVOKABLE void RequestOnIfCanIdentify(QString sysNo, InterfaceInputHead header);
    //后台比对请求
   Q_INVOKABLE void RequestOnBackendRecognize(BackendRecognizeData backendRecognizeData, InterfaceInputHead header);
    //完成认证请求
    Q_INVOKABLE void RequestOnCompleteIdentify(CompleteIdentifyData completeIdentifyData, InterfaceInputHead header);
    //心跳请求
    Q_INVOKABLE void RequestOnHeartbeat();

signals:
    //经办人登录应答
    void respondSigOnOperatorLogin();
    //获取人员信息应答
    void respondSigOnGetBaseInfo();
    //获取人员身份证照片应答
    void respondSigOnGetIdCardPic(int nCode, QString sMsg, QString picData);
    //获取人员是否可以认证应答
    void respondSigOnIfCanIdentify(int nCode, QString sMsg, bool successed, QString batchId);
    //后台比对应答
    void respondSigOnBackendRecognize(int nCode, QString sMsg, int result);
    //完成认证应答
    void respondSigOnCompleteIdentify(int nCode, QString sMsg, int result);
    //心跳应答
    void respondSigOnHeartbeat(bool online);
    //网络异常应答
    void respondSigOnNetworkErr(int nCode, QString sMsg);

 private slots:
    //经办人登录应答
    void RespondOnOperatorLogin(int nCode, QString sMsg, QString sessionId);
    //获取人员信息应答
    void RespondOnGetBaseInfo(int nCode, QString sMsg, ModelStatus modelStatus, QString sysNo);
    //获取人员身份证照片应答
    void RespondOnGetIdCardPic(int nCode, QString sMsg, QString picData);
    //获取人员是否可以认证应答
    void RespondOnIfCanIdentify(int nCode, QString sMsg, bool successed, QString batchId);
    //后台比对应答
    void RespondOnBackendRecognize(int nCode, QString sMsg, int result);
    //完成认证应答
    void RespondOnCompleteIdentify(int nCode, QString sMsg, int result);
    //心跳应答
    void RespondOnHeartbeat(int nCode, QString sMsg);

private:
    explicit HttpBusiness(QObject *parent = NULL);
    ~HttpBusiness();

    //初始化连接
    void InitConnect();

private:
    static HttpBusiness* m_pInstance;
};

#endif // HTTPBUSINESS_H
