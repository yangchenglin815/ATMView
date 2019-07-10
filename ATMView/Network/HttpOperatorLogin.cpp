/***********************************************************************************
*								HttpOperatorLogin.cpp
*
* Copyright(C):	智慧眼科技股份有限公司
*
* Author:  YCL
*
* Date: 2019-06
*
* Description: 经办人登录网络请求实例
***********************************************************************************/

#include "HttpOperatorLogin.h"
#include "HttpSignal.h"
#include "HttpInterface.h"
#include "EnumData.h"
#include "GlogManager.h"
#include "UserConfig.h"

HttpOperatorLogin::HttpOperatorLogin(OperatorInfo operatorInfo, InterfaceInputHead header)
{
    setReqUrlAddress(INSTANCE_USER_CONFIG->getServerDefaultUrl() + c_sHttpInterfaceParam);

	QString param = createJsonStr(operatorInfo, header, c_sHttpActionOperatorLogin, "0");
	QByteArray array;
	array.append(param);
	setReqParams(array);
}

HttpOperatorLogin::~HttpOperatorLogin()
{

}

void HttpOperatorLogin::processResponse( QString strResult )
{
	QScriptEngine engine;
	QScriptValue sc = engine.evaluate("value=" + strResult);
	int nCode = sc.property("data").property("respCode").toInt32();
	QString sMsg = sc.property("data").property("respMsg").toString();
	if (!sc.property("data").property("respData").isValid())
	{
		LOG(INFO)<<"HttpOperatorLogin 返回参数json格式错误";
		nCode = e_connectServerError;
		sMsg = c_sServerJsonError;
	}

	QString sessionId = sc.property("data").property("respData").property("sessionId").toString();
	HttpSignal::instance()->RespondOnOperatorLogin(nCode, sMsg, sessionId);
	this->deleteLater();
}

void HttpOperatorLogin::processError()
{
	HttpSignal::instance()->RespondOnOperatorLogin(e_connectServerError, c_sNetError, "");
	this->deleteLater();
}

QString HttpOperatorLogin::createJsonStr( OperatorInfo operatorInfo, InterfaceInputHead header, QString funId, QString sysCode )
{
	QJsonObject dataJson, infoJson, headJson;
	operatorInfo.assemble(infoJson);
	header.assemble(headJson);

	dataJson.insert("fnId", funId);
	dataJson.insert("sysCode", sysCode);
	dataJson.insert("sign", "Sign");
	dataJson.insert("head", headJson);
	dataJson.insert("data", infoJson);

	QJsonDocument document;
	document.setObject(dataJson);
	QByteArray byte_array = document.toJson(QJsonDocument::Compact);
	QString byte_str      = QString::fromUtf8(byte_array);
	return byte_str;
}
