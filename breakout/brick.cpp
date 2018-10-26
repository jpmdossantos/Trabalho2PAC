#include <iostream>
#include "brick.h"
#include <QDebug>

Brick::Brick(int x, int y) {

  image.load(":/images/brick.png");
  destroyed = false;
  rect = image.rect();
  rect.translate(x, y);

}

Brick::~Brick() {

  std::cout << ("Brick deleted") << std::endl;

}

QRectF Brick::getRect() {

  return rect;
}

void Brick::setRect(QRectF rct) {

  rect = rct;
}

QImage & Brick::getImage() {

  return image;
}


bool Brick::isDestroyed() {

  return destroyed;
}

void Brick::setDestroyed(bool destr) {

  destroyed = destr;
}
