#ifndef PILLERITEM_H
#define PILLERITEM_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include<QPropertyAnimation>

class PillerItem : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX NOTIFY xChanged)

public:
    explicit PillerItem();
    ~ PillerItem();

    qreal x() const;
signals:

public slots:

    void setX(qreal x);

private:
    QGraphicsPixmapItem * topPiller;
    QGraphicsPixmapItem * bottomPiller;
    QPropertyAnimation * xAnimation;
    int yPos;

    qreal m_x;
};

#endif // PILLERITEM_H
