/***********************************************************************************
*								AppEventListener.cpp
*
* Copyright(C):	北京智慧眼科技股份有限公司
*
* Author:  HJM,TZH
*
* Date: 2018-12
*
* Description: 用于整个App事件监测，如用户输入等
***********************************************************************************/
#include "AppEventListener.h"
#include <QCoreApplication>
#include <QMouseEvent>
#include <QCursor>
#include <QTimer>
#include <Windows.h>

#include "UserConfig.h"
#include "SystemChecker.h"

AppEventListener::AppEventListener(QObject *parent)
	: QObject(parent)
{
   
}

AppEventListener::~AppEventListener()
{

}

bool AppEventListener::eventFilter(QObject *obj, QEvent *event)
{	

	return false;
}
