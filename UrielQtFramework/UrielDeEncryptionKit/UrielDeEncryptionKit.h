#pragma once

#include <QCryptographicHash>
#include <QChar>
#include <QObject>
#include <vector>
#include <QByteArray>
#include <string>

using namespace std;
/**
* @brief The UrielDeEncryptionKit class
* ���ݵļӽ��ܡ�ǩ����У������
*/
class UrielDeEncryptionKit
{
private:

	 UrielDeEncryptionKit();
	 UrielDeEncryptionKit(const UrielDeEncryptionKit& other);
public:

	// Singleton instance accessor.
	static UrielDeEncryptionKit *getInstance();

	// The singleton instance.
	static UrielDeEncryptionKit* m_instance;
	/**
	* @brief getMD5Hash ��ȡ�ַ�����MD5ɢ��ֵ
	* @param param_data ��ת��������
	* @return ת�����ɢ��ֵ
	*/
	QString getMD5Hash(const QString &param_data);

	/**
	* @brief getSHAHash ��ȡ�ַ�����SHAɢ��ֵ
	* @param param_data ��ת��������
	* @return ת�����ɢ��ֵ
	*/
	QString getSHAHash(const QString &param_data);

	/**
	* @brief getByKaiser ��ȡ���ÿ������ܵ��ַ���
	* @param param_data �����ܵ�����
	* @param param_key ������Կ
	* @return �Ƿ���ܳɹ�
	*/
	bool getByKaiser(QString &param_data, qint8 param_key);


	/**
	* @brief getEncryByAES ��AES���м���
	* @param paramSource �������ַ���
	* @param paramDest ���ܺ���ַ���
	* @return �Ƿ���ܳɹ�
	*/
	bool getEncryByAES(QString paramSource, QString &paramDest);

	/**
	* @brief decryptByAES ��AES���н���
	* @param paramSource �������ַ���
	* @param paramDest ���ܺ���ַ���
	* @return �Ƿ���ܳɹ�
	*/
	bool decryptByAES(QString paramSource, QString &paramDest);

	/**
	* @brief setPassword ���ü��ܵ���Կ
	* @param param_password ��Կ
	*/
	void setPassword(QString param_password);

	/**
	* @brief setSalt ���ü�����
	* @param param_salt
	*/
	void setSalt(QString param_salt);

private:

	/**
	* @brief mPassword ����
	*/
	QString mPassword;
};

