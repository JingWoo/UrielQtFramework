#ifndef ImageProcessThread_H
#define ImageProcessThread_H

#include <QImage>
#include <QMutex>
#include <QThread>
#include "UrielDataStructure/UserInfo/UserInfo.h"

//! [ImageProcessThread class definition]
class ImageProcessThread : public QThread
{
    Q_OBJECT

public:
    ImageProcessThread(QObject *parent = 0);
    ~ImageProcessThread();

    void processImage(const QImage &image);

signals:
    void sendInfo(const UserInfo &useinfo);

public slots:
    void stopProcess();

protected:
    void run();

private:
    bool m_abort;
    QImage m_image;
    QMutex mutex;
};
//! [ImageProcessThread class definition]

#endif
