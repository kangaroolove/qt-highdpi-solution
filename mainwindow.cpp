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
    initializeButtons();
    initializeLabels();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeButtons()
{
    // styleSheet结合text, text会在中间显示,与QIcon结合，图像会在左，字在右
    // 图片很小张，重叠
    ui->btn1->setStyleSheet("#btn1{border:none; width:100px; height:100px; border-image:url(:/image/send.svg)}");
    // image是正常的，缩放正常, 不受AA_UseHighDpiPixmaps影响
    ui->btn2->setStyleSheet("#btn2{border:none; width:400px; height:400px; background-image:url(:/image/send.svg)}");
    // 单张，图像模糊
    ui->btn3->setStyleSheet("#btn3{border:none; width:200px; height:200px; image:url(:/image/send.svg)}");
}

void MainWindow::initializeLabels()
{
    QPixmap onlyPixmap(":/image/send.svg");
    ui->labelOnlyPixmap->setPixmap(onlyPixmap);

    QIcon icon(":/image/send.svg");
    QPixmap iconPixmap = icon.pixmap(200, 200);
    ui->labelQIconPixmap->setPixmap(iconPixmap);
}

