#ifndef AEYEIDREADER_H
#define AEYEIDREADER_H

#include "aeyeidreader_global.h"

typedef struct _AEIdCardInfo
{
	char name[50];		 //姓名     
	char sex[10];		 //性别
	char nation[10];     //名族
	char birthday[30];      //出生日期
	char address[100];	 //住址	
	char idNumber[50];	 //身份证号	
	char grantDept[50];  //发证机关
	char startDate[30];	 //有效开始日期
	char endDate[30];	 //有效截止日期
	char reserved[38];	 //保留
	char photoPath[255]; //照片路径
}AEIdCardInfo;

class AEYEIDREADER_EXPORT AEyeIdReader
{
public:
	AEyeIdReader();
	~AEyeIdReader();

	virtual int AEyeIdReader_ReadBaseMsg(AEIdCardInfo* cardInfo);
	virtual int AEyeIdReader_Read(char* pName, char* pCertNo);
};

extern "C" {
	AEYEIDREADER_EXPORT AEyeIdReader* getDllObj();
};

#endif // AEYEIDREADER_H
