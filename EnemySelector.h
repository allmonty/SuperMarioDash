#ifndef ENEMYSELECTOR_H
#define ENEMYSELECTOR_H

#include "Enemy.h"
#include "Koopa.h"
#include "Spiker.h"

class EnemySelector: Enemy
{
    public:
        EnemySelector();
        virtual ~EnemySelector();
    protected:
    private:
        Koopa koopa;
        Spiker spiker;
};

#endif // ENEMYSELECTOR_H
