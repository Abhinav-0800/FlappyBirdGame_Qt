#include "birditem.h"
#include <QTimer>

BirdItem::BirdItem(QPixmap pixmap) :
    wingPosition(WingPosition::Up),
    wingDirection(0)
{
    setPixmap(pixmap);

    QTimer * birdWingsTimer = new QTimer(this);
    connect(birdWingsTimer, &QTimer::timeout, [=](){
       updatePixmap();
    });

    birdWingsTimer->start(80);
}

void BirdItem::updatePixmap()
{
    if(wingPosition == WingPosition::Up){

        setPixmap(QPixmap(":/images/bird_yellow_up1.png"));
        wingPosition = WingPosition::Down;
    }
    else{
        setPixmap(QPixmap(":/images/bird_yellow_down1.png"));
        wingPosition = WingPosition::Up;
    }

}
