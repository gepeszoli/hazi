#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QPushButton>
#include <QtGui>
#include "ship.h"
#include <string>
#include <sstream>

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
public slots:
    void fireClicked(){}
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
private:
    QPushButton *buttonFire;
    bool AllShipsPlaced;
    int forcedHeight, forcedWidth;
    int fireX,fireY,pFireX,pFireY;
    int homeX,homeY;
    int enemyX,enemyY;
    void drawWeb( QPainter &painter, int x, int y, int width, int number);
    void drawFire( int x, int y);
    void drawShip( Ship& ship);
};


#endif // GAMEWINDOW_H
