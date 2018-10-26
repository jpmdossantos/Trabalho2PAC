#include <QPainter>
#include <QApplication>
#include "breakout.h"
#include <iostream>
#include <QMatrix>
#include <QtMath>
#include <time.h>
#include <stdlib.h>

Breakout::Breakout(QWidget *parent)
    : QWidget(parent) {

  player = new QMediaPlayer;
  background_music = new QMediaPlayer;
  background_music->setMedia(QUrl("qrc:/sounds/Space_Shooter_Theme_Music_1.mp3"));
  background_music->setVolume(100);
  background_music->play();
  player->setMedia(QUrl("qrc:/sounds/hit_effect.mp3"));
  //player->setMedia(QUrl("qrc:/sounds/musica.mp3")
  player->setVolume(50);
  x = 0;
  hit = true;
  gameOver = false;
  gameWon = false;
  paused = false;
  listed = false;
  alive=false;
  gameStarted = false;
  chance = 0;
  paddle = new Paddle();
  hitFlag=false;
  demo = false;
  turn = false;
    scoreP1 = 0;
    scoreP2 = 0;
 ball = new Ball;
  int k = 0;
  this->speed=1;  
  connect(ball,SIGNAL(kick(int)),this,SLOT(changeScore(int)));

  for (int i=0; i<5; i++) {
    for (int j=0; j<6; j++) {
      bricks[k] = new Brick( (i)*21 +198, (j)*41 +77);
      brick_counter[k]=0;
      k++;
    }
  }
  srand (time(NULL));

}

Breakout::~Breakout() {

 delete ball;
 delete paddle;

 for (int i=0; i<N_OF_BRICKS; i++) {
   delete bricks[i];
 }
}

void Breakout::setSpeed(int spd){
    this->speed = spd;
    this->ball->updateSpeed(spd);
}

int Breakout::getSpeed()
{
    return this->speed;
}

void Breakout::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);

  QPainter painter(this);

  if (gameOver) {

    finishGame(&painter, "Game lost");

  } else if(gameWon) {

    finishGame(&painter, "Victory");
  }
  else {

    drawObjects(&painter);
  }
}

void Breakout::finishGame(QPainter *painter, QString message) {

  QFont font("Courier", 15, QFont::DemiBold);
  QFontMetrics fm(font);
  int textWidth = fm.width(message);

  painter->setFont(font);
  int h = height();
  int w = width();

  painter->translate(QPoint(w/2, h/2));
  painter->drawText(-textWidth/2, 0, message);
}

void Breakout::drawObjects(QPainter *painter) {
  QPoint topl(0,0);
  QPoint botr(500,400);
  QRect Backg(topl,botr);

  painter->setBrush(Qt::black);
  painter->drawRect(0,0,500,400);
  painter->setBrush(Qt::NoBrush);
  painter->drawImage(ball->getRect(), ball->getImage());
  painter->drawImage(paddle->getRect(), paddle->getImage());
  painter->drawImage(paddle->getRect2(), paddle->getImage2());

  for (int i=0; i<N_OF_BRICKS; i++) {
    if (!bricks[i]->isDestroyed()) {
      painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
    }
  }
}

void Breakout::timerEvent(QTimerEvent *e) {

  Q_UNUSED(e);
if (this->demo){
     if (this->ball->getRect().x()>=303 && !this->hitFlag)
     {
         this->changeHit();
         this->hitFlag=true;
     }
     if (this->ball->getRect().x()<303 && this->hitFlag)
     {
         this->hitFlag=false;
     }

        if (this->hit)
        {

            if (this->paddle->getRect2().center().y() > this->ball->getRect().center().y())
                {
                this->paddle->setDy2(-this->speed);
                }
            else if(this->paddle->getRect2().center().y() < this->ball->getRect().center().y())
                  {
                    this->paddle->setDy2(this->speed);
                  }
            else
                   {
                  this->paddle->setDy2(0);
                 }
        }

        else
        {
            if(this->paddle->getRect2().top()-20> this->ball->getRect().top())
               {
                this->paddle->setDy2(-this->speed);
               }
            else if (this->paddle->getRect2().bottom()+20 < this->ball->getRect().bottom())
                {
                    this->paddle->setDy2(this->speed);
                }
            else
            {
                if(this->paddle->getRect2().center().y() < this->ball->getRect().center().y())
                    this->paddle->setDy2(-this->speed);
                else
                    this->paddle->setDy2(this->speed);
            }


        }

}

            if (this->ball->getRect().x()<=197 && !this->hitFlag)
            {
                this->changeHit();
                this->hitFlag=true;
            }
            if (this->ball->getRect().x()>197 && this->hitFlag)
            {
                this->hitFlag=false;
            }

               if (this->hit)
               {

                   if (this->paddle->getRect().center().y() > this->ball->getRect().center().y())
                       {
                       this->paddle->setDy(-this->speed);
                       }
                   else if(this->paddle->getRect().center().y() < this->ball->getRect().center().y())
                         {
                           this->paddle->setDy(this->speed);
                         }
                   else
                          {
                         this->paddle->setDy(0);
                        }
               }

               else
               {
                   if(this->paddle->getRect().top()-20> this->ball->getRect().top())
                      {
                       this->paddle->setDy(-this->speed);
                      }
                   else if (this->paddle->getRect().bottom()+20 < this->ball->getRect().bottom())
                       {
                           this->paddle->setDy(this->speed);
                       }
                   else
                   {
                       if(this->paddle->getRect().center().y() < this->ball->getRect().center().y())
                           this->paddle->setDy(-this->speed);
                       else
                           this->paddle->setDy(this->speed);
                   }


               }




    if(listed){
        moveObjects();
        checkCollision();
        repaint();
        pauseGame();
        emit showAtributos();
        listed=false;
    }else{

      moveObjects();
      checkCollision();
      repaint();
    }

emit update();
}

void Breakout::moveObjects() {

  ball->autoMove();
  paddle->move();
}

void Breakout::keyReleaseEvent(QKeyEvent *e) {

    int dy = 0;

    switch (e->key()) {
        case Qt::Key_Down:
            dy = 0;
            paddle->setDy(dy);
            break;

        case Qt::Key_Up:
            dy = 0;
            paddle->setDy(dy);
            break;
    }
}
void Breakout::mousePressEvent(QMouseEvent *e)
{

    if(e->buttons() == Qt::LeftButton){
        qDebug("left mouse press");
        pauseGame();
    }else
        if(e->buttons() == Qt :: RightButton){
        qDebug("right mouse press");
        if(!listed){
            pauseGame();
            emit showAtributos();
            listed=true;
        }else{
            pauseGame();
            emit hideAtributos();
            //listed=false;
        }

    }
}



void Breakout::keyPressEvent(QKeyEvent *e) {

    int dy = 0;

    switch (e->key()) {
    case Qt::Key_Up:

        dy = -1;
        paddle->setDy2(dy);

        break;

    case Qt::Key_Down:

        dy = 1;
        paddle->setDy2(dy);
        break;

    case Qt::Key_P:
        if(gameStarted){
            pauseGame();
            break;
        }else{
            break;
        }

    case Qt::Key_Space:


            startGame();
            break;

    case Qt::Key_B:
        victory();
        break;

    case Qt::Key_Q:

        qApp->exit();
        break;
    case Qt::Key_R:
        resetGame();
        break;

    default:
        QWidget::keyPressEvent(e);
    }
}

void Breakout::startGame() {

    if (!gameStarted) {
      ball->resetState();
      paddle->resetState();

      for (int i=0; i<N_OF_BRICKS; i++) {
        bricks[i]->setDestroyed(false);
      }

    gameOver = false;
    gameWon = false;
    gameStarted = true;
    alive=true;
    timerId = startTimer(DELAY);
    emit NballsChanged(QString::number(n_balls));
  }
}
void Breakout::resetGame() {

    //killTimer(timerId);
    //gameOver = true;
    //gameStarted = false;
    ball->resetState();
    paddle->resetState();


    if(!alive){
        speed=1;
    }

    gameStarted = false;
    gameOver = false;
    gameWon = false;

    moveObjects();
    checkCollision();
    repaint();
    killTimer(timerId);
    /*
    moveObjects();
    checkCollision();
    repaint();*/

   // killTimer(timerId); ja e usado antes de chamar essa função
}

void Breakout::pauseGame() {

  if (paused) {
    background_music->play();
    timerId = startTimer(DELAY);
    paused = false;
    emit hideAtributos();
  } else {
    background_music->pause();
    paused = true;
    killTimer(timerId);
  }
}

void Breakout::stopGame() {

  killTimer(timerId);
  std::cout<<"Bolas disponíveis: "<<n_balls<<std::endl;
  emit NballsChanged(QString::number(n_balls));
  if(n_balls<=0){
      gameOver = true;
      gameStarted = false;
      n_balls = N_OF_BALLS;
      alive=false;

  }else{
      alive=true;
      gameStarted=true;
      resetGame();

  }
}
void Breakout::resumeGame(){

    ball->resetState();
    paddle->resetState();
    gameOver = false;
    gameWon = false;
    gameStarted=true;


    timerId = startTimer(DELAY);

}

void Breakout::victory() {

  killTimer(timerId);
  gameWon = true;
  gameStarted = false;
  resetGame();
}

void Breakout::changeHit()
{
        int chance = rand() %10 + 1;
        if (chance < 1)
            this->hit = true;
        else
            this->hit=false;

        qDebug()<<this->hit;

}

bool Breakout::getHit()
{
    return this->hit;
}
void Breakout::checkCollision() {

  if (ball->getRect().left() < 1) {
      this->scoreP1 +=-10;
 //   stopGame();
  }
  else if (ball->getRect().right() > 499)
  {
      this->scoreP2 +=-10;
  }

  for (int i=0, j=0; i<N_OF_BRICKS; i++) {

    if (bricks[i]->isDestroyed()) {
      j++;
    }

    if (j == N_OF_BRICKS) {
      victory();
    }
  }

  if ((ball->getRect()).intersects(paddle->getRect())) {
    this->turn = false;

    int paddleLPos = paddle->getRect().top();
    int ballLPos = ball->getRect().top();

    int first = paddleLPos + 12;
    int second = paddleLPos + 24;
    int third = paddleLPos + 36;
    int fourth = paddleLPos + 48;

    if (ballLPos < first) {
      ball->setXDir(speed);
      ball->setYDir(-speed);
    }

    if (ballLPos >= first && ballLPos < second) {
      ball->setXDir(speed);
      ball->setYDir(-speed);
      if (ball->getXDir()<=0)
          ball->setXDir(speed);
    }

    if (ballLPos >= second && ballLPos < third) {
       ball->setXDir(speed);
       ball->setYDir(0);
    }

    if (ballLPos >= third && ballLPos < fourth) {
       ball->setXDir(speed);
       ball->setYDir(speed);
       if (ball->getXDir()<=0)
           ball->setXDir(speed);
    }

    if (ballLPos > fourth) {
      ball->setXDir(speed);
      ball->setYDir(speed);
    }
  }

  if ((ball->getRect()).intersects(paddle->getRect2())) {
    this->turn = true;

    int paddleLPos = paddle->getRect2().top();
    int ballLPos = ball->getRect().top();

    int first = paddleLPos + 12;
    int second = paddleLPos + 24;
    int third = paddleLPos + 36;
    int fourth = paddleLPos + 48;

    if (ballLPos < first) {
      ball->setXDir(-speed);
      ball->setYDir(-speed);
    }

    if (ballLPos >= first && ballLPos < second) {
      ball->setXDir(-speed);
      ball->setYDir(-speed);
      if (ball->getXDir()>=0)
          ball->setXDir(-speed);
    }

    if (ballLPos >= second && ballLPos < third) {
       ball->setXDir(-speed);
       ball->setYDir(0);
    }

    if (ballLPos >= third && ballLPos < fourth) {
       ball->setXDir(-speed);
       ball->setYDir(speed);
       if (ball->getXDir()>=0)
           ball->setXDir(-speed);
    }

    if (ballLPos > fourth) {
      ball->setXDir(-speed);
      ball->setYDir(speed);
    }
  }
  for (int i=0; i<N_OF_BRICKS; i++) {

    if ((ball->getRect()).intersects(bricks[i]->getRect())) {


      int ballLeft = ball->getRect().left();
      int ballHeight = ball->getRect().height();
      int ballWidth = ball->getRect().width();
      int ballTop = ball->getRect().top();
      int ballBottom = ball->getRect().bottom();
      int ballRight = ball->getRect().right();

      QPoint pointRight(ballLeft + ballWidth + 1, ballTop + ballHeight/2);
      QPoint pointLeft(ballLeft - 1, ballTop + ballHeight/2);
      QPoint pointTop(ballLeft + ballWidth/2, ballTop -1);
      QPoint pointBottom(ballLeft + ballWidth/2, ballTop + ballHeight + 1);

      QPoint pointTopRight(ballRight - ballWidth *(2- qSqrt(2)) / 4 + 1, ballTop + ballHeight * (2-qSqrt(2))/4 -1);
      QPoint pointTopLeft(ballLeft + ballWidth *(2- qSqrt(2)) / 4 - 1, ballTop + ballHeight * (2-qSqrt(2))/4 -1);
      QPoint pointBottomLeft(ballLeft + ballWidth *(2- qSqrt(2)) / 4 - 1 , ballBottom - ballHeight * (2-qSqrt(2))/4 + 1);
      QPoint pointBottomRight(ballRight - ballWidth *(2- qSqrt(2)) / 4 + 1, ballBottom - ballHeight * (2-qSqrt(2))/4 + 1);

      bool changedFlag = false;


      if (!bricks[i]->isDestroyed()) {
        if(bricks[i]->getRect().contains(pointRight)) {
           ball->setXDir(-speed);
           changedFlag = true;

           qDebug()<<"Direita"<<endl;
        }

        else if(bricks[i]->getRect().contains(pointLeft)) {
           ball->setXDir(speed);
           changedFlag = true;
           qDebug()<<"Esquerda"<<endl;
        }

        if(bricks[i]->getRect().contains(pointTop)) {
           ball->setYDir(speed);
           changedFlag = true;
           qDebug()<<"Topo"<<endl;
        }

        else if(bricks[i]->getRect().contains(pointBottom)) {
           ball->setYDir(-speed);
           changedFlag = true;
           qDebug()<<"Baixo"<<endl;
        }


        if (!changedFlag)
        {
            if(bricks[i]->getRect().contains(pointTopRight)) {
               ball->setXDir(-speed);
               ball->setYDir(speed);
               changedFlag = true;
               qDebug()<<"TopoDireita"<<endl;
            }

            else if(bricks[i]->getRect().contains(pointTopLeft)) {
                ball->setXDir(speed);
                ball->setYDir(speed);
                changedFlag = true;
                qDebug()<<"TopoEsquerda"<<endl;
            }

            else if(bricks[i]->getRect().contains(pointBottomRight)) {
                ball->setXDir(-speed);
                ball->setYDir(-speed);
                changedFlag = true;
                qDebug()<<"Baixo Direita"<<endl;
            }

            else if(bricks[i]->getRect().contains(pointBottomLeft)) {
                ball->setXDir(speed);
                ball->setYDir(-speed);
                changedFlag = true;
                qDebug()<<"Baixo Esquerdaa"<<endl;
            }
        }

        bricks[i]->setDestroyed(true);
        this->changeScore(2);

      }
    }
  }

}

QPointF Breakout::getBallPosit()
{
    QPointF posit = this->ball->getRect().center();
    return posit;
}
int Breakout::getScore1()
{
    return this->scoreP1;
}

int Breakout::getScore2()
{
    return this->scoreP2;
}

QPoint Breakout::getPaddleposit1()
{
    return this->paddle->getRect().center();
}
QPoint Breakout::getPaddleposit2()
{
    return this->paddle->getRect2().center();
}
void Breakout::setScore1(int p)
{
    this->scoreP1 += p;
}
void Breakout::setScore2(int p)
{
    this->scoreP2 += p;
}

int Breakout::getnballs()
{
    return this->n_balls;
}

void Breakout::changeScore(int s)
{
    if (!this->turn){
    this->scoreP1+=s;
    }
    else
    {
     this->scoreP2+=s;
}
}

