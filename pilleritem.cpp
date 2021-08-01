#include "pilleritem.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QDebug>

PillerItem::PillerItem() :
    topPiller(new QGraphicsPixmapItem(QPixmap(":/images/piller_up.png"))),
    bottomPiller(new QGraphicsPixmapItem(QPixmap(":/images/piller_down.png")))
{

    topPiller->setPos(QPointF(0,0) - QPointF(topPiller->boundingRect().width()/2, topPiller->boundingRect().height() + 60));

    bottomPiller->setPos(QPointF(0,0) + QPointF(-bottomPiller->boundingRect().width()/2, 60));

    addToGroup(topPiller);
    addToGroup(bottomPiller);

    yPos = QRandomGenerator::global()->bounded(150);
    int xRandomiser = QRandomGenerator::global()->bounded(200);

    setPos(QPoint(0,0) +QPoint(260 + xRandomiser, yPos));


    xAnimation = new QPropertyAnimation(this, "x", this);
    xAnimation->setStartValue(260 + xRandomiser);
    xAnimation->setEndValue(-260);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(1500);

    connect(xAnimation, &QPropertyAnimation::finished, [=](){
        qDebug() << "Animation finished";
        scene()->removeItem(this);
        delete this;
    });

    xAnimation->start();



}

PillerItem::~PillerItem()
{
    qDebug() << "Deleting pillar";

}

qreal PillerItem::x() const
{
    return m_x;
}

void PillerItem::setX(qreal x)
{
    qDebug() << "Pillar position : " << x;
    m_x = x;
    setPos(QPointF(0,0) + QPointF(x, yPos));
}
