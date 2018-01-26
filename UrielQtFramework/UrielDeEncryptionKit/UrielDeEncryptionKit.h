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
* 数据的加解密、签名、校验等组件
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
	* @brief getMD5Hash 获取字符串的MD5散列值
	* @param param_data 待转换的数据
	* @return 转换后的散列值
	*/
	QString getMD5Hash(const QString &param_data);

	/**
	* @brief getSHAHash 获取字符串的SHA散列值
	* @param param_data 待转换的数据
	* @return 转换后的散列值
	*/
	QString getSHAHash(const QString &param_data);

	/**
	* @brief getByKaiser 获取采用凯撒机密的字符串
	* @param param_data 待加密的数据
	* @param param_key 加密秘钥
	* @return 是否加密成功
	*/
	bool getByKaiser(QString &param_data, qint8 param_key);


	/**
	* @brief getEncryByAES 用AES进行加密
	* @param paramSource 待加密字符串
	* @param paramDest 加密后的字符串
	* @return 是否解密成功
	*/
	bool getEncryByAES(QString paramSource, QString &paramDest);

	/**
	* @brief decryptByAES 用AES进行解密
	* @param paramSource 待解密字符串
	* @param paramDest 解密后的字符串
	* @return 是否解密成功
	*/
	bool decryptByAES(QString paramSource, QString &paramDest);

	/**
	* @brief setPassword 设置加密的密钥
	* @param param_password 密钥
	*/
	void setPassword(QString param_password);

	/**
	* @brief setSalt 设置加密盐
	* @param param_salt
	*/
	void setSalt(QString param_salt);

private:

	/**
	* @brief mPassword 密码
	*/
	QString mPassword;
};

