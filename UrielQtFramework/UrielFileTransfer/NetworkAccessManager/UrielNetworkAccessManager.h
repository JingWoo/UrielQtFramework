#pragma once

#include <QObject>
#include <QUrl>
#include <QFile>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <atomic>
#include <mutex>
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
class UrielNetworkAccessManager : public QObject
{
	Q_OBJECT
private:
	UrielNetworkAccessManager(QObject * parent =nullptr);
	~UrielNetworkAccessManager();
public:
	// Singleton instance accessor.
	static UrielNetworkAccessManager* getInstance();
	// The singleton instance.
	static std::atomic<UrielNetworkAccessManager*> g_pUrielNetworkAccessManager;
	static std::mutex m_mutex;

	//// Singleton instance accessor.
	//static UrielNetworkAccessManager *getInstance();
	//// The singleton instance.
	//static UrielNetworkAccessManager* g_pUrielNetworkAccessManager;

	void setHostPort(const QString &host, int port = 21);
	// 设置登录 FTP 服务器的用户名和密码
	void setUserInfo(const QString &userName, const QString &password);
	// 上传文件
	void put(const QString &fileName, const QString &path);
	// 下载文件
	void get(const QString &path, const QString &fileName);
	// 下载文件
	void get(const QString &path);

signals:
	void error(QNetworkReply::NetworkError);
	// 上传进度
	void uploadProgress(qint64 bytesSent, qint64 bytesTotal);
	// 下载进度
	void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
	void replyFinished(QNetworkReply*);
	void UrielReplyFinished();
	private slots:
	// 下载过程中写文件
	void finished();
private:
	UrielQtFrameworkOptions *g_pOptions{ nullptr };
	QUrl m_pUrl;
	QFile m_file;
	QNetworkAccessManager m_manager;
	QNetworkReply *m_pReply{ nullptr };
};
