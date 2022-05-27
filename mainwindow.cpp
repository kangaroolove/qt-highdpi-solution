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
    // overlapping, small picture
    ui->btn1->setStyleSheet("#btn1{border:none; width:100px; height:100px; border-image:url(:/image/send.svg)}");
    // Correct, it doesn't be affect by AA_UseHighDpiPixmaps
    ui->btn2->setStyleSheet("#btn2{border:none; width:400px; height:400px; background-image:url(:/image/send.svg)}");
    // Vague single picture, 
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

