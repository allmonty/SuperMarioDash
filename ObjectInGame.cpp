#include "ObjectInGame.h"

#include "GVC.h"

ObjectInGame::ObjectInGame():width(0),height(0),position(0,0),speed(0,0)
{

}

ObjectInGame::~ObjectInGame()
{
    //dtor
}

void ObjectInGame::setPosition(float x, float y)
{
    position = Vetor(x,y);
}

void ObjectInGame::setSpeed(float x, float y)
{
    speed = Vetor(x,y);
}

void ObjectInGame::setWidth(float w)
{
    width = w;
}

void ObjectInGame::setHeight(float h)
{
    height = h;

}

Vetor ObjectInGame::getPosition()
{
    return position;
}

Vetor ObjectInGame::getSpeed()
{
    return speed;
}

float ObjectInGame::getWidth()
{
    return width;
}

float ObjectInGame::getHeight()
{
    return height;
}

void ObjectInGame::update()
{
    speed.setX(speed.getX() + GVC::gravity->getX());
    speed.setY(speed.getY() + GVC::gravity->getY());
    position = position + speed;
}
