QT += quick network script core
CONFIG += c++11
#CONFIG += qml_debug

#QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
#QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO

#CONFIG+=declarative_debug
#CONFIG+=qml_debug

INCLUDEPATH += Utils App Network Log Business Data
INCLUDEPATH += 3rdParty/gLog/include

LIBS += -lDbgHelp

win32:CONFIG(debug, debug|release): LIBS += $$PWD/3rdParty/gLog/lib/glog_d.lib
else:win32:CONFIG(release, debug|release): LIBS += $$PWD/3rdParty/gLog/lib/glog.lib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    Network/HttpBackendRecognize.cpp \
    Network/HttpClient.cpp \
    Network/HttpCompleteIdentify.cpp \
    Network/HttpGetBaseInfo.cpp \
    Network/HttpGetIdCardPic.cpp \
    Network/HttpHeartbeat.cpp \
    Network/HttpIfCanIdentify.cpp \
    Network/HttpOperatorLogin.cpp \
    Network/HttpSignal.cpp \
    Network/IHttpReqRes.cpp \
    App/AppCleaner.cpp \
    App/AppEnvChecker.cpp \
    App/AppEventListener.cpp \
    App/AppInitializer.cpp \
    App/SystemChecker.cpp \
    App/UserConfig.cpp \
    Utils/Base64.cpp \
    Utils/commonFunc.cpp \
    Utils/DataPathManager.cpp \
    Utils/FileManager.cpp \
    Utils/PixmapLoader.cpp \
    Utils/ThreadManager.cpp \
    Log/GlogManager.cpp \
    Business/GlobalSignal.cpp \
    Business/HttpAgent.cpp \
    Business/HttpBusiness.cpp \
    Data/DataModelReader.cpp \
    Log/LogAgent.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

HEADERS += \
    Network/HttpBackendRecognize.h \
    Network/HttpClient.h \
    Network/HttpCompleteIdentify.h \
    Network/HttpGetBaseInfo.h \
    Network/HttpGetIdCardPic.h \
    Network/HttpHeartbeat.h \
    Network/HttpIfCanIdentify.h \
    Network/HttpInterface.h \
    Network/HttpOperatorLogin.h \
    Network/HttpSignal.h \
    Network/IHttpReqRes.h \
    App/AppCleaner.h \
    App/AppEnvChecker.h \
    App/AppEventListener.h \
    App/AppInitializer.h \
    App/SystemChecker.h \
    App/UserConfig.h \
    Utils/Base64.h \
    Utils/CommonConstData.h \
    Utils/commonFunc.h \
    Utils/DataPathManager.h \
    Utils/dump.h \
    Utils/EnumData.h \
    Utils/FileManager.h \
    Utils/HttpStructData.h \
    Utils/PixmapLoader.h \
    Utils/ThreadManager.h \
    Log/GlogManager.h \
    Business/GlobalSignal.h \
    Business/HttpAgent.h \
    Business/HttpBusiness.h \
    Data/DataModelReader.h \
    Log/LogAgent.h
