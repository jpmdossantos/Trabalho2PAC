#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QToolBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mouseMoveEvent(QMouseEvent *event);
public slots:
    void start();
    void pause();
    void reset();
    void exit();
    void updateStatus();




private:
    Ui::MainWindow *ui;
    QAction *Start;
    QAction *Pause;
    QAction *Demo;
    QAction *Open;
    QAction *Save;
    QToolBar *toolbar;




};

#endif // MAINWINDOW_H
