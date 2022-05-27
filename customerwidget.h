#ifndef CUSTOMERWIDGET_H
#define CUSTOMERWIDGET_H

#include <QWidget>

namespace Ui {
class CustomerWidget;
}

class CustomerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerWidget(QWidget *parent = nullptr);
    ~CustomerWidget();
protected:
    void paintEvent(QPaintEvent* event);
private:
    Ui::CustomerWidget *ui;
};

#endif // CUSTOMERWIDGET_H
