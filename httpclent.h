#ifndef HTTPCLENT_H
#define HTTPCLENT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

class HttpClent : public QObject
{
    Q_OBJECT
public:
    explicit HttpClent(QObject *parent = nullptr);

public:
    void RequestURL(QString sUrl, QByteArray baData, bool bGet=true);

signals:
    void getHtmlSig(QString sText);

private slots:
    void finishedSlot(QNetworkReply* pReply);

private:
    QNetworkAccessManager* m_pManager;
};

#endif // HTTPCLENT_H
