/***********************************************************************************
*								dump.h
*
* Copyright(C):	智慧眼科技股份有限公司
*
* Author:  YCL
*
* Date: 2019-06
*
* Description: 崩溃捕捉文件
***********************************************************************************/
#ifndef DUMP_H
#define DUMP_H
// pro_dump.h
// 包含本文件是用来处理程序崩溃时自动生成dump文件的
// 生成的dump文件在程序的工作目录下
// 文件名格式是:年月日_时分秒.dmp
// 使用dmp示例：可直接把该dmp文件、程序和程序所对应的PDB文件
// 放在同一个目录下，然后双击打开dmp文件即可查看崩溃的现场
#include <DbgHelp.h>
#include <ShellAPI.h>
#include <ShlObj.h>
#include <QDateTime>
#include "DataPathManager.h"

#pragma comment(lib, "DbgHelp")

// 启动自动生成dump文件的话，只需要在main函数开始处
// 创建Dump文件
static LONG WINAPI MyUnhandledExceptionFilter(struct _EXCEPTION_POINTERS* ExceptionInfo)
{
    //获取当前时间
    QString curDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss");

    //生成Dump文件名
    QString path = QString::fromLocal8Bit(DataPathManager::getDumpDirPath().c_str());
    QString strFileName(QString("%1/ATMView").arg(path));
    strFileName += "_t";
    strFileName += curDateTime;
    strFileName += ".dmp";

    HANDLE lhDumpFile = CreateFile(strFileName.toStdWString().c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);//L"TT_DumpFile.dmp"
    MINIDUMP_EXCEPTION_INFORMATION loExceptionInfo;
    loExceptionInfo.ExceptionPointers = ExceptionInfo;
    loExceptionInfo.ThreadId = GetCurrentThreadId();
    loExceptionInfo.ClientPointers = TRUE;

    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(),lhDumpFile, MiniDumpNormal, &loExceptionInfo, NULL, NULL);
    CloseHandle(lhDumpFile);
    return EXCEPTION_EXECUTE_HANDLER;
}
#endif // DUMP_H
