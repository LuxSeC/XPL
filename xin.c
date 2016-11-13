#include "xin.h"
#include <Windows.h>
#include <string.h>

char allString[1024];

/*
业务通信的创建与销毁函数.
*/
XHANDLE		__stdcall xin_init(const char * account, const char * sn, xinsettings_t * settings)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "account: %s\nsn: %s\nsettings: %s", account, sn, settings);
	MessageBox(NULL, TEXT(allString), TEXT(xin_init), MB_OK | MB_ICONINFORMATION);
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
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "user: %s", bind->user);
	MessageBox(NULL, TEXT(allString), TEXT(xin_bind), MB_OK | MB_ICONINFORMATION);
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
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "user: %s", unbind->user);
	MessageBox(NULL, TEXT(allString), TEXT(xin_unbind), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
>> 功能: 执行指纹比对
返回值: 0 提交成功, -1 掉线, -2 未登录. -3 参数错误
*/
int __stdcall xin_compare(XHANDLE * h, xcompare_t * c)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "sIDNO: %s\nFingerCode: %s", c->sIDNO, c->FingerCode.pdata);
	MessageBox(NULL, TEXT(allString), TEXT(xin_compare), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
上机指令.
*/
int __stdcall xin_pclock(XHANDLE * h, xpclock_t * c)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "iTime: %s\sIDNO: %s\nsPCNO: %s", c->iTime, c->sIDNO, c->sPCNO);
	MessageBox(NULL, TEXT(allString), TEXT(xin_pclock), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
下机指令
*/
int __stdcall xin_pcunlock(XHANDLE * h, xpcunlock_t * c)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "iTime: %s\sIDNO: %s\nsPCNO: %s", c->iTime, c->sIDNO, c->sPCNO);
	MessageBox(NULL, TEXT(allString), TEXT(xin_pcunlock), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
查询
*/
int __stdcall xin_query(XHANDLE h, xquery_t * c)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "IDNO: %s", c->sIDNO);
	MessageBox(NULL, TEXT(allString), TEXT(xin_query), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
成功返回 0 失败返回 -1;
*/
int __stdcall xrawdata_init(xrawdata_t * raw, const char * data, unsigned int size)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "pdata: %s\nsize: %d\ndata: %s\nsize: %d", raw->pdata, raw->size, data, size);
	MessageBox(NULL, TEXT(allString), TEXT(xrawdata_init), MB_OK | MB_ICONINFORMATION);
	return 0;
}

void __stdcall xrawdata_uninit(xrawdata_t * raw)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "pdata: %s\nsize: %d", raw->pdata, raw->size);
	MessageBox(NULL, TEXT(allString), TEXT(xrawdata_uninit), MB_OK | MB_ICONINFORMATION);
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