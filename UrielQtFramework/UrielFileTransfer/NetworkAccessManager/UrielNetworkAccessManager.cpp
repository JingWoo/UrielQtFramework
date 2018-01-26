#include "UrielNetworkAccessManager.h"
#include <QFileInfo>
#include "UrielQtFrameworkOptions/UrielQtFrameworkOptions.h"
// Singleton instance pointer.

std::atomic<UrielNetworkAccessManager*> UrielNetworkAccessManager::g_pUrielNetworkAccessManager;
std::mutex UrielNetworkAccessManager::m_mutex;

//UrielNetworkAccessManager *UrielNetworkAccessManager::g_pUrielNetworkAccessManager = nullptr;
UrielNetworkAccessManager* UrielNetworkAccessManager::getInstance() {
	//return g_pUrielNetworkAccessManager;
	UrielNetworkAccessManager* tmp = g_pUrielNetworkAccessManager.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = g_pUrielNetworkAccessManager.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new UrielNetworkAccessManager;
			std::atomic_thread_fence(std::memory_order_release);
			g_pUrielNetworkAccessManager.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}

UrielNetworkAccessManager::UrielNetworkAccessManager(QObject * parent)
	:QObject(parent)
{
	g_pOptions = UrielQtFrameworkOptions::getInstance();
	// 设置协议
	sUrielFTPItem item=g_pOptions->getFTPConfigParameter();
	m_pUrl.setScheme("http");
	//m_pUrl.setScheme("ftp");
	m_pUrl.setHost(item.m_sHostIp);
	m_pUrl.setPort(item.m_iPort);
	m_pUrl.setUserName(item.m_sUserName);
	m_pUrl.setPassword(item.m_sPassword);
}

UrielNetworkAccessManager::~UrielNetworkAccessManager()
{
}


// 设置地址和端口
void UrielNetworkAccessManager::setHostPort(const QString &host, int port)
{
	m_pUrl.setHost(host);
	m_pUrl.setPort(port);
}

// 设置登录 FTP 服务器的用户名和密码
void UrielNetworkAccessManager::setUserInfo(const QString &userName, const QString &password)
{
	m_pUrl.setUserName(userName);
	m_pUrl.setPassword(password);
}

// 上传文件
void UrielNetworkAccessManager::put(const QString &fileName, const QString &path)
{
	QFile file(fileName);
	file.open(QIODevice::ReadOnly);
	QByteArray data = file.readAll();

	m_pUrl.setPath(path);
	m_pReply = m_manager.put(QNetworkRequest(m_pUrl), data);

	connect(m_pReply, SIGNAL(uploadProgress(qint64, qint64)), this, SIGNAL(uploadProgress(qint64, qint64)));
	connect(m_pReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SIGNAL(error(QNetworkReply::NetworkError)));
}


// 下载文件
void UrielNetworkAccessManager::get(const QString &path, const QString &fileName)
{
	QFileInfo info;
	info.setFile(fileName);

	m_file.setFileName(fileName);
	m_file.open(QIODevice::WriteOnly | QIODevice::Append);
	m_pUrl.setPath(path);

	m_pReply = m_manager.get(QNetworkRequest(m_pUrl));

	connect(m_pReply, SIGNAL(finished()), this, SLOT(finished()));
	connect(m_pReply, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(downloadProgress(qint64, qint64)));
	connect(m_pReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SIGNAL(error(QNetworkReply::NetworkError)));
	connect(&m_manager, SIGNAL(finished(QNetworkReply*)), this, SIGNAL(replyFinished(QNetworkReply*)));
}


void UrielNetworkAccessManager::get(const QString &path)
{
	m_pUrl.setPath(path);

	m_pReply = m_manager.get(QNetworkRequest(m_pUrl));

	connect(m_pReply, SIGNAL(downloadProgress(qint64, qint64)), this, SIGNAL(downloadProgress(qint64, qint64)));
	connect(m_pReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SIGNAL(error(QNetworkReply::NetworkError)));
	connect(&m_manager, SIGNAL(finished(QNetworkReply*)), this, SIGNAL(replyFinished(QNetworkReply*)));
}



// 下载过程中写文件
void UrielNetworkAccessManager::finished()
{
	QNetworkReply *pReply = qobject_cast<QNetworkReply *>(sender());
	switch (pReply->error()) {
	case QNetworkReply::NoError: {
		m_file.write(pReply->readAll());
		m_file.flush();
	}
	 break;
	default:
		break;
	}

	m_file.close();
	pReply->deleteLater();
	emit UrielReplyFinished();
}