// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN        // Exclude rarely-used stuff from Windows headers
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER // Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0x0501 // Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif
#ifndef _WIN32_WINNT // Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0501 // Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif
#ifndef _WIN32_WINDOWS // Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0501 // Change this to the appropriate value to target Windows Me or later.
#endif
#ifndef _WIN32_IE // Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0x0601 // Change this to the appropriate value to target IE 5.0 or later.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS  // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>         // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#define HPSOCKET_STATIC_LIB		


#ifndef _DEBUG
#define ADD_VMProtect			//授权模式	//开启VMPWL验证扣点模式（服务器需要测试PHP环境搭配VMPWL）
#endif
//#define OPEN_LOGIN			//开启登录功能
//#define TIME_LIMIT				//开启时间限制
#define BUILD_OPEN				//生成开关
#define TOOLBAR_OPEN			//TOOLBAR显示
#define ANTISCREENSHOT			//反截图
#define ONLINE_NUM  1000			//上线数量限制
//#define ONLINE_TIME  			//时间限制
#if _DEBUG
#define TITLENAME  _T("DEBUG 版本:4.0   -- Quick");
#else
#define TITLENAME  _T("版本:4.0 ");
#endif




#include <afxinet.h> //CInternetSession网页下载
#include <afx.h>  //VERIFY
#include <atlimage.h> //支持Cimage
#include <new>
using namespace std;

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include<crtdbg.h> //内存泄漏检测
#endif

#include <XTToolkitPro.h>    // Xtreme Toolkit Pro components
#include "macros.h"
#include "zlib.h"
#include "ipc.h"				//日志使用
#include "ISocketBase.h"



extern osIPC::Client* logger;

#define log_严重(x)  if(logger) logger->write(x,1) //严重
#define log_错误(x)  if(logger) logger->write(x,2) //错误
#define log_警告(x)  if(logger) logger->write(x,3) //警告
#define log_信息(x)  if(logger) logger->write(x,4) //信息


#ifdef ADD_VMProtect
#include "WinlicenseSDK.h"	

#define   VMPSTAR       VM_LION_BLACK_START
#define   VMPEND		VM_LION_BLACK_END
#else
#define   VMPSTAR        OUT_PUT_FUNCION_NAME_INFO
#define   VMPEND		
#endif // ADD_VMProtect


#ifdef _DEBUG


#define OUT_PUT_FUNCION_NAME_FATAL		TRACE(" 函数 %s   \t%d 行\r\n  ",__FUNCTION__,__LINE__);
#define OUT_PUT_FUNCION_NAME_ERROR		TRACE(" 函数 %s   \t%d 行\r\n  ",__FUNCTION__,__LINE__);
#define OUT_PUT_FUNCION_NAME_WARING		TRACE(" 函数 %s   \t%d 行\r\n  ",__FUNCTION__,__LINE__);
#define OUT_PUT_FUNCION_NAME_INFO		TRACE(" 函数 %s   \t%d 行\r\n  ",__FUNCTION__,__LINE__);

#define OUT_PUT_FUNCION_LINE_REMARK(X)		TRACE(" 函数 %s   \t%d 行  备注%s\r\n  ",__FUNCTION__,__LINE__,X);
#else

#define OUT_PUT_FUNCION_NAME_FATAL		log_严重(__FUNCTION__);
#define OUT_PUT_FUNCION_NAME_ERROR		log_错误(__FUNCTION__);
#define OUT_PUT_FUNCION_NAME_WARING		log_警告(__FUNCTION__);
#define OUT_PUT_FUNCION_NAME_INFO		log_信息(__FUNCTION__);

#define OUT_PUT_FUNCION_LINE_REMARK(X)		TRACE(" 函数 %s   \t%d 行  备注%s\r\n  ",__FUNCTION__,__LINE__,X);
#endif // WRITE_LOG













