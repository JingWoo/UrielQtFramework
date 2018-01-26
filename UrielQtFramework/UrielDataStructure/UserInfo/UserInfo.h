#ifndef __USER_INFO_H__
#define __USER_INFO_H__

#include <QMetaType>
#include <QString>
#include <QImage>
//! [custom type definition and meta-type declaration]
class UserInfo
{
public:
	UserInfo() {};
	~UserInfo() {};

	const QString & Name() const { return m_sName; }
	const QString & StudentID() const { return m_sStudentID; }
	const QString & Password() const { return m_sPassword; }
	const QImage & HeadIco() const { if (!m_pHeadIco.isNull()) return m_pHeadIco; }

private:
	QString m_sName;
	QString m_sStudentID;
	QString m_sPassword;
	QImage  m_pHeadIco;

};

Q_DECLARE_METATYPE(UserInfo);
//! [custom type definition and meta-type declaration]

#endif
