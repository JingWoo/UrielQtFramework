#include "UrielDeEncryptionKit.h"
#include <QDebug>
//#include <memory>
#include <QFile>
#include "botan.h"
#include "botan/hex.h"
using namespace Botan;

// Singleton instance pointer.
UrielDeEncryptionKit *UrielDeEncryptionKit::m_instance = nullptr;

// Singleton instance accessor (static).

UrielDeEncryptionKit* UrielDeEncryptionKit::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new UrielDeEncryptionKit();
	}
	return m_instance;
}

UrielDeEncryptionKit::UrielDeEncryptionKit(const UrielDeEncryptionKit& other) {

}


UrielDeEncryptionKit::UrielDeEncryptionKit()
{
	//ÉèÖÃÄ¬ÈÏÃÜÂë
	mPassword = getSHAHash("Uriel(WuJing)");
}

QString UrielDeEncryptionKit::getMD5Hash(const QString &param_data)
{
	return QString(QCryptographicHash::hash(param_data.toLocal8Bit(), QCryptographicHash::Md5).toHex());
}

QString UrielDeEncryptionKit::getSHAHash(const QString &param_data)
{
	return QString(QCryptographicHash::hash(param_data.toLocal8Bit(), QCryptographicHash::Sha3_512).toHex());
}

bool UrielDeEncryptionKit::getByKaiser(QString &param_data, qint8 param_key)
{
	if (param_data.isEmpty()) {
		return false;
	}
	for (int temp_index = 0; temp_index != param_data.size(); ++temp_index) {
		char tempChar = param_data.at(temp_index).toLatin1();
		int tempValue = 0;
		if (tempChar >= 0x30 && tempChar <= 0x39) {
			tempValue = (tempChar - '0' + param_key);
			tempChar = (tempValue >= 0) ? (tempValue % 10 + '0') : (tempValue % 10 + 0x3a);
		}
		else if (tempChar >= 0x41 && tempChar <= 0x5a) {
			tempValue = (tempChar - 'A' + param_key);
			tempChar = (tempValue >= 0) ? (tempValue % 26 + 'A') : (tempValue % 26 + 0x5b);
		}
		else if (tempChar >= 0x61 && tempChar <= 0x7a) {
			tempValue = (tempChar - 'a' + param_key);
			tempChar = (tempValue >= 0) ? (tempValue % 26 + 'a') : (tempValue % 26 + 0x7b);
		}
		param_data[temp_index] = QChar(tempChar);
	}
	return true;
}


bool UrielDeEncryptionKit::getEncryByAES(QString paramSource, QString &paramDest)
{
	try
	{
#if defined(BOTAN_HAS_MODE_CBC) && defined(BOTAN_HAS_AES)
		std::unique_ptr<Botan::Cipher_Mode> enc(
			Botan::get_cipher_mode("AES-128/CBC/PKCS7", Botan::ENCRYPTION));
		const std::vector<uint8_t> key(16, 0xAB);
		const std::vector<uint8_t> iv(16, 0xCD);
		Botan::secure_vector<uint8_t> msg1 =
			Botan::hex_decode_locked(QString::fromLatin1(paramSource.toLocal8Bit().toHex()).toStdString().c_str());
		enc->set_key(key);
		enc->start(iv);
		enc->finish(msg1);
		paramDest = QString::fromStdString(Botan::hex_encode(msg1));
#endif
		return true;
	}
	catch (Exception &e)
	{
		qDebug() << e.what();
		return false;
	}
	//try
	//{
	//	HashFunction* hash = get_hash("MD5");
	//	SymmetricKey key = hash->process(mPassword.toStdString());
	//	SecureVector<byte> raw_iv = hash->process('0' + mPassword.toStdString());
	//	InitializationVector iv(raw_iv.data(), 16);
	//	Pipe pipe(get_cipher("AES-128/CBC/PKCS7", key, iv, ENCRYPTION));
	//	pipe.process_msg(paramSource.toStdString());
	//	string output = pipe.read_all_as_string();
	//	//output = Botan::hex_encode((uint8_t*)output.data(), sizeof(output.data()));
	//	paramDest = output;
	//	return true;
	//}
	//catch (Exception &e)
	//{
	//	qDebug() << e.what();
	//	return false;
	//}
}

bool UrielDeEncryptionKit::decryptByAES(QString paramSource, QString &paramDest)
{
	try
	{
#if defined(BOTAN_HAS_MODE_CBC) && defined(BOTAN_HAS_AES)
	std::unique_ptr<Botan::Cipher_Mode> dec(
		Botan::get_cipher_mode("AES-128/CBC/PKCS7", Botan::DECRYPTION));
	const std::vector<uint8_t> key(16, 0xAB);
	const std::vector<uint8_t> iv(16, 0xCD);
	Botan::secure_vector<uint8_t> msg = 
		Botan::hex_decode_locked(paramSource.toStdString().c_str());
	dec->set_key(key);
	dec->start(iv);
	dec->finish(msg);
	paramDest = QByteArray::fromHex(QString::fromStdString(Botan::hex_encode(msg)).toLocal8Bit());
#endif
	return true;
	}
	catch (Exception &e)
	{
		qDebug() << e.what();
		return false;
	}
	//try
	//{
	//	HashFunction* hash = get_hash("MD5");
	//	SymmetricKey key = hash->process(mPassword.toStdString());
	//	SecureVector<byte> raw_iv = hash->process('0' + mPassword.toStdString());
	//	InitializationVector iv(raw_iv.data(), 16);
	//	Pipe pipe(get_cipher("AES-128/CBC/PKCS7", key, iv, DECRYPTION));
	//	//std::vector<uint8_t> vex = Botan::hex_decode(paramSource);

	//	//std::string tem;
	//	//for (size_t i = 0; i < vex.size(); ++i)
	//	//	tem += (static_cast<char>(vex[i]));
	//	pipe.process_msg(paramSource);
	//	string output = pipe.read_all_as_string();
	//	paramDest = QString::fromStdString(output);
	//	return true;
	//}
	//catch (Exception &e)
	//{
	//	qDebug() << e.what();
	//	return false;
	//}
}

void UrielDeEncryptionKit::setPassword(QString param_password)
{
	mPassword = param_password;
}

void UrielDeEncryptionKit::setSalt(QString param_salt)
{
	// TODO ÉèÖÃ¼ÓÃÜÑÎ
}
