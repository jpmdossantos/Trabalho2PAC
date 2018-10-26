#include <iostream>
#include "paddle.h"
#include <QMatrix>

Paddle::Paddle() {

  dy = 0;
  image.load(":/images/paddle.png");
  image2.load(":/images/paddle2.png");

  QMatrix Noventa;
  QMatrix mNoventa;
  Noventa.rotate(90);
  image = image.transformed(Noventa);
  rect = image.rect();
  mNoventa.rotate(270);
  image2 = image2.transformed(mNoventa);
  rect2 = image2.rect();
  resetState();
}

Paddle::~Paddle() {

 std::cout << ("Paddle deleted") << std::endl;
}

void Paddle::setDy(int y) {
  dy = y;
}


void Paddle::setDy2(int y) {
  dy2 = y;
}
int Paddle::getDy(){
    return dy;
}
int Paddle::getDy2(){
    return dy2;
}
void Paddle::move() {

    int y = rect.y() + dy;
    int x = rect.x();
    if ( (340 > y) && (y > 0))
    rect.moveTo(x, y);

    y = rect2.y() + dy2;
    x = rect2.x();
    if ( (340 > y) && (y > 0))
    rect2.moveTo(x, y);

}

void Paddle::movemouse(int y){

    int x = rect2.x();
    if ((340 > y) && (y > 0))
    rect2.moveTo(x,y);
}

void Paddle::resetState() {

  rect.moveTo(INITIAL_X, INITIAL_Y);
  rect2.moveTo(INITIAL_X2,INITIAL_Y2);
}

QRect Paddle::getRect() {

  return rect;
}

QRect Paddle::getRect2() {

  return rect2;
}

QImage & Paddle::getImage() {

  return image;
}

QImage & Paddle::getImage2() {

  return image2;
}
