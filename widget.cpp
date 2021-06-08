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
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));


        painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
        painter.drawEllipse(200, 50, 150, 150);
        painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        painter.drawEllipse(212, 103, 45, 45);
        painter.drawEllipse(292, 103, 45, 45);
        painter.drawEllipse(252, 138, 45, 45);
        painter.drawEllipse(252, 65, 45, 45);



}
