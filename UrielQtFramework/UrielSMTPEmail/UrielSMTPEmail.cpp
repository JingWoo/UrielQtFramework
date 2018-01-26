#include "UrielSMTPEmail.h"
#include <atomic>
#include <mutex>
#include <QPair>
#include "UrielQtFrameworkOptions\UrielQtFrameworkOptions.h"
#include "UrielDatabase\UrielDatabase.h"

// Singleton instance pointer.
UrielSMTPEmail *UrielSMTPEmail::m_instance = nullptr;

// Singleton instance accessor (static).

UrielSMTPEmail* UrielSMTPEmail::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new UrielSMTPEmail();
	}
	return m_instance;
}

//UrielSMTPEmail *UrielSMTPEmail::getInstance()
//{
//	//return g_pOptions;
//	UrielSMTPEmail* tmp = m_instance.load(std::memory_order_relaxed);
//	std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
//	if (tmp == nullptr) {
//		std::lock_guard<std::mutex> lock(m_mutex);
//		tmp = m_instance.load(std::memory_order_relaxed);
//		if (tmp == nullptr) {
//			tmp = new UrielSMTPEmail;
//			std::atomic_thread_fence(std::memory_order_release);//释放内存fence
//			m_instance.store(tmp, std::memory_order_relaxed);
//		}
//	}
//	return tmp;
//
//}

UrielSMTPEmail::UrielSMTPEmail(void) {

}

UrielSMTPEmail::UrielSMTPEmail(const UrielSMTPEmail& other) {

}

UrielSMTPEmail::~UrielSMTPEmail() {

}

int UrielSMTPEmail::sendEmail(UrielDatabase * database,const sSMTPEmailItem & EmailItem) {
	// First we need to create an SmtpClient object
	// We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

	//UrielQtFrameworkOptions * options = UrielQtFrameworkOptions::getInstance();

	//SmtpClient smtp(options->getSystemEmailSendServer(), 
	//	options->getSystemEmailSendServerPort(),
	//	options->getSystemEmailUseSSL()?SmtpClient::SslConnection: SmtpClient::TlsConnection);

	//// We need to set the username (your email address) and password
	//// for smtp authentification.
	//smtp.setUser(options->getSystemEmailAccount());
	//smtp.setPassword(options->getSystemEmailPassword());

	sUrielSystemSettingsItem system_info;
	database->getSystemSettings(system_info);

	SmtpClient::ConnectionType Protocol = SmtpClient::SslConnection;
	if (system_info.SystemEmailProtocol == "TLS")
		Protocol = SmtpClient::TlsConnection;
	else if(system_info.SystemEmailProtocol == "TCP")
		Protocol = SmtpClient::TcpConnection;
	else
		Protocol = SmtpClient::SslConnection;

	SmtpClient smtp(system_info.SystemEmailSendServer,
		system_info.SystemEmailSendServerPort.toInt(),
		Protocol);

	// We need to set the username (your email address) and password
	// for smtp authentification.
	smtp.setUser(system_info.SystemEMail);
	UrielDeEncryptionKit * pDeEncryptionKit = UrielDeEncryptionKit::getInstance();
	QString Decryption;
	pDeEncryptionKit->decryptByAES(system_info.SystemEMailPassword, Decryption);
	smtp.setPassword(Decryption);

	// Now we create a MimeMessage object. This is the email.
	MimeMessage message;

	EmailAddress sender(system_info.SystemEMail, system_info.SystemEmailName);
	message.setSender(&sender);
	QMapIterator<QString, QString> iRecipient(EmailItem.recipient);
	while (iRecipient.hasNext()) {
		iRecipient.next();
		message.addRecipient(new EmailAddress(iRecipient.key(), iRecipient.value()));
	}

	message.setSubject(EmailItem.subjectName);
	// Now add some text to the email.
	// First we create a MimeText object.
	MimeText text;
	text.setText(EmailItem.text);
	message.addPart(&text);

	QVector<MimeAttachment> attachmentVec;
	QMapIterator<QString, QString> iAttachment(EmailItem.attachment);
	while (iAttachment.hasNext()) {
		iAttachment.next();
		message.addPart(new MimeAttachment(new QFile(iAttachment.key())));
		//// Now we create the attachment object
		//MimeAttachment attachment(new QFile(i.key()));
		//// the file type can be setted. (by default is application/octet-stream)
		//if(!i.value().isEmpty())
		//	attachment.setContentType(i.value());
		//attachmentVec.append(attachment);
		
	}

	// Now we can send the mail

	if (!smtp.connectToHost()) {
		//emit failedToConnectToHost();
		return -1;
	}
	if (!smtp.login()) {
		//emit failedToLogin();
		return -2;
	}

	if (!smtp.sendMail(message)) {
		//emit failedToSendMail();
		return -3;
	}

	smtp.quit();



	//// First create the SmtpClient object and set the user and the password.
	//SmtpClient smtp(QLatin1String("smtp.zju.edu.cn"), 994, SmtpClient::SslConnection);

	//smtp.setUser("21525201@zju.edu.cn");
	//smtp.setPassword("WuJing3.1415926");

	//// Create a MimeMessage

	//MimeMessage message;

	//EmailAddress sender("21525201@zju.edu.cn", "Wu Jing");
	//message.setSender(&sender);

	//EmailAddress to("21525201@zju.edu.cn"/*"wangcy91@zju.edu.cn"*/, "Wang Chuan Yong");
	//message.addRecipient(&to);

	//message.setSubject("SmtpClient for Qt - Demo");

	//// Add some text
	//MimeText text;
	//text.setText("Hi!\n This is an email with some attachments.");
	//message.addPart(&text);

	//// Now we create the attachment object
	//MimeAttachment attachment(new QFile("image1.jpg"));

	//// the file type can be setted. (by default is application/octet-stream)
	//attachment.setContentType("image/jpg");

	//// Now add it to message
	//message.addPart(&attachment);

	//// Add an another attachment
	//MimeAttachment document(new QFile("document.pdf"));
	//message.addPart(&document);

	//// Now we can send the mail

	//if (!smtp.connectToHost()) {
	//	qDebug() << "Failed to connect to host!" << endl;
	//	return -1;
	//}

	//if (!smtp.login()) {
	//	qDebug() << "Failed to login!" << endl;
	//	return -2;
	//}

	//if (!smtp.sendMail(message)) {
	//	qDebug() << "Failed to send mail!" << endl;
	//	return -3;
	//}

	//smtp.quit();
	return 0;
}