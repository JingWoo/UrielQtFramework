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
	// ���õ�¼ FTP ���������û���������
	void setUserInfo(const QString &userName, const QString &password);
	// �ϴ��ļ�
	void put(const QString &fileName, const QString &path);
	// �����ļ�
	void get(const QString &path, const QString &fileName);
	// �����ļ�
	void get(const QString &path);

signals:
	void error(QNetworkReply::NetworkError);
	// �ϴ�����
	void uploadProgress(qint64 bytesSent, qint64 bytesTotal);
	// ���ؽ���
	void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
	void replyFinished(QNetworkReply*);
	void UrielReplyFinished();
	private slots:
	// ���ع�����д�ļ�
	void finished();
private:
	UrielQtFrameworkOptions *g_pOptions{ nullptr };
	QUrl m_pUrl;
	QFile m_file;
	QNetworkAccessManager m_manager;
	QNetworkReply *m_pReply{ nullptr };
};
