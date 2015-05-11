#include "PowerUps.h"

#include "GVC.h"

PowerUps::PowerUps():able(true),fall(true),locked(true)
{
    //ctor
}

PowerUps::~PowerUps()
{
    //dtor
}


void PowerUps::collidePlatform(Plataforma& visado)
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

void PowerUps::collidePlayer(Player& player)
{
    if(!able || player.getDead()) return;

//se colide com o player
    if(position.getY() <= player.getPosition().getY() + player.getHeight()&&
       position.getX() <= player.getPosition().getX() + player.getWidth() &&
       position.getX() + width >= player.getPosition().getX()&&
       position.getY() + height >= player.getPosition().getY())
    {
        makeEffect(player);
        able = false;
    }
}

void PowerUps::setAble(bool _able)
{
    able = _able;
}

void PowerUps::setLocked(bool _locked)
{
    locked = _locked;
}

bool PowerUps::getLocked()
{
    return locked;
}

void PowerUps::resetSpeed(){}
void PowerUps::makeEffect(Player& player){};
void PowerUps::update(Player& players, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3){};
void PowerUps::draw(){};

