#include "PowerUpsMushroom.h"

#include "GFX.h"
#include "GVC.h"

PowerUpsMushroom::PowerUpsMushroom()
{
    width = al_get_bitmap_width(GFX::mushroom);
    height = al_get_bitmap_height(GFX::mushroom);

    resetSpeed();
}

PowerUpsMushroom::~PowerUpsMushroom()
{
    //dtor
}

void PowerUpsMushroom::makeEffect(Player& player)
{
    if(player.getDead()) return;

    if(player.getLife() < 2)
    {
        player.setLife(player.getLife() + 1);
        al_stop_sample_instance(GFX::powerupInstance);
        al_play_sample_instance(GFX::powerupInstance);
    }
    else
    {
        GVC::score->add(250);
        al_stop_sample_instance(GFX::oneupInstance);
        al_play_sample_instance(GFX::oneupInstance);
    }

    GVC::gameSpeed -= 0.5;
}

void PowerUpsMushroom::resetSpeed()
{
    setSpeed(-0.02,0);
}

void PowerUpsMushroom::update(Player& player, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3)
{
    if(!locked)
    {
        ObjectInGame::update();

        collidePlayer(player);
        collidePlatform(plataforma1);
        collidePlatform(plataforma2);
        collidePlatform(plataforma3);

        fall = true;
    }
}

void PowerUpsMushroom::draw()
{
    if(able)
    {
        al_draw_bitmap(GFX::mushroom,position.getX(),position.getY(),0);
    }
}
