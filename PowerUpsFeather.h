#ifndef POWERUPSFEATHER_H
#define POWERUPSFEATHER_H

#include "PowerUps.h"

class PowerUpsFeather: public PowerUps
{
    public:
        PowerUpsFeather();
        virtual ~PowerUpsFeather();

        void makeEffect(Player& player);
        void resetSpeed();
        void update(Player& players, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3);
        void draw();
    protected:
    private:
};

#endif // POWERUPSFEATHERS_H
