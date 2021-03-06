#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStandardItemModel>
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QStringListModel>
#include <QStringList>
#include <movies.h>
#include "dialog.h"
#include "widget.h"

extern  QStringList mylist;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow // logic
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_actionSave_2_triggered();

    void on_pushButton_6_clicked();

    void on_actionHelp_triggered();

    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
    QStringListModel *csvModel;
    QStringListModel *detailmodel;
    QStandardItemModel *shadowmodel;
    QSortFilterProxyModel *proxyModel;
    Movies movies;
    Dialog *dialog;
    Widget *widget;


};


#endif // MAINWINDOW_H
