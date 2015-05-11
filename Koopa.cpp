#include "Koopa.h"

#include "GFX.h"
#include "GVC.h"
#include <cmath>

Koopa::Koopa()
{
    Enemy::spriteNumber = 3;
    resetSpeed();
    type = 0;
}

Koopa::~Koopa()
{
    //dtor
}

void Koopa::collidePlayer(Player& player)
{
    if(!able || player.getDead()) return;

//se colide com o player
    if(position.getY() <= player.getPosition().getY() + player.getHeight()&&
       position.getX() <= player.getPosition().getX() + player.getWidth() &&
       position.getX() + width >= player.getPosition().getX()&&
       position.getY() + height >= player.getPosition().getY())
    {
        //se o player colide na parte de cima do inimigo
        if(((player.getPosition().getX() + player.getWidth()) - position.getX()) >
            ((player.getPosition().getY() + player.getHeight()) - position.getY()))
        {
            dead = true;
            al_stop_sample_instance(GFX::kickInstance);
            al_play_sample_instance(GFX::kickInstance);
            player.setFall(false);
            player.jump();
            player.setHoldJump(true);
            player.setJumpTimer();
        }
        else{
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
}

void Koopa::resetSpeed()
{
    setSpeed(-0.02,0);
}

void Koopa::draw()
{
    if(dead)
    {
        al_draw_bitmap(GFX::koopared0,position.getX(),position.getY(),0);
        width = al_get_bitmap_width(GFX::koopared0);
        height = al_get_bitmap_height(GFX::koopared0);
    }
    else
    {
        if(spriteRun==0)
        {
            al_draw_bitmap(GFX::koopared1,position.getX(),position.getY(),0);
            width = al_get_bitmap_width(GFX::koopared1);
            height = al_get_bitmap_height(GFX::koopared1);
        }
        if(spriteRun==1)
        {
            al_draw_bitmap(GFX::koopared2,position.getX(),position.getY(),0);
            width = al_get_bitmap_width(GFX::koopared2);
            height = al_get_bitmap_height(GFX::koopared2);
        }
        if(spriteRun==2)
        {
            al_draw_bitmap(GFX::koopared1,position.getX(),position.getY(),0);
            width = al_get_bitmap_width(GFX::koopared1);
            height = al_get_bitmap_height(GFX::koopared1);
        }
    }
}

void Koopa::update(Player& player, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3)
{
    if(!locked)
    {
        //speed with gravity update
        ObjectInGame::update();

        if(!dead)
        {
            fall = true;
        }

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
