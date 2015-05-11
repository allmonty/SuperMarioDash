#ifndef POWERUPS_H
#define POWERUPS_H

#include "ObjectInGame.h"
#include "Player.h"
#include "Plataforma.h"

class PowerUps: public ObjectInGame
{
    public:
        PowerUps();
        virtual ~PowerUps();

        void collidePlayer(Player& player);
        void collidePlatform(Plataforma& visado);
        void setAble(bool _able);
        void setLocked(bool _locked);
        bool getLocked();

        virtual void resetSpeed();
        virtual void makeEffect(Player& player);
        virtual void update(Player& players, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3);
        virtual void draw();
    protected:
        bool able, fall, locked;
};

#endif // POWERUPS_H
