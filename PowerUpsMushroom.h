#ifndef POWERUPSMUSHROOM_H
#define POWERUPSMUSHROOM_H

#include "PowerUps.h"

class PowerUpsMushroom: public PowerUps
{
    public:
        PowerUpsMushroom();
        virtual ~PowerUpsMushroom();

        void makeEffect(Player& player);
        void resetSpeed();
        void update(Player& players, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3);
        void draw();
    protected:
    private:
};

#endif // POWERUPSMUSHROOM_H
