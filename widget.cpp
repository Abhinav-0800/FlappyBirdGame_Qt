#include "widget.h"
#include "ui_widget.h"
#include "QGraphicsPixmapItem"
#include "birditem.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Scene = new scene(this);
    Scene->setSceneRect(-250,-300,500,600);

    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/images/flappybird_bg.png"));
    Scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) - QPointF(pixItem->boundingRect().width()/2, pixItem->boundingRect().height()/2));

    Scene->addLine(-400,0,400,0, QPen(Qt::blue));
    Scene->addLine(0,-400,0,400, QPen(Qt::blue));

//    PillerItem * piller = new PillerItem();
//    Scene->addItem(piller);

    BirdItem * bird = new BirdItem(QPixmap(":/images/bird_yellow_up1.png"));
    Scene->addItem(bird);


    ui->graphicsView->setScene(Scene);
}

Widget::~Widget()
{
    delete ui;
}

