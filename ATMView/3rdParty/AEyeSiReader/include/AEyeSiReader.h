#ifndef AEYESIREADER_H
#define AEYESIREADER_H

#include "aeyesireader_global.h"

typedef struct _AESsCardOrgInfo
{
	char cardId[256];     //卡识别码
	char cardType[256];   //卡类别
	char version[256];    //规范版本
	char orgNumber[256];  //初始化机构编号
	char issueDate[256];  //发卡日期
	char validity[256];   //卡有效期
	char cardNumber[256]; //卡号
} AESsCardOrgInfo;

typedef struct _AESsCardPersonInfo
{
	char ssNumber[256];  //社会保障号码
	char name[256];      //姓名
	char nameExt[256];   //姓名扩展
	char sex[256];       //性别
	char nation[256];    //民族
	char birthland[256]; //出生地
	char birthday[256];  //出生日期
} AESsCardPersonInfo;

class AEYESIREADER_EXPORT AEyeSiReader
{
public:
	AEyeSiReader();
	~AEyeSiReader();

    virtual int AEyeSiReader_ReadOrgInfo(AESsCardOrgInfo* orgInfo);
	virtual int AEyeSiReader_ReadPersonInfo(AESsCardPersonInfo* personInfo);
	virtual int AEyeSiReader_ChangePin(char* oldPin, char* newPin);
	virtual int AEyeSiReader_VerifyPin(char* pin);
};

extern "C" {
	AEYESIREADER_EXPORT AEyeSiReader* getDllObj();
};

#endif // AEYESIREADER_H
