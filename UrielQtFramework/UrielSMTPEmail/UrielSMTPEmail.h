#pragma once
#include "UrielSMTPEmail\UrielSMTPEmail.h"
#include "ThirdPartyLibraries\SMTPEmail\SmtpMime"
#include "UrielDefinition\UrielDefinition.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
//客户端设置
//使用imap协议时：
//收信服务器： imap.zju.edu.cn      端口 : 143    使用SSL端口 : 993
//发信服务器： smtp.zju.edu.cn      端口 : 25    使用SSL端口 : 994
//使用pop3协议时：
//收信服务器：pop3.zju.edu.cn      端口 : 110    使用SSL端口 : 995
//发信服务器：smtp.zju.edu.cn      端口 : 25     使用SSL端口 : 994

class UrielSMTPEmail
{
private:
	// Constructor.
	UrielSMTPEmail();
	UrielSMTPEmail(const UrielSMTPEmail& other);
	// Default destructor.
	~UrielSMTPEmail();

public:
	// Singleton instance accessor.
	static UrielSMTPEmail *getInstance();

	// The singleton instance.
	static UrielSMTPEmail* m_instance;

	/*static std::atomic<UrielSMTPEmail*> m_instance;
	static std::mutex m_mutex;*/
	int sendEmail(UrielDatabase * database,const sSMTPEmailItem & EmailItem);
};
