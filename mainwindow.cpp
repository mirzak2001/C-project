#include "mainwindow.h"
#include "movies.h"
#include "dialog.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>

   QStringList mylist;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    csvModel = new QStringListModel(this);
    detailmodel = new QStringListModel(this);
    QStringList moviesList = movies.getTitles();

    csvModel->setStringList(moviesList);

    proxyModel = new QSortFilterProxyModel();
    proxyModel->setSourceModel(csvModel);
    ui->listView->setModel(proxyModel);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete csvModel;
}




void MainWindow::on_pushButton_clicked()
{
        proxyModel->setFilterFixedString(ui->lineEdit->text());
        ui->lineEdit->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    proxyModel->setFilterFixedString(ui->lineEdit->text());
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_3_clicked()
{
    proxyModel->setFilterKeyColumn(5);
    proxyModel->setFilterFixedString(ui->lineEdit->text());
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_4_clicked()
{
    proxyModel->setFilterKeyColumn(6);
    proxyModel->setFilterFixedString(ui->lineEdit->text());
    ui->lineEdit->clear();
}


void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    std::string MovieTitle = (index.data().toString().toStdString());
    std::cout << "Selecting: " << MovieTitle << std::endl;

    QStringList MovieDetails = movies.MovieDetails(MovieTitle);

    detailmodel->setStringList(MovieDetails);
    ui->listView_2->setModel(detailmodel);
    ui->listView_2->setEditTriggers(QAbstractItemView::DoubleClicked);

}


void MainWindow::on_pushButton_5_clicked()
{
    dialog = new Dialog (this);
    dialog->show();

}


void MainWindow::on_pushButton_7_clicked()
{
    csvModel->removeRows(ui->listView->currentIndex().row(), 1);
}



void MainWindow::on_pushButton_8_clicked()
{
    int row = csvModel->rowCount();
    csvModel->insertRows(row,1);
}




void MainWindow::on_actionSave_2_triggered()
{
    std::ofstream outputFile("C:/Users/mirza/Documents/test_app/data/movies_test.txt");
    for(int i = 0; i < csvModel->rowCount(); i++){
        QModelIndex index = csvModel->index(i);
        std::string Movie = (index.data().toString()).toStdString();
        std::string details = movies.MovieDetailsExport(Movie).join(';').toStdString();
        outputFile << Movie << ";" << details << "\n";
    }
    outputFile.close();
}


void MainWindow::on_pushButton_6_clicked()
{


    mylist << (ui->listView->currentIndex().data().toString());
}


void MainWindow::on_actionHelp_triggered()
{
    widget = new Widget (this);
    widget->show();
}

