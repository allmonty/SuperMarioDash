#ifndef KOOPA_H
#define KOOPA_H

#include "Enemy.h"

class Koopa: public Enemy
{
    public:
        Koopa();
        virtual ~Koopa();

        void collidePlayer(Player& player);
        void resetSpeed();
        void draw();
        void update(Player& player, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3);
    protected:
    private:
};

#endif // KOOPA_H
