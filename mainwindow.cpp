#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<qdebug.h>
#include <qpixmap.h>
#include <qpainter.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // styleSheet结合text, text会在中间显示,与QIcon结合，图像会在左，字在右
    // 图片很小张，重叠
    ui->btn1->setStyleSheet("#btn1{border:none; width:100px; height:100px; border-image:url(:/image/send.svg)}");
    // image是正常的，缩放正常, 不受AA_UseHighDpiPixmaps影响
    ui->btn2->setStyleSheet("#btn2{border:none; width:400px; height:400px; background-image:url(:/image/send.svg)}");
    // 单张，图像模糊
    ui->btn3->setStyleSheet("#btn3{border:none; width:200px; height:200px; image:url(:/image/send.svg)}");  

    //QIcon产生的svg图像是清晰的
#if 0
    qDebug() <<"C:/Users/kangaroo/Desktop/1.svg";
    QIcon icon("C:/Users/kangaroo/Desktop/1.svg");
    QPixmap p = icon.pixmap(200, 200);
    ui->labelSvg->setPixmap(p);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
#if 0
    QPainter painter(this);
    // 加了SmoothPixmap感觉速度快了些
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    // 缩放后，x,y,width,height会自动扩大
    //painter.drawRect(10, 10, 100, 100);

    // 用icon画出的svg图片是可以缩放的
#if 1
    QIcon icon("C:/Users/kangaroo/Desktop/1.svg");
    QPixmap p = icon.pixmap(900, 900);
#else
    // 直接画是会模糊
    QPixmap p("C:/Users/kangaroo/Desktop/1.svg");
#endif
    painter.drawPixmap(0, 0, p);
#else
    QWidget::paintEvent(event);
#endif
}

