#include "widget.h"
#include "ui_widget.h"
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle(tr("阴阳怪气生成器"));
    setWindowIcon(QIcon(":/image/1.jpg"));

    myString = "***";

    lineEdit = new QLineEdit;
    lineEdit->setPlaceholderText(tr("输入你想要阴阳怪气的事情"));

    OKButton = new QPushButton(tr("&Generate"));
    connect(OKButton, &QPushButton::clicked, this, &Widget::generate);

    textEdit = new QTextEdit;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(OKButton);
    layout->addWidget(textEdit);
    setLayout(layout);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::generate()
{
    textEdit->clear();
    if (!lineEdit->text().isEmpty())
        myString = lineEdit->text();
    QFile file(":/text/test.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("Read File"), tr("Cannot open file test.txt"));
        return;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
    while (!in.atEnd())
    {
        QString line = in.readLine();
        line.replace("***", myString);
        textEdit->append(line);
    }
}
