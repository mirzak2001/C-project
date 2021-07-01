#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));


        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.drawEllipse(500, 170, 150, 150);
        painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        painter.drawEllipse(512, 223, 45, 45);
        painter.drawEllipse(592, 223, 45, 45);
        painter.drawEllipse(552, 258, 45, 45);
        painter.drawEllipse(552, 185, 45, 45);



}

void Widget::on_pushButton_clicked()
{
    this->close();
}

