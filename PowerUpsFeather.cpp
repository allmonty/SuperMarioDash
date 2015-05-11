#include "PowerUpsFeather.h"

#include "GFX.h"
#include "GVC.h"

PowerUpsFeather::PowerUpsFeather()
{
    width = al_get_bitmap_width(GFX::feather);
    height = al_get_bitmap_height(GFX::feather);

    resetSpeed();
}

PowerUpsFeather::~PowerUpsFeather()
{
    //dtor
}

void PowerUpsFeather::makeEffect(Player& player)
{
    if(player.getDead()) return;

    player.setFlyingCounter(player.getFlyingCounter() + 15);
    player.setLife(2);

    player.fly();

    al_stop_sample_instance(GFX::feathergetInstance);
    al_play_sample_instance(GFX::feathergetInstance);

    GVC::gameSpeed -= 1;
}

void PowerUpsFeather::resetSpeed()
{
    setSpeed(-0.02,0);
}

void PowerUpsFeather::update(Player& player, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3)
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

void PowerUpsFeather::draw()
{
    if(able)
    {
        al_draw_bitmap(GFX::feather,position.getX(),position.getY(),0);
    }
}
