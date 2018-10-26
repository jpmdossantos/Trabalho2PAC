#ifndef BREAKOUT_H
#define BREAKOUT_H

#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include <QObject>
#include<QMediaPlayer>

class Breakout : public QWidget {
  Q_OBJECT

  public:
    Breakout(QWidget *parent = 0);
    ~Breakout();
    void startGame();
    void resetGame();
    void pauseGame();
    Ball *ball;
    Paddle *paddle;
    int num_bricks = N_OF_BRICKS;
    void changeHit();
    bool getHit();

    QPointF getBallPosit();
    int getScore1();
    int getScore2();
    QPoint getPaddleposit1();
    QPoint getPaddleposit2();
    void setScore1(int);
    void setScore2(int);
    int getnballs();



    int getSpeed();

  protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void drawObjects(QPainter *);
    void finishGame(QPainter *, QString);
    void moveObjects();



    void stopGame();
    void resumeGame();
    void victory();
    void checkCollision();

  private:
    int x;
    int timerId;
    int speed;
    bool hit;
    bool hitFlag;
    int chance;
    static const int N_OF_BRICKS = 30;
    static const int N_OF_BALLS = 3;
    static const int DELAY = 10;
    static const int BOTTOM_EDGE = 400;
    static const int N_OF_COLISSION=2;
    static const int MAX_SPEED=3;
    static const int MIN_SPEED=1;
    //Ball *ball;
    //Paddle *paddle;
    int scoreP1;
    int scoreP2;
    Brick *bricks[N_OF_BRICKS];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    bool alive;
    bool listed;
    bool demo;
    bool turn;
    int n_balls = N_OF_BALLS;
    int brick_counter[N_OF_BRICKS];
    QMediaPlayer *player,*background_music;

    signals:
        void NballsChanged(QString);
        void BrickDestroyed(QString);
        void LevelChanged(QString);
        void showAtributos();
        void hideAtributos();
        int speedChanged(int);
        void update();
    public slots:
        void setSpeed(int);
        void changeScore(int);
};

#endif // BREAKOUT_H
