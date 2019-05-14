#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "textticker.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout* myLayout = new QHBoxLayout();
    TextTicker* ticker = new TextTicker();
    ticker->setText("床前明月光，疑是地上霜，举头望明月，低头思故乡。床前明月光，疑是地上霜，举头望明月，低头思故乡");
    myLayout->addWidget(ticker);
    ui->pushButton->setLayout(myLayout);
    ui->pushButton->setWindowFlag(Qt::WindowTitleHint);


    QHBoxLayout* myLayout1 = new QHBoxLayout();
    TextTicker* ticker1 = new TextTicker();
    ticker1->setText("吃葡萄不吐葡萄皮");
    myLayout1->addWidget(ticker1);
    ui->pushButton_2->setLayout(myLayout1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
