#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->breakout

    Start = new QAction("&Start",this);
    Pause = new QAction("&Pause",this);
    Demo = new QAction("&Demo",this);
    Open = new QAction("&Open",this);
    Save = new QAction("&Save",this);

    toolbar = addToolBar("Menu");                    ;




    QMenu *mainmenu = ui->menubar->addMenu("&Menu");

    mainmenu->addAction(Start);
    mainmenu->addAction(Pause);
    mainmenu->addAction(Demo);
    mainmenu->addAction(Open);
    mainmenu->addAction(Save);

    toolbar->addAction(Start);
    toolbar->addAction(Pause);
    toolbar->addAction(Demo);
    toolbar->addAction(Open);
    toolbar->addAction(Save);





    connect(Start, SIGNAL(triggered()),this, SLOT(start()));
    connect(Pause, SIGNAL(triggered()), this, SLOT(pause()));



    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->breakout,SLOT(setSpeed(int)));

    connect(ui->breakout, SIGNAL(update()), this, SLOT(updateStatus()));
    this->setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);
    ui->breakout->setMouseTracking(true);


}

void MainWindow::start(){
    ui->breakout->startGame();
}

void MainWindow::pause(){
    ui->breakout->pauseGame();
}

void MainWindow::reset(){
    ui->breakout->resetGame();
}

void MainWindow::exit(){
    qApp->exit();
}

void MainWindow::updateStatus(){
    ui->scrp1->setText(QString::number(ui->breakout->getScore1()));
    ui->scrp2->setText(QString::number(ui->breakout->getScore2()));
    ui->positp1->setText(QString::number(ui->breakout->getPaddleposit1().x())+','+QString::number(ui->breakout->getPaddleposit1().y()));
    ui->positp2->setText(QString::number(ui->breakout->getPaddleposit2().x())+','+QString::number(ui->breakout->getPaddleposit2().y()));
    ui->positball->setText(QString::number(ui->breakout->getBallPosit().x())+','+QString::number(ui->breakout->getBallPosit().y()));
    ui->nballs->setText(QString::number(ui->breakout->getnballs()));

}


  void MainWindow::mouseMoveEvent(QMouseEvent *event){
       ui->breakout->paddle->movemouse(event->pos().y()-100);
  }

MainWindow::~MainWindow()
{
    delete ui;
}
