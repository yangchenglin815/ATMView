#ifndef READIDCARDTHREAD_H
#define READIDCARDTHREAD_H

#include <QObject>
#include <QThread>
#include <QLibrary>

#include "HttpStructData.h"
#include "EnumData.h"
#include "AEyeIdReader.h"

typedef AEyeIdReader* (*getObj)();

class ReadIdCardThread : public QThread
{
	Q_OBJECT

public:
    ReadIdCardThread(QObject *parent);
    ~ReadIdCardThread();

protected:
	//开始读卡
    int readIdCard();
	//线程启动
	virtual void run();

private:
    void loadDLL();

signals:
	//读卡成功
    void readIdCardSuccessed(AuthReadCardResult readCardResult);
    //读卡失败
    void readIdCardFailed(int errCode);

private:
	AuthReadCardResult m_readCardResult;
    AEyeIdReader* m_idReader;
};

#endif // READIDCARDTHREAD_H
