#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    qDebug() << __FUNCTION__;

    ui->setupUi(this);

    ui->lineEdit_2->setVisible(false);
    QObject::connect(ui->comboBox_RequestType, SIGNAL(currentIndexChanged(int)), this, SLOT(showPostContent(int)));
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

    if(0 == ui->comboBox_RequestType->currentIndex()) {
        m_httpClient.RequestURL(ui->lineEdit->text().trimmed(), "", true);
    }
    else {
        m_httpClient.RequestURL(ui->lineEdit->text().trimmed(), "", false);
    }

}

void Dialog::showHtmlSlot(QString sText)
{
    qDebug() << __FUNCTION__;

    ui->textEdit_Content->setText(sText);
}

void Dialog::showPostContent(int nIdx)
{
    if(0 == ui->comboBox_RequestType->currentIndex()) {
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_2->setText("");
    }
    else {
        ui->lineEdit_2->setVisible(true);
    }
}
