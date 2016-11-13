// XPLTestOne.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "XPLTestOne.h"
#include <Windows.h>

/*
ҵ��ͨ�ŵĴ��������ٺ���.
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

/* ������־�ص�. ���ڻ�ȡ�������־. */
void		__stdcall xin_set_logcb(XHANDLE h, xin_log_cb log_cb)
{

}

/*
>> ���� �ύ����Ϣ
����ֵ: 0 �ύ�ɹ�, -1,����״̬, -2 δ��¼. -3 ��������
*/
int __stdcall xin_bind(XHANDLE * h, xbind_t * bind)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("user: %s"), bind->user);
	MessageBox(NULL, allString, TEXT("xin_bind"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
����: �ύָ�ƽ������.
����ֵ: 0 �ύ�ɹ�, -1,����״̬, -2 δ��¼. -3 ��������
Ҫ��������:
1���������Ѿ��󶨹�ָ�Ƶ��û�.
2���û��챾��ˢ���֤����ָ�ơ�ȷ���Ǳ��˲������ɽ��.
*/
int __stdcall xin_unbind(XHANDLE * h, xunbind_t * unbind)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("user: %s"), unbind->user);
	MessageBox(NULL, allString, TEXT("xin_unbind"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
>> ����: ִ��ָ�Ʊȶ�
����ֵ: 0 �ύ�ɹ�, -1 ����, -2 δ��¼. -3 ��������
*/
int __stdcall xin_compare(XHANDLE * h, xcompare_t * c)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("sIDNO: %s\nFingerCode: %s"), c->sIDNO, c->FingerCode.pdata);
	MessageBox(NULL, allString, TEXT("xin_compare"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
�ϻ�ָ��.
*/
int __stdcall xin_pclock(XHANDLE * h, xpclock_t * c)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("iTime: %s\nIDNO: %s\nsPCNO: %s"), c->iTime, c->sIDNO, c->sPCNO);
	MessageBox(NULL, allString, TEXT("xin_pclock"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
�»�ָ��
*/
int __stdcall xin_pcunlock(XHANDLE * h, xpcunlock_t * c)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("iTime: %s\nIDNO: %s\nsPCNO: %s"), c->iTime, c->sIDNO, c->sPCNO);
	MessageBox(NULL, allString, TEXT("xin_pcunlock"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
��ѯ
*/
int __stdcall xin_query(XHANDLE h, xquery_t * c)
{
	TCHAR allString[1024] = { 0 };
	wsprintf(allString, TEXT("IDNO: %s"), c->sIDNO);
	MessageBox(NULL, allString, TEXT("xin_query"), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
�ɹ����� 0 ʧ�ܷ��� -1;
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
