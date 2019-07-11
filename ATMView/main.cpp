#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QTextCodec>
#include <QFont>

#include "HttpBusiness.h"
#include "DataModelReader.h"
#include "AppInitializer.h"
#include "AppEnvChecker.h"
#include "GlogManager.h"
#include "AppCleaner.h"
#include "Windows.h"
#include "DbgHelp.h"
#include "dump.h"
#include "LogAgent.h"

int main(int argc, char *argv[])
{
    SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);
    QGuiApplication app(argc, argv);

    //设置编码格式
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    //设置字体
    QFont font;
    font.setFamily(QString::fromLocal8Bit("微软雅黑"));
    app.setFont(font);

    //检查环境（如是否单例等）
    AppEnvChecker envChecker;
    if(!envChecker.check()) {
        return -1;
    }

    //初始化
    AppInitializer  initializer;
    initializer.init(app.arguments());

    LOG(INFO)<<"App 启动.";

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("getLogObj", LogAgent::instance());
    engine.rootContext()->setContextProperty("getModelData", DataModelReader::instance());
    engine.rootContext()->setContextProperty("getHttpAgent", HttpBusiness::instance());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    int ret = app.exec();

    LOG(INFO)<<"App 退出.";

    //清理
    AppCleaner cleaner;
    cleaner.clean();

    return ret;
}
