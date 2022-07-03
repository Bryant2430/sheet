#include "secdialog.h"
#include "ui_secdialog.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

SecDialog::data SecDialog::getdata() const{
    return data_;
}

void SecDialog::on_buttonBox_accepted()
{
    data_.data1 = ui -> firedit -> text();
    data_.data2 = ui -> secedit -> text();
    data_.data3 = ui -> thirdedit -> text();
    data_.data4 = ui -> fouredit -> text();


    accept();
}


void SecDialog::on_buttonBox_rejected()
{
    close();
}

