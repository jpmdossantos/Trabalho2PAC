#ifndef BRICK_H
#define BRICK_H

#pragma once

#include <QImage>
#include <QRectF>

class Brick {

  public:
    Brick(int, int);
    ~Brick();

  public:
    bool isDestroyed();
    void setDestroyed(bool);
    QRectF getRect();
    void setRect(QRectF);
    QImage & getImage();
    QImage & setImage(int);

  private:
    QImage image;
    QRectF rect;
    bool destroyed;
};

#endif // BRICK_H
