#include "dialog.h"
#include "ui_dialog.h"
#include "Wishlist.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model = new QStringListModel (this);
    model->setStringList(mylist);
    ui->listView->setModel(model);
}

Dialog::~Dialog()
{
    delete ui;
}
