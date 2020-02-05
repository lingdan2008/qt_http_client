#include "httpclent.h"
#include <QDebug>

HttpClent::HttpClent(QObject *parent) : QObject(parent)
{
    qDebug() << __FUNCTION__;

    m_pManager = new QNetworkAccessManager(this);
    Q_ASSERT(m_pManager);

    QObject::connect(m_pManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
}

void HttpClent::RequestURL(QString sUrl, QByteArray baData, bool bGet)
{
    qDebug() << __FUNCTION__ << sUrl;

    QUrl url(sUrl);
    QNetworkRequest request(url);

    QNetworkReply *pReply;
    if(bGet) {
        pReply = m_pManager->get(request);
    }
    else {
        pReply = m_pManager->post(request, baData);
    }

    Q_ASSERT(pReply);
}

void HttpClent::finishedSlot(QNetworkReply* pReply)
{
    QVariant vStatusCode = pReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(vStatusCode.isValid()) {
        qDebug() << "status code:" << vStatusCode.toInt();
    }

    QVariant vReason = pReply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if(vReason.isValid()) {
        qDebug() << "reason:" << vReason.toString();
    }

    if(QNetworkReply::NoError == pReply->error()) {
        QByteArray baData = pReply->readAll();

        qDebug() << __FUNCTION__ << QString::fromUtf8(baData);

        emit getHtmlSig(QString::fromUtf8(baData));
    }
    else {
        qDebug() << __FUNCTION__ << pReply->errorString();
    }

    pReply->deleteLater();
}
