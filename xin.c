#include "xin.h"
#include <Windows.h>
#include <string.h>

char allString[1024];

/*
ҵ��ͨ�ŵĴ��������ٺ���.
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
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "user: %s", bind->user);
	MessageBox(NULL, TEXT(allString), TEXT(xin_bind), MB_OK | MB_ICONINFORMATION);
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
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "user: %s", unbind->user);
	MessageBox(NULL, TEXT(allString), TEXT(xin_unbind), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
>> ����: ִ��ָ�Ʊȶ�
����ֵ: 0 �ύ�ɹ�, -1 ����, -2 δ��¼. -3 ��������
*/
int __stdcall xin_compare(XHANDLE * h, xcompare_t * c)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "sIDNO: %s\nFingerCode: %s", c->sIDNO, c->FingerCode.pdata);
	MessageBox(NULL, TEXT(allString), TEXT(xin_compare), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
�ϻ�ָ��.
*/
int __stdcall xin_pclock(XHANDLE * h, xpclock_t * c)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "iTime: %s\sIDNO: %s\nsPCNO: %s", c->iTime, c->sIDNO, c->sPCNO);
	MessageBox(NULL, TEXT(allString), TEXT(xin_pclock), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
�»�ָ��
*/
int __stdcall xin_pcunlock(XHANDLE * h, xpcunlock_t * c)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "iTime: %s\sIDNO: %s\nsPCNO: %s", c->iTime, c->sIDNO, c->sPCNO);
	MessageBox(NULL, TEXT(allString), TEXT(xin_pcunlock), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
��ѯ
*/
int __stdcall xin_query(XHANDLE h, xquery_t * c)
{
	memset(allString, 0, sizeof(allString));
	sprintf(allString, "IDNO: %s", c->sIDNO);
	MessageBox(NULL, TEXT(allString), TEXT(xin_query), MB_OK | MB_ICONINFORMATION);
	return 0;
}

/*
�ɹ����� 0 ʧ�ܷ��� -1;
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