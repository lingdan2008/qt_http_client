#ifndef DIALOG_H
#define DIALOG_H

#include "httpclent.h"

#include <QDialog>
#include "httpclent.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_Submit_clicked();

    void showHtmlSlot(QString sText);

private:
    Ui::Dialog *ui;

private:
    HttpClent m_httpClient;
};

#endif // DIALOG_H
