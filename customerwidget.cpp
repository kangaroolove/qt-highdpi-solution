#include "customerwidget.h"
#include "ui_customerwidget.h"
#include <qpainter.h>
#include <qicon.h>
#include <qfont.h>

CustomerWidget::CustomerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerWidget)
{
    ui->setupUi(this);
}

CustomerWidget::~CustomerWidget()
{
    delete ui;
}

void CustomerWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    // Draw a text
    QFont font;
    font.setPointSizeF(20.0);
    painter.setFont(font);
    painter.drawText(this->width() - 200, 50, "Hello world");

    // Draw a pixmap
    QIcon icon(":/image/send.svg");
    QPixmap p = icon.pixmap(50, 50);
    painter.drawPixmap(0, 0, p);
}
