#include "Spiker.h"

#include "GFX.h"
#include "GVC.h"
#include <cmath>

Spiker::Spiker()
{
    Enemy::spriteNumber = 2;
    resetSpeed();
    type = 1;
}

Spiker::~Spiker()
{
}

void Spiker::collidePlayer(Player& player)
{
    if(!able || player.getDead()) return;
//se colide com o player
    if(position.getY() <= player.getPosition().getY() + player.getHeight()&&
       position.getX() <= player.getPosition().getX() + player.getWidth() &&
       position.getX() + width >= player.getPosition().getX()&&
       position.getY() + height >= player.getPosition().getY())
    {
        if(player.getFlyingCounter() == 0)
        {
            player.looseLife();
        }
        else
        {
            player.setLife(2);
            player.looseFeather();
        }

        able = false;
        if(GVC::gameSpeed < -3 )
        {
        GVC::gameSpeed += 2;
        }

    }
}

void Spiker::resetSpeed()
{
    setSpeed(-0.01,0);
}

void Spiker::draw()
{
    if(!fall)
    {
        if(spriteRun==0)
        {
            al_draw_bitmap(GFX::spiker0,position.getX(),position.getY(),0);
            width = al_get_bitmap_width(GFX::spiker0);
            height = al_get_bitmap_height(GFX::spiker0);
        }
        if(spriteRun==1)
        {
            al_draw_bitmap(GFX::spiker1,position.getX(),position.getY(),0);
            width = al_get_bitmap_width(GFX::spiker1);
            height = al_get_bitmap_height(GFX::spiker1);
        }
    }
    else
    {
        if(spriteRun==0)
        {
            al_draw_bitmap(GFX::spiker2,position.getX(),position.getY(),0);
            width = al_get_bitmap_width(GFX::spiker2);
            height = al_get_bitmap_height(GFX::spiker2);
        }
        if(spriteRun==1)
        {
            al_draw_bitmap(GFX::spiker3,position.getX(),position.getY(),0);
            width = al_get_bitmap_width(GFX::spiker3);
            height = al_get_bitmap_height(GFX::spiker3);
        }
    }
}

void Spiker::update(Player& player, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3)
{
    if(!locked)
    {
        //speed with gravity update
        ObjectInGame::update();

        fall = true;

        collidePlayer(player);
        collidePlatform(plataforma1);
        collidePlatform(plataforma2);
        collidePlatform(plataforma3);

        calcSpriteSpeed();

        if(dead)
        {
            speed.setX(0);
        }
    }
}
