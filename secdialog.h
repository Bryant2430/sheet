#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

    struct data{
        QString data1;
        QString data2;
        QString data3;
        QString data4;
    };

public:
    data getdata() const;

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SecDialog *ui;
    data data_;
};

#endif // SECDIALOG_H
