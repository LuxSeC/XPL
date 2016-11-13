// XPLTestOne.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "XPLTestOne.h"
#include <Windows.h>

/*
业务通信的创建与销毁函数.
*/
XHANDLE		__stdcall xin_init(const char * account, const char * sn, xinsettings_t * settings)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("account: %s\nsn: %s\nsettings: %s"), account, sn, settings);
	MessageBox(NULL, allString, TEXT("xin_init"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

void		__stdcall xin_uninit(XHANDLE h)
{

}

/* 设置日志回调. 用于获取并输出日志. */
void		__stdcall xin_set_logcb(XHANDLE h, xin_log_cb log_cb)
{

}

/*
>> 功能 提交绑定信息
返回值: 0 提交成功, -1,掉线状态, -2 未登录. -3 参数错误
*/
int __stdcall xin_bind(XHANDLE * h, xbind_t * bind)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("user: %s"), bind->user);
	MessageBox(NULL, allString, TEXT("xin_bind"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
功能: 提交指纹解绑请求.
返回值: 0 提交成功, -1,掉线状态, -2 未登录. -3 参数错误
要求与限制:
1、必须是已经绑定过指纹的用户.
2、用户徐本人刷身份证并按指纹。确定是本人操作方可解绑.
*/
int __stdcall xin_unbind(XHANDLE * h, xunbind_t * unbind)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("user: %s"), unbind->user);
	MessageBox(NULL, allString, TEXT("xin_unbind"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
>> 功能: 执行指纹比对
返回值: 0 提交成功, -1 掉线, -2 未登录. -3 参数错误
*/
int __stdcall xin_compare(XHANDLE * h, xcompare_t * c)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("sIDNO: %s\nFingerCode: %s"), c->sIDNO, c->FingerCode.pdata);
	MessageBox(NULL, allString, TEXT("xin_compare"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
上机指令.
*/
int __stdcall xin_pclock(XHANDLE * h, xpclock_t * c)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("iTime: %s\nIDNO: %s\nsPCNO: %s"), c->iTime, c->sIDNO, c->sPCNO);
	MessageBox(NULL, allString, TEXT("xin_pclock"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
下机指令
*/
int __stdcall xin_pcunlock(XHANDLE * h, xpcunlock_t * c)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("iTime: %s\nIDNO: %s\nsPCNO: %s"), c->iTime, c->sIDNO, c->sPCNO);
	MessageBox(NULL, allString, TEXT("xin_pcunlock"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
查询
*/
int __stdcall xin_query(XHANDLE h, xquery_t * c)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("IDNO: %s"), c->sIDNO);
	MessageBox(NULL, allString, TEXT("xin_query"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
成功返回 0 失败返回 -1;
*/
int __stdcall xrawdata_init(xrawdata_t * raw, const char * data, unsigned int size)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("pdata: %s\nsize: %d\ndata: %s\nsize: %d"), raw->pdata, raw->size, data, size);
	MessageBox(NULL, allString, TEXT("xrawdata_init"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

void __stdcall xrawdata_uninit(xrawdata_t * raw)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("pdata: %s\nsize: %d"), raw->pdata, raw->size);
	MessageBox(NULL, allString, TEXT("xrawdata_uninit"), MB_OK | MB_ICONINFORMATION);
}

char * utf8_to_gb(const char * string)
{
	return NULL;
}
char * gb_to_utf8(const char * string)
{
	return NULL;
}
void free_str(const char * str)
{

}
