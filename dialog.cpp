#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    qDebug() << __FUNCTION__;

    ui->setupUi(this);

    QObject::connect(&m_httpClient, SIGNAL(getHtmlSig(QString)), this, SLOT(showHtmlSlot(QString)));
}

Dialog::~Dialog()
{
    qDebug() << __FUNCTION__;

    delete ui;
}

void Dialog::on_pushButton_Submit_clicked()
{
    qDebug() << __FUNCTION__;

    m_httpClient.RequestURL(ui->lineEdit->text().trimmed());
}

void Dialog::showHtmlSlot(QString sText)
{
    qDebug() << __FUNCTION__;

    ui->textEdit_Content->setText(sText);
}
