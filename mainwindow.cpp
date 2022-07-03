#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"
#include "QtDebug"
#include "QFile"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList header;

    // Change the header name of the table
    header << tr("first") << tr("second") << tr("third") << tr("fourth");
    ui->tableWidget->setHorizontalHeaderLabels(header);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Insertbtn_clicked()
{
    ui->State->setText("Inserting");
    //secdialog = new SecDialog(this);
    //secdialog->show();

    SecDialog secdialog;
    secdialog.setModal(true);
    auto status = secdialog.exec();
    if (status == QDialog::Accepted){
        auto data = secdialog.getdata();

        QList<QString> list;

        list.clear();
        list<<data.data1<<data.data2<<data.data3<<data.data4;

        int row_count = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row_count);

        QTableWidgetItem *item = new QTableWidgetItem();
        QTableWidgetItem *item1 = new QTableWidgetItem();
        QTableWidgetItem *item2 = new QTableWidgetItem();
        QTableWidgetItem *item3 = new QTableWidgetItem();

        item->setText(list[0]);
        item1->setText(list[1]);
        item2->setText(list[2]);
        item3->setText(list[3]);

        ui -> tableWidget -> setItem(row_count,0,item);
        ui -> tableWidget -> setItem(row_count,1,item1);
        ui -> tableWidget -> setItem(row_count,2,item2);
        ui -> tableWidget -> setItem(row_count,3,item3);

        ui->State->setText("Insert success");
    }
    else{
        qDebug() << "reject";
        ui->State->setText("Insert failed");
    }
}

void MainWindow::on_Savebtn_clicked()
{
    QFile f("./output.csv");
    if (f.open(QFile::WriteOnly | QFile::Truncate)){
         QTextStream data( &f );
         QStringList strList;

         int row_count = ui->tableWidget->rowCount();
         int col_count = ui->tableWidget->columnCount();

         for( int c = 0; c < col_count ; ++c )
         {
             strList<< ui->tableWidget->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString();
         }

         data << strList.join(",") << "\n";

         for( int r = 0; r < row_count; ++r )
         {
             strList.clear();
             for( int c = 0; c < col_count; ++c )
             {
                 strList << ui->tableWidget->item( r, c )->text();
             }
             data << strList.join( "," )+"\n";
         }
         ui->State->setText("Save success");
    }
    else{
        qDebug()<<"Save failed";
        ui->State->setText("Save failed");
    }
    f.close();

}
