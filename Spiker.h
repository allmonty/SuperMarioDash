#ifndef SPIKER_H
#define SPIKER_H

#include "Enemy.h"

class Spiker: public Enemy
{
    public:
        Spiker();
        virtual ~Spiker();

        void collidePlayer(Player& player);
        void resetSpeed();
        void draw();
        void update(Player& player, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3);
    protected:
    private:
};

#endif // Spiker_H
