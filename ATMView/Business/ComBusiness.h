#ifndef COMBUSINESS_H
#define COMBUSINESS_H

#include <QObject>
#include "ReadIdCardThread.h"
#include "CommonConstData.h"
#include "HttpStructData.h"

class ComBusiness : public QObject
{
    Q_OBJECT
public:
    static ComBusiness* instance();

    Q_INVOKABLE void ReadIdCard();

private:
    explicit ComBusiness(QObject *parent = nullptr);

    //初始化连接
    void InitConnect();

signals:
    void sigOnReadCardFailed(QString errMsg);
    void sigOnReadCardSuccess();

public slots:
    void onReadCardFailed(int errCode);
    void onReadCardSuccessed(AuthReadCardResult authReadCardResult);

private:
    static ComBusiness* m_pInstance;
};

#endif // COMBUSINESS_H
