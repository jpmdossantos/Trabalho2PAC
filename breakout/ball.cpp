#include <iostream>
#include <QObject>
#include <qDebug>
#include "ball.h"
using namespace std;

Ball::Ball(QObject *parent) : QObject(parent)
{

  xdir = -1;
  ydir = -1;
  image.load(":/images/ball.png");

  rect = image.rect();
  resetState();
}

Ball::~Ball() {

  std::cout << ("Ball deleted") << std::endl;
}

void Ball::autoMove() {

  rect.translate(xdir, ydir);

  if (rect.left() <= 0) {
    xdir = -1*xdir;

  }

  if (rect.right() >= RIGHT_EDGE) {
    xdir = -1*xdir;
  }

  if (rect.top() <= 0) {
    ydir = -1*ydir;
    emit kick(1);
    qDebug()<<"emitido kick";

  }
  if (rect.bottom()>= BOTTOM_EDGE)
  {
      ydir = -1*ydir;
      emit kick(1);
      qDebug()<<"emitido kick";
  }
}

void Ball::resetState() {

  rect.moveTo(INITIAL_X, INITIAL_Y);
}

void Ball::setXDir(int x) {

  xdir = x;
}

void Ball::setYDir(int y) {

  ydir = y;
}

int Ball::getXDir() {

  return xdir;
}

int Ball::getYDir() {

  return ydir;
}

QRectF Ball::getRect() {

  return rect;
}

QImage & Ball::getImage() {

  return image;
}

void Ball::updateSpeed(int s)
{
    if (this->getXDir()>0)
        this->setXDir(s);
    else if (this->getXDir()<0)
        this->setXDir(-s);

    if (this->getYDir()>0)
        this->setYDir(s);
    else if (this->getYDir()<0)
        this->setYDir(-s);
}
