#include "httpclent.h"
#include <QDebug>

HttpClent::HttpClent(QObject *parent) : QObject(parent)
{
    qDebug() << __FUNCTION__;

    m_pManager = new QNetworkAccessManager(this);
    Q_ASSERT(m_pManager);

    QObject::connect(m_pManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
}

void HttpClent::RequestURL(QString sUrl)
{
    qDebug() << __FUNCTION__ << sUrl;

    QUrl url(sUrl);
    QNetworkRequest request(url);

    QNetworkReply *pReply = m_pManager->get(request);
    Q_ASSERT(pReply);
}

void HttpClent::finishedSlot(QNetworkReply* pReply)
{
    QByteArray baData = pReply->readAll();
    pReply->deleteLater();

    qDebug() << __FUNCTION__ << QString(baData);

    emit getHtmlSig(QString(baData));
}
