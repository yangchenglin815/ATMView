#ifndef LOGAGENT_H
#define LOGAGENT_H

#include <QObject>
#include <QString>

class LogAgent : public QObject
{
    Q_OBJECT
public:
    static LogAgent* instance();

    Q_INVOKABLE void logInfo(QString fmt);

private:
    explicit LogAgent(QObject *parent = nullptr);

signals:

public slots:

private:
    static LogAgent* m_pInstance;
};

#endif // LOGAGENT_H
