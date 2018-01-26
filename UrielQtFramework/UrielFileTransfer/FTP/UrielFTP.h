#ifndef URIEL_FTP_H_
#define URIEL_FTP_H_
#include <atomic>
#include <mutex>
#include <QDialog>
#include <QHash>
#include <QNetworkConfigurationManager>

QT_FORWARD_DECLARE_CLASS(QFtp)
QT_FORWARD_DECLARE_CLASS(QUrielUrlInfo)
QT_FORWARD_DECLARE_CLASS(QNetworkSession)
QT_FORWARD_DECLARE_CLASS(QFile)
QT_FORWARD_DECLARE_CLASS(QProgressDialog)
QT_FORWARD_DECLARE_CLASS(UrielQtFrameworkOptions)
QT_FORWARD_DECLARE_CLASS(ProgressDialog)



class UrielFtp :public QObject
{
	Q_OBJECT
private:
	UrielFtp();
	UrielFtp(const UrielFtp& other);
	UrielQtFrameworkOptions *g_pOptions{nullptr};
	QFtp *m_pFtp{nullptr};
	QHash<QString, bool> isDirectory;  //È«¾Ö
	QString m_sCurrentPath;
	QString m_sRootPath;
	QString m_strUrl;
	QFile *m_pFile{ nullptr };
	QNetworkSession *m_pNetworkSession{ nullptr };
	QNetworkConfigurationManager m_netManager;
	//ProgressDialog *m_pProgressDialog{ nullptr };
Q_SIGNALS:
	void updateDataTransferProgressSignal(qint64 readBytes, qint64 totalBytes);
	void updateDataTransferFinishSignal();
	void clearGUIList();
	void addToGuiList(const QUrielUrlInfo &);
	void GUIClear();
	void GUISetCursor();
public slots:
	void connectOrDisconnect();
	void enableConnectServer();
	void downloadFile(const QString &fileName);
	bool downloadFiles(const QString &file_path, const QString &fileName);
	QImage downloadImageFile(const QString &fileName);
	void uploadFile();
	void uploadFiles();
	void uploadFile(const QString &fileName);
	void uploadFileWithRemoteName(const QString &fileName, const  QString & remoteName);
	void uploadFile(const QString &fileName,const QString &Path);
	void uploadFileWithRemoteName(const QString &fileName, const  QString & remoteName, const QString &Path);
	void deleteFile(const QString &fileName);
	void cancelDownload();
	void ftpCommandFinished(int, bool error);
	void cdToParent();
	void updateDataTransferProgress(qint64 readBytes, qint64 totalBytes);
	void connectToFtpServer();
	void addToList(const QUrielUrlInfo &urlInfo);
	void cdToNextPath(const QString &pathName);
	void cdToSpecifiedPath(const QString &pathName);
	void cdToRootPath();
	void mkdir(const QString DirName);
	void rmdir(const QString DirName);
	void Remove(const QString& fileName);
	void removeAllFile(const QString & DirName);
	void clearisDirectory() { isDirectory.clear(); };
	QString getCurrentPath() { return m_sCurrentPath; };
	QHash<QString, bool> getDirInfo() { return isDirectory; };
	const QString & getRootPath() { return m_sRootPath; }
	void cd(const QString &name);
	void list();
	void rename(const QString &oldname, const QString &newname);
public:
	static UrielFtp* getInstance();
	static std::atomic<UrielFtp*> m_instance;
	static std::mutex m_mutex;
	void saveUsedConfiguration();
	QString _ToSpecialEncoding(const QString &InputStr);
	QString _FromSpecialEncoding(const QString &InputStr);
};



#endif 

