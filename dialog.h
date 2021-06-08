#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStringListModel>
#include "Wishlist.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QStringListModel *model;

};


#endif // DIALOG_H
