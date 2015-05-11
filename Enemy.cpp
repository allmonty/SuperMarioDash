#include "Enemy.h"

#include "GVC.h"
#include <cmath>

Enemy::Enemy():able(true), locked(true), dead(false), fall(true),type(0),
                spriteNumber(0),spriteCount(0.0),spriteRun(0.0)
{
}

Enemy::~Enemy()
{
}

void Enemy::calcSpriteSpeed()
{
    spriteCount += GVC::gameSpeed + speed.getX();
    if(abs(spriteCount) > width)
    {
        spriteCount = 0;
        spriteRun++;
        spriteRun = fmod(spriteRun,spriteNumber);
    }
}

void Enemy::collidePlatform(Plataforma& visado)
{
    if(!fall) return;

//se colide com a plataforma
    if(position.getY() + height >= visado.getPosition().getY() &&
       position.getX()  + width >= visado.getPosition().getX() &&
       position.getX() <= visado.getPosition().getX() + visado.getWidth()&&
       position.getY() < visado.getPosition().getY() + visado.getHeight())
    {
    //se colide na lateral esquerda da plataforma = frente
        if(((position.getX() + width) - visado.getPosition().getX()) <= ((position.getY() + height) - visado.getPosition().getY()))
        {
            //2 eh um numero arbitrario para uma aproximacao de rebatida - ficou razoavel assim
            setSpeed(visado.getSpeed().getX() * 2, speed.getY() + GVC::gravity->getY());
        }
        else{
        //se colide na lateral direita da plataforma
            if(((visado.getPosition().getX() + visado.getWidth()) - position.getX()) <= ((visado.getPosition().getY() + visado.getHeight()) - position.getY()))
            {
                //2 eh um numero arbitrario para uma aproximacao de rebatida - ficou razoavel assim
                setSpeed(visado.getSpeed().getX() * -2, speed.getY() + GVC::gravity->getY());
            }
            else
            {
                fall = false;
                setPosition(position.getX() + speed.getX(), visado.getPosition().getY() - height);
                resetSpeed();
                speed.setX(visado.getSpeed().getX() + speed.getX());
            }
        }
    }
}

void Enemy::setAble(bool _able)
{
    able = _able;
}

void Enemy::setLocked(bool _locked)
{
    locked = _locked;
}

void Enemy::setDead(bool _dead)
{
    dead = _dead;
}

bool Enemy::getAble()
{
    return able;
}

bool Enemy::getLocked()
{
    return locked;
}

int Enemy::getType()
{
    return type;
}

void Enemy::collidePlayer(Player& player){};
void Enemy::resetSpeed(){};
void Enemy::draw(){}
void Enemy::update(Player& player, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3){}
