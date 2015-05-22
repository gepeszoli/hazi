#include "gamewindow.h"


GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent)
{
    forcedWidth = 940;
    forcedHeight = 600;
    homeX = 40;
    homeY = 80;
    enemyX = homeX+400+50;
    enemyY = 80;
    resize(forcedWidth, forcedHeight);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMaximumHeight(forcedHeight);
    this->setMinimumHeight(forcedHeight);
    this->setMinimumWidth(forcedWidth);
    this->setMaximumWidth(forcedWidth);
    this->setWindowTitle("Game");
    buttonFire = new QPushButton(this);
    buttonFire->setGeometry(homeX+385,homeY+440,80,40);
    buttonFire->setText("FIRE");
    connect(buttonFire,SIGNAL(clicked()),this,SLOT(fireClicked()) );
}

GameWindow::~GameWindow()
{
    delete buttonFire;
}

void GameWindow::paintEvent(QPaintEvent *){

        QPainter painter(this);
        QPen pen;
        // Label home territory
        pen.setColor(Qt::blue);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.setFont(QFont("Arial", 16));
        painter.drawText( homeX+150, 40, "Allied Waters");
        // Label enemy territory
        pen.setColor(Qt::red);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawText( enemyX+150, 40, "Enemy Waters");
        // Draw the seas
        pen.setColor(Qt::blue);
        QBrush brush;
        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::Dense4Pattern);
        painter.setBrush(brush);
        painter.setPen(pen);
        painter.drawRect( homeX, homeY, 400, 400);
        painter.drawRect( enemyX, enemyY, 400, 400);
        brush.setStyle(Qt::NoBrush);
        painter.setBrush(brush);
        // Draw webs on the seas
        drawWeb( painter, homeX, homeY, 80, 5);
        drawWeb( painter, enemyX, enemyY, 80, 5);
        drawFire( fireX, fireY);

        // Draw ships
        if( isServer ){
            Ship s = Ship( homeX, homeY, 3);
            s.blocks[1]=KILLED;
            drawShip(s);

        } else {
            Ship s = Ship( homeX, homeY, 3);
            drawShip(s);
        }

}

void GameWindow::mousePressEvent(QMouseEvent *event) {
    /* Check if in the enemy sea */
    int x = event->x();
    int y = event->y();
    // If the mouse was clicked in the enemy territory
    if( (x >= enemyX && y >= enemyY) && (x <= enemyX+400 && y <= enemyY+400) ) {
        fireX = x;
        fireY = y;
        this->update();
    }

}
void GameWindow::fireClicked() {
//    n = write(sockfd,&cmd,sizeof(cmd));
//    if (n < 0)
//        error("ERROR writing to socket");
//    bzero(buffer,256);
}

void GameWindow::drawWeb(QPainter &painter, int x, int y, int size, int number) {
    int i = 0;
    int j = 0;
    if( number < 1 ) {
        return;
    }
    for( i=0; i < number; i++) {
        for( j=0; j < number; j++ ) {
            painter.drawRect( x+i*size, y+j*size, size, size);
        }
    }
}
void GameWindow::drawFire( int x, int y) {
    QPainter painter(this);
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawEllipse( x,y, 60, 60);
}

void GameWindow::drawShip(Ship &ship) {
    QPainter painter(this);
    QBrush brush;
    for(int i=0; i<ship.size; i++) {
        if( ship.blocks[i] == HEALTHY ) {
            brush.setColor(Qt::black);
            brush.setStyle(Qt::SolidPattern);
        }
        else if( ship.blocks[i] == KILLED ) {
            brush.setColor(Qt::red);
            brush.setStyle(Qt::Dense4Pattern);
        }
        painter.setBrush(brush);
        painter.drawRect( ship.X+i*80, ship.Y+20, 80, 40);
    }
}
