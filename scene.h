#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <pilleritem.h>
#include <QTimer>

class scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit scene(QObject *parent = nullptr);

signals:

public slots:
private:
    void setUpPillerTimer();

    QTimer * pillerTimer;

};

#endif // SCENE_H
