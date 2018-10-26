#ifndef BALL_H
#define BALL_H

#pragma once

#include <QImage>
#include <QRectF>
#include <QObject>

class Ball : public QObject {
 Q_OBJECT
  public:
    explicit Ball(QObject *parent = nullptr);
    ~Ball();

  public:
    void resetState();
    void autoMove();
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRectF getRect();
    QImage & getImage();
     void updateSpeed(int);

  private:
    int xdir;
    int ydir;
    QImage image;
    QRectF rect;
    static const int INITIAL_X = 10;
    static const int INITIAL_Y = 200;
    static const int RIGHT_EDGE = 500;
    static const int BOTTOM_EDGE = 400;
signals:
    void kick(int);

};

#endif // BALL_H
