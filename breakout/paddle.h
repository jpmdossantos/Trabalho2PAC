#ifndef PADDLE_H
#define PADDLE_H

#pragma once

#include <QImage>
#include <QRect>

class Paddle {

  public:
    Paddle();
    ~Paddle();

  public:
    void resetState();
    void move();
    void movemouse(int);
    void setDy(int);
    void setDy2(int);
    int getDy();
    int getDy2();
    QRect getRect();
    QRect getRect2();
    QImage & getImage();
    QImage & getImage2();

  private:
    QImage image;
    QRect rect;
    QImage image2;
    QRect rect2;
    int dy;
    int dy2;
    static const int INITIAL_X = 0;
    static const int INITIAL_Y = 180;
    static const int INITIAL_X2 = 492;
    static const int INITIAL_Y2 = 200;
    static const int RIGHT_EDGE = 300;
};



#endif // PADDLE_H
