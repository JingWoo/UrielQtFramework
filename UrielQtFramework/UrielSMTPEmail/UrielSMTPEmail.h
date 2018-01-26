#pragma once
#include "UrielSMTPEmail\UrielSMTPEmail.h"
#include "ThirdPartyLibraries\SMTPEmail\SmtpMime"
#include "UrielDefinition\UrielDefinition.h"
QT_FORWARD_DECLARE_CLASS(UrielDatabase)
//�ͻ�������
//ʹ��imapЭ��ʱ��
//���ŷ������� imap.zju.edu.cn      �˿� : 143    ʹ��SSL�˿� : 993
//���ŷ������� smtp.zju.edu.cn      �˿� : 25    ʹ��SSL�˿� : 994
//ʹ��pop3Э��ʱ��
//���ŷ�������pop3.zju.edu.cn      �˿� : 110    ʹ��SSL�˿� : 995
//���ŷ�������smtp.zju.edu.cn      �˿� : 25     ʹ��SSL�˿� : 994

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
