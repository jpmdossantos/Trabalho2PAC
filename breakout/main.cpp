#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMouseTracking(true);
    w.show();
    //w.setFixedSize(480,420);

    return a.exec();
}



/*#include <QApplication>
#include "mainwindow.h"
//#include <QMainWindow>
#include "breakout.h"
#include <QLabel>

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);
  QMainWindow w;
  w.show();
  w.setFixedSize(480 , 420);
  //w.show();
  //QWidget x;
  /*w.setCentralWidget(new Breakout);
  w.centralWidget()->resize(300,400);
  w.centralWidget()->show();*/

  //w.addWidget();
  //w.setCentralWidget(&window);
  //w.setBaseSize(300,400);
  //w.show();

/*
  Breakout window;
  window.resize(300, 400);
  window.setWindowTitle("Breakout");
  window.show();
  w.show();



  return app.exec();
}
*/
