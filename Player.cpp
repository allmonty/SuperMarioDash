#include "Player.h"

#include "GFX.h"
#include "GVC.h"
#include "Allegro.h"
#include <cmath>

Player::Player():life(2),flyingCounter(0),dead(false),fall(true),jumping(true),flying(false),holdJump(false),jumpDuration(0.3),jumpTimer(0),spriteRun(0),spriteCount(0)
{
}

Player::~Player()
{
    //dtor
}

void Player::looseLife()
{
    if(life > 0)
    {
        life--;
    }
    if(life == 0)
    {
        dead = true;
        jump();
    }

    if(dead)
    {
        al_stop_sample_instance(GFX::lostalifeInstance);
        al_play_sample_instance(GFX::lostalifeInstance);
    }
    else
    {
        al_stop_sample_instance(GFX::injuryInstance);
        al_play_sample_instance(GFX::injuryInstance);
    }
}

void Player::setLife(int _life)
{
    life = _life;
}

int Player::getLife()
{
    return life;
}

void Player::fly()
{
    jumping = true;
    speed = Vetor(speed.getX(),-10);
    al_stop_sample_instance(GFX::caperiseInstance);
    al_play_sample_instance(GFX::caperiseInstance);
}

void Player::looseFeather()
{
    flyingCounter = 0;
    al_stop_sample_instance(GFX::spinInstance);
    al_play_sample_instance(GFX::spinInstance);
}

void Player::looseFlyingCounter()
{
    if(flyingCounter > 0)
    {
        flyingCounter--;
    }
}

void Player::setFlyingCounter(int _flyingCounter)
{
    flyingCounter = _flyingCounter;
}

int Player::getFlyingCounter()
{
    return flyingCounter;
}

void Player::setDead(bool _dead)
{
    dead = _dead;
}

bool Player::getDead()
{
    return dead;
}

void Player::setFall(bool _fall)
{
    fall = _fall;
}

bool Player::getFall()
{
    return fall;
}

void Player::setJumping(bool _jumping)
{
    jumping = _jumping;
}

bool Player::getJumping()
{
    return jumping;
}

void Player::setFlying(bool _flying)
{
    flying = _flying;
}

bool Player::getFlying()
{
    return flying;
}

void Player::jump()
{
    jumping = true;
    speed = Vetor(speed.getX(),-10);
    al_stop_sample_instance(GFX::jumpInstance);
    al_play_sample_instance(GFX::jumpInstance);
}

void Player::setHoldJump(bool hold)
{
    holdJump = hold;
}

bool Player::getHoldJump()
{
    return holdJump;
}

void Player::setJumpTimer()
{
    jumpTimer = clock();
}

float Player::getJumpTimer()
{
    return jumpTimer;
}

float Player::getJumpDuration()
{
    return jumpDuration;
}

void Player::colidePlataforma(Plataforma& visado)
{
    if(!fall) return;

//se colide com a plataforma
    if(position.getY() + height >= visado.getPosition().getY() &&
       position.getX()  + width >= visado.getPosition().getX() &&
       position.getX() <= visado.getPosition().getX() + visado.getWidth()&&
       position.getY() <= visado.getPosition().getY() + visado.getHeight())
    {
        //se colidir por baixo
        if(position.getX() <= visado.getPosition().getX() + visado.getWidth() &&
            position.getX() >= visado.getPosition().getX()&&
            height/2 > ((visado.getPosition().getY() + visado.getHeight()) - position.getY()))
        {
            position.setY(visado.getPosition().getY() + visado.getHeight());
            setSpeed( speed.getX(), 0.1);
            return;
        }
        //se colide na lateral esquerda da plataforma = frente
        if(((position.getX() + width) - visado.getPosition().getX()) <= ((position.getY() + height) - visado.getPosition().getY()))
        {
            //2 eh um numero arbitrario para uma aproximacao de rebatida - ficou razoavel assim
            setSpeed(visado.getSpeed().getX() * 2, speed.getY() + GVC::gravity->getY());
        }
        else{
            fall = false;
            jumping = false;
            flying = false;
            setPosition(position.getX() , visado.getPosition().getY() - height);
            setSpeed(speed.getX(), 0);
        }
    }
}

void Player::calcSpriteSpeed()
{
    spriteCount += GVC::gameSpeed;
    if(abs(spriteCount) > width)
    {
        spriteCount = 0;
        spriteRun++;
        spriteRun = fmod(spriteRun,4);
    }
}

void Player::update()
{
    ObjectInGame::update();

    if(flying && flyingCounter > 0)
    {
        speed.setY(speed.getY() + (GVC::gravity->getY()*-3)/5);
    }

    if(!dead)
    {
        fall = true;
    }

    if(position.getY()>GVC::SCREENHEIGHT)
    {
        dead = true;

    }

    calcSpriteSpeed();

}

void Player::draw()
{
    if(dead)
    {
        al_draw_bitmap(GFX::playerDead,position.getX(),position.getY(),0);
        width = al_get_bitmap_width(GFX::playerDead);
        height = al_get_bitmap_height(GFX::playerDead);
        return;
    }

    if(flying)
    {
        if(speed.getY() < 0)
        {
            al_draw_bitmap(GFX::playerFly0,position.getX(),position.getY(),0);
            width = al_get_bitmap_width(GFX::playerFly0);
            height = al_get_bitmap_height(GFX::playerFly0);
            return;
        }
        else
        {
            al_draw_bitmap(GFX::playerFly1,position.getX(),position.getY(),0);
            width = al_get_bitmap_width(GFX::playerFly1);
            height = al_get_bitmap_height(GFX::playerFly1);
            return;
        }
    }

    if(flyingCounter > 0)
    {
        if(jumping)
        {
            if(speed.getY() < 0)
            {
                al_draw_bitmap(GFX::playerCapeJump0,position.getX(),position.getY(),0);
                width = al_get_bitmap_width(GFX::playerCapeJump0);
                height = al_get_bitmap_height(GFX::playerCapeJump0);
            }
            else
            {
                al_draw_bitmap(GFX::playerCapeJump1,position.getX(),position.getY(),0);
                width = al_get_bitmap_width(GFX::playerCapeJump1);
                height = al_get_bitmap_height(GFX::playerCapeJump1);
            }
        }
        else
        {
            if(spriteRun==0)
            {
                al_draw_bitmap(GFX::playerCapeRun0,position.getX(),position.getY(),0);
                width = al_get_bitmap_width(GFX::playerCapeRun0);
                height = al_get_bitmap_height(GFX::playerCapeRun0);
            }
            if(spriteRun==1)
            {
                al_draw_bitmap(GFX::playerCapeRun1,position.getX(),position.getY(),0);
                width = al_get_bitmap_width(GFX::playerCapeRun1);
                height = al_get_bitmap_height(GFX::playerCapeRun1);
            }
            if(spriteRun==2)
            {
                al_draw_bitmap(GFX::playerCapeRun2,position.getX(),position.getY(),0);
                width = al_get_bitmap_width(GFX::playerCapeRun2);
                height = al_get_bitmap_height(GFX::playerCapeRun2);
            }
            if(spriteRun==3)
            {
                al_draw_bitmap(GFX::playerCapeRun3,position.getX(),position.getY(),0);
                width = al_get_bitmap_width(GFX::playerCapeRun3);
                height = al_get_bitmap_height(GFX::playerCapeRun3);
            }
        }
    }
    else
    {
        if(jumping)
        {
            if(speed.getY() < 0)
            {
                if(life == 2)
                {
                    al_draw_bitmap(GFX::playerJump0,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerJump0);
                    height = al_get_bitmap_height(GFX::playerJump0);
                }
                if(life == 1)
                {
                    al_draw_bitmap(GFX::playerJump00,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerJump00);
                    height = al_get_bitmap_height(GFX::playerJump00);
                }
            }
            else
            {
                if(life == 2)
                {
                    al_draw_bitmap(GFX::playerJump1,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerJump1);
                    height = al_get_bitmap_height(GFX::playerJump1);
                }
                if(life == 1)
                {
                    al_draw_bitmap(GFX::playerJump01,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerJump01);
                    height = al_get_bitmap_height(GFX::playerJump01);
                }
            }
        }
        else
        {
            if(life == 2)
            {
                if(spriteRun==0)
                {
                    al_draw_bitmap(GFX::playerRun0,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerRun0);
                    height = al_get_bitmap_height(GFX::playerRun0);
                }
                if(spriteRun==1)
                {
                    al_draw_bitmap(GFX::playerRun1,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerRun1);
                    height = al_get_bitmap_height(GFX::playerRun1);
                }
                if(spriteRun==2)
                {
                    al_draw_bitmap(GFX::playerRun2,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerRun2);
                    height = al_get_bitmap_height(GFX::playerRun2);
                }
                if(spriteRun==3)
                {
                    al_draw_bitmap(GFX::playerRun1,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerRun1);
                    height = al_get_bitmap_height(GFX::playerRun1);
                }
            }
            if(life == 1)
            {
                if(spriteRun==0)
                {
                    al_draw_bitmap(GFX::playerRun00,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerRun00);
                    height = al_get_bitmap_height(GFX::playerRun00);
                }
                if(spriteRun==1)
                {
                    al_draw_bitmap(GFX::playerRun01,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerRun01);
                    height = al_get_bitmap_height(GFX::playerRun01);
                }
                if(spriteRun==2)
                {
                    al_draw_bitmap(GFX::playerRun00,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerRun00);
                    height = al_get_bitmap_height(GFX::playerRun00);
                }
                if(spriteRun==3)
                {
                    al_draw_bitmap(GFX::playerRun01,position.getX(),position.getY(),0);
                    width = al_get_bitmap_width(GFX::playerRun01);
                    height = al_get_bitmap_height(GFX::playerRun01);
                }
            }
        }

    }
}
