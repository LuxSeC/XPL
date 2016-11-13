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

	//余额变动通知.
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
		XIN_EVENT_CONNCLOSE,	//当连接断开时,产生此事件.
		XIN_EVENT_LOGIN,
		XIN_EVENT_BIND,
		XIN_EVENT_MATCH,		//指纹查询接口
		XIN_EVENT_PCUNLOCK,		//用户解锁开始消费接口.
		XIN_EVENT_PCLOCK,		//用户下机接口.
		XIN_EVENT_QUERY,		//提供一个证件号码, 查询用户是否绑定过指纹.
		XIN_EVENT_UNBIND,		//解除绑定接口.
		XIN_NOTIFY_BALANCE,		//余额变动通知.
	};

#define PRIVATE_REQ_FILEDS		int req_id; XHANDLE xc;

	struct xrawdata {
		void * pdata;
		unsigned int size;
	};
	struct xuser {
		char sIDNO[36];			//用户证件号码.	(必填)
		char sName[64];			//用户姓名.		(必填)
		unsigned char iSex;		//用户性别.		(必填) 1 男性 0 女性
		char sFolk[5];			//民族
		char sAddress[70];		//地址
		char sSigned[30];		//签发机关
		char sBirth[16];		//出生日期
		char sLife[30];			//有效年限
		xrawdata_t sPhoto;
		unsigned int iVerify;	//审核 1 审核通过了 0 审核未通过
	};

	struct xbind {
		PRIVATE_REQ_FILEDS
			xuser_t user; //实名信息.
		xrawdata_t FingerCode;
		xrawdata_t BackupFingerCode;
		//	图片.
		xrawdata_t sFingerPic;
		xrawdata_t sBackupFingerPic;
		//  大头照
		xrawdata_t sCameraPhoto;
		xrawdata_t sBackupCameraPhoto;
	};

	struct xunbind {
		PRIVATE_REQ_FILEDS
			xuser_t user; //实名信息.
		xrawdata_t FingerCode;
	};

	struct xcompare {
		PRIVATE_REQ_FILEDS
			xrawdata_t FingerCode;
		char sIDNO[36];			//用户证件号码.	(当单纯指纹比对失败时,提示用户输入证件号码,并再次提交比对请求.)
	};

	struct xpcunlock {
		PRIVATE_REQ_FILEDS
			time_t iTime;
		char sIDNO[36];			//用户证件号码.
		char sPCNO[128];		//机器号
	};

	struct xloginresult {
		int event_id;
		int success;
		unsigned int balance;
		double rate;
		const char * message;	//* 服务器返回的消息. 如果不为空.则需要提示用户.
	};


	struct xbindresult {
		int event_id;
		int success; // 0 绑定成功, -1 实名已经绑定过其它指纹, -2 指纹已经绑定过其它实名. -3实名信息无效.
		const char * message;
		char sIDNO[36];			//绑定成功或者失败的用户证件号码.
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
		char sPCNO[128];		//机器号
	};


	struct xquery {
		PRIVATE_REQ_FILEDS
			char sIDNO[36];
	};
	struct xquery_result {
		int event_id;
		int success;
		int white; // 1 在白名单内 0 不在白名单内
		int review; // 0 等待审核 1 审核通过 2 审核未通过.
		char sIDNO[36];
	};

	struct xbalance_notify {
		int event_id;
		uint64_t seq; //seq 序号.
		unsigned int balance;
		double rate;
	};

	typedef void(*xin_onlogin_cb)			(XHANDLE h, xlogin_result_t * login);
	typedef void(*xin_onbind_cb)			(XHANDLE h, xbind_result_t * bind);
	typedef void(*xin_onunbind_cb)			(XHANDLE h, xbind_result_t * unbind);
	typedef void(*xin_onmatch_cb)			(XHANDLE h, xcompare_result_t * cmp);
	typedef void(*xin_onquery_cb)			(XHANDLE h, xquery_result_t * query);
	typedef void(*xin_onbalancechange)		(XHANDLE h, xbalance_notify_t * bl);
	typedef void(*xin_onlock_cb)			(XHANDLE h, xpclock_result_t * lock); // lock: 1 下机 0 上机
	typedef void(*xin_log_cb)				(XHANDLE h, int level, const char * logstr);
	typedef void(*xin_onclose_cb)			(XHANDLE h);
	typedef struct xinsettings xinsettings_t;
	struct xinsettings {
		xin_onlogin_cb  login_cb;	// 登录处理回调.
		xin_onbind_cb   bind_cb;	// 绑定结果处理回调.
		xin_onunbind_cb unbind_cb;
		xin_onmatch_cb	match_cb;	// 匹配到结果回调.
		xin_onbalancechange balance_notify; //余额改变通知.
		xin_onquery_cb		query_cb;
		xin_onlock_cb		lock_cb;		//* 上下机处理通知,服务器做标识，已经上机的用户，全网不再提供比对服务. 需要确保该用户正确下机.()
		xin_onclose_cb		close_cb;		//连接被断开回调,当网络断开时调用.
		xin_log_cb			log_cb;			//日志记录回调.
	};


	typedef void(__stdcall * xin_event_cb)(XHANDLE h, int ev_type, void * pdata);


	/*
	业务通信的创建与销毁函数.
	*/
	XHANDLE		__stdcall xin_init(const char * account, const char * sn, xinsettings_t * settings);
	void		__stdcall xin_uninit(XHANDLE h);

	/* 设置日志回调. 用于获取并输出日志. */
	void		__stdcall xin_set_logcb(XHANDLE h, xin_log_cb log_cb);

	/*
	>> 功能 提交绑定信息
	返回值: 0 提交成功, -1,掉线状态, -2 未登录. -3 参数错误
	*/
	int __stdcall xin_bind(XHANDLE * h, xbind_t * bind);

	/*
	功能: 提交指纹解绑请求.
	返回值: 0 提交成功, -1,掉线状态, -2 未登录. -3 参数错误
	要求与限制:
	1、必须是已经绑定过指纹的用户.
	2、用户徐本人刷身份证并按指纹。确定是本人操作方可解绑.
	*/
	int __stdcall xin_unbind(XHANDLE * h, xunbind_t * unbind);

	/*
	>> 功能: 执行指纹比对
	返回值: 0 提交成功, -1 掉线, -2 未登录. -3 参数错误
	*/
	int __stdcall xin_compare(XHANDLE * h, xcompare_t * c);

	/*
	上机指令.
	*/
	int __stdcall xin_pclock(XHANDLE * h, xpclock_t * c);

	/*
	下机指令
	*/
	int __stdcall xin_pcunlock(XHANDLE * h, xpcunlock_t * c);

	int __stdcall xin_query(XHANDLE h, xquery_t * c);
	/*
	成功返回 0 失败返回 -1;
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
