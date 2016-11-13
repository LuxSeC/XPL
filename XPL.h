#pragma once
#ifndef _XIN_XINPLG_H
#define _XIN_XINPLG_H

#ifdef __cplusplus
extern "C" {
#endif
#include <time.h>
#include <stdint.h>

#define	INVALID_XHANDLE		NULL
#define xpclock_t xpcunlock_t
#define xpcunlock_result_t xpclock_result_t

	typedef void*			XHANDLE;
	typedef struct xuser	xuser_t;
	typedef struct xrawdata xrawdata_t;
	typedef struct xbind	xbind_t;
	typedef struct xbindresult xbind_result_t;
	typedef struct xunbind	xunbind_t;
	typedef struct xcompare xcompare_t;
	typedef struct xcompare_result xcompare_result_t;

	typedef struct xloginresult xlogin_result_t;
	typedef struct xpcunlock xpcunlock_t;

	typedef struct xpclockresult xpclock_result_t;


	typedef struct xquery  xquery_t;
	typedef struct xquery_result  xquery_result_t;

	//���䶯֪ͨ.
	typedef struct xbalance_notify xbalance_notify_t;

#if !defined(LOG_ERR)
	enum {
		LOG_ERR,
		LOG_WARNING,
		LOG_NOTICE,
		LOG_INFO,
		LOG_DEBUG,
		LOG_EMERG,
		LOG_ALERT,
	};

#endif

	enum {
		XIN_EVENT_CONNCLOSE,	//�����ӶϿ�ʱ,�������¼�.
		XIN_EVENT_LOGIN,
		XIN_EVENT_BIND,
		XIN_EVENT_MATCH,		//ָ�Ʋ�ѯ�ӿ�
		XIN_EVENT_PCUNLOCK,		//�û�������ʼ���ѽӿ�.
		XIN_EVENT_PCLOCK,		//�û��»��ӿ�.
		XIN_EVENT_QUERY,		//�ṩһ��֤������, ��ѯ�û��Ƿ�󶨹�ָ��.
		XIN_EVENT_UNBIND,		//����󶨽ӿ�.
		XIN_NOTIFY_BALANCE,		//���䶯֪ͨ.
	};

#define PRIVATE_REQ_FILEDS		int req_id; XHANDLE xc;

	struct xrawdata {
		void * pdata;
		unsigned int size;
	};
	struct xuser {
		char sIDNO[36];			//�û�֤������.	(����)
		char sName[64];			//�û�����.		(����)
		unsigned char iSex;		//�û��Ա�.		(����) 1 ���� 0 Ů��
		char sFolk[5];			//����
		char sAddress[70];		//��ַ
		char sSigned[30];		//ǩ������
		char sBirth[16];		//��������
		char sLife[30];			//��Ч����
		xrawdata_t sPhoto;
		unsigned int iVerify;	//��� 1 ���ͨ���� 0 ���δͨ��
	};

	struct xbind {
		PRIVATE_REQ_FILEDS
			xuser_t user; //ʵ����Ϣ.
		xrawdata_t FingerCode;
		xrawdata_t BackupFingerCode;
		//	ͼƬ.
		xrawdata_t sFingerPic;
		xrawdata_t sBackupFingerPic;
		//  ��ͷ��
		xrawdata_t sCameraPhoto;
		xrawdata_t sBackupCameraPhoto;
	};

	struct xunbind {
		PRIVATE_REQ_FILEDS
			xuser_t user; //ʵ����Ϣ.
		xrawdata_t FingerCode;
	};

	struct xcompare {
		PRIVATE_REQ_FILEDS
			xrawdata_t FingerCode;
		char sIDNO[36];			//�û�֤������.	(������ָ�Ʊȶ�ʧ��ʱ,��ʾ�û�����֤������,���ٴ��ύ�ȶ�����.)
	};

	struct xpcunlock {
		PRIVATE_REQ_FILEDS
			time_t iTime;
		char sIDNO[36];			//�û�֤������.
		char sPCNO[128];		//������
	};

	struct xloginresult {
		int event_id;
		int success;
		unsigned int balance;
		double rate;
		const char * message;	//* ���������ص���Ϣ. �����Ϊ��.����Ҫ��ʾ�û�.
	};


	struct xbindresult {
		int event_id;
		int success; // 0 �󶨳ɹ�, -1 ʵ���Ѿ��󶨹�����ָ��, -2 ָ���Ѿ��󶨹�����ʵ��. -3ʵ����Ϣ��Ч.
		const char * message;
		char sIDNO[36];			//�󶨳ɹ�����ʧ�ܵ��û�֤������.
	};

	struct xcompare_result
	{
		int event_id;
		int success;
		const char * message;
		char sIDNO[36];
		xuser_t user;
	};

	struct xpclockresult {
		int event_id;
		int success;
		char sIDNO[36];
		char sPCNO[128];		//������
	};


	struct xquery {
		PRIVATE_REQ_FILEDS
			char sIDNO[36];
	};
	struct xquery_result {
		int event_id;
		int success;
		int white; // 1 �ڰ������� 0 ���ڰ�������
		int review; // 0 �ȴ���� 1 ���ͨ�� 2 ���δͨ��.
		char sIDNO[36];
	};

	struct xbalance_notify {
		int event_id;
		uint64_t seq; //seq ���.
		unsigned int balance;
		double rate;
	};

	typedef void(*xin_onlogin_cb)			(XHANDLE h, xlogin_result_t * login);
	typedef void(*xin_onbind_cb)			(XHANDLE h, xbind_result_t * bind);
	typedef void(*xin_onunbind_cb)			(XHANDLE h, xbind_result_t * unbind);
	typedef void(*xin_onmatch_cb)			(XHANDLE h, xcompare_result_t * cmp);
	typedef void(*xin_onquery_cb)			(XHANDLE h, xquery_result_t * query);
	typedef void(*xin_onbalancechange)		(XHANDLE h, xbalance_notify_t * bl);
	typedef void(*xin_onlock_cb)			(XHANDLE h, xpclock_result_t * lock); // lock: 1 �»� 0 �ϻ�
	typedef void(*xin_log_cb)				(XHANDLE h, int level, const char * logstr);
	typedef void(*xin_onclose_cb)			(XHANDLE h);
	typedef struct xinsettings xinsettings_t;
	struct xinsettings {
		xin_onlogin_cb  login_cb;	// ��¼����ص�.
		xin_onbind_cb   bind_cb;	// �󶨽������ص�.
		xin_onunbind_cb unbind_cb;
		xin_onmatch_cb	match_cb;	// ƥ�䵽����ص�.
		xin_onbalancechange balance_notify; //���ı�֪ͨ.
		xin_onquery_cb		query_cb;
		xin_onlock_cb		lock_cb;		//* ���»�����֪ͨ,����������ʶ���Ѿ��ϻ����û���ȫ�������ṩ�ȶԷ���. ��Ҫȷ�����û���ȷ�»�.()
		xin_onclose_cb		close_cb;		//���ӱ��Ͽ��ص�,������Ͽ�ʱ����.
		xin_log_cb			log_cb;			//��־��¼�ص�.
	};


	typedef void(__stdcall * xin_event_cb)(XHANDLE h, int ev_type, void * pdata);


	/*
	ҵ��ͨ�ŵĴ��������ٺ���.
	*/
	XHANDLE		__stdcall xin_init(const char * account, const char * sn, xinsettings_t * settings);
	void		__stdcall xin_uninit(XHANDLE h);

	/* ������־�ص�. ���ڻ�ȡ�������־. */
	void		__stdcall xin_set_logcb(XHANDLE h, xin_log_cb log_cb);

	/*
	>> ���� �ύ����Ϣ
	����ֵ: 0 �ύ�ɹ�, -1,����״̬, -2 δ��¼. -3 ��������
	*/
	int __stdcall xin_bind(XHANDLE * h, xbind_t * bind);

	/*
	����: �ύָ�ƽ������.
	����ֵ: 0 �ύ�ɹ�, -1,����״̬, -2 δ��¼. -3 ��������
	Ҫ��������:
	1���������Ѿ��󶨹�ָ�Ƶ��û�.
	2���û��챾��ˢ���֤����ָ�ơ�ȷ���Ǳ��˲������ɽ��.
	*/
	int __stdcall xin_unbind(XHANDLE * h, xunbind_t * unbind);

	/*
	>> ����: ִ��ָ�Ʊȶ�
	����ֵ: 0 �ύ�ɹ�, -1 ����, -2 δ��¼. -3 ��������
	*/
	int __stdcall xin_compare(XHANDLE * h, xcompare_t * c);

	/*
	�ϻ�ָ��.
	*/
	int __stdcall xin_pclock(XHANDLE * h, xpclock_t * c);

	/*
	�»�ָ��
	*/
	int __stdcall xin_pcunlock(XHANDLE * h, xpcunlock_t * c);

	int __stdcall xin_query(XHANDLE h, xquery_t * c);
	/*
	�ɹ����� 0 ʧ�ܷ��� -1;
	*/
	int __stdcall xrawdata_init(xrawdata_t * raw, const char * data, unsigned int size);
	void __stdcall xrawdata_uninit(xrawdata_t * raw);


	char * utf8_to_gb(const char * string);
	char * gb_to_utf8(const char * string);
	void free_str(const char * str);

#ifdef __cplusplus
};
#endif

#endif // _XIN_XINPLG_H
