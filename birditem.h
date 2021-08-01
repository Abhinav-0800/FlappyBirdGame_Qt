#ifndef BIRDITEM_H
#define BIRDITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class BirdItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit BirdItem(QPixmap pixmap);

signals:

public slots:
private:

    enum WingPosition{
        Up,
        Down
    };

    void updatePixmap();

    WingPosition wingPosition;
    bool wingDirection; // 0 - down, 1 - up
};

#endif // BIRDITEM_H
