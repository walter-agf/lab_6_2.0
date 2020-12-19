#include "cuerpograf.h"

cuerpograf::cuerpograf(float x, float y, float vx, float vy, float m, float r):escala(0.05)
{
    esf = new cuerpo(x,y,vx,vy,m,r);
}

QRectF cuerpograf::boundingRect() const
{
    return QRectF(escala*esf->getR(),escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    if (color == "rojo") painter->setBrush(Qt::red);
//    else if (color == "amarillo") painter->setBrush(Qt::yellow);
//    else if (color == "verde") painter->setBrush(Qt::green);
//    else if (color == "azul") painter->setBrush(Qt::blue);
//    else if (color == "magenta") painter->setBrush(Qt::magenta);
//    else if (color == "blanco") painter->setBrush(Qt::white);
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void cuerpograf::setEscala(float s)
{
    escala = s;
}

void cuerpograf::actualizar(float dt)
{
    esf->actualizar(dt);
    setPos(esf->getPX()*escala,-1*esf->getPY()*escala);
}

void cuerpograf::guardar_datos(string datos)
{
    fstream k("Ensayo.txt",fstream::out); // Se crea el archivo o se abre en modo escritura
    k << datos;
    k.close();
}

cuerpo *cuerpograf::getEsf()
{
    return esf;
}
