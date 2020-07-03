#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QLineEdit;
class QPushButton;
class QTextEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void generate();

private:
    Ui::Widget *ui;
    QLineEdit *lineEdit;
    QPushButton *OKButton;
    QTextEdit *textEdit;
    QString myString;
};
#endif // WIDGET_H
