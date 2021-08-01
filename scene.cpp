#include "scene.h"

scene::scene(QObject *parent) : QGraphicsScene(parent)
{
    setUpPillerTimer();
}

void scene::setUpPillerTimer()
{
    pillerTimer = new QTimer(this);
    connect(pillerTimer, &QTimer::timeout,[=](){

        PillerItem * pillerItem = new PillerItem();

        addItem(pillerItem);
    });

    pillerTimer->start(1000);

}
