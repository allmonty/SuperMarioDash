#ifndef ENEMY_H
#define ENEMY_H

#include "Allegro.h"
#include "ObjectInGame.h"

#include "Player.h"
#include "Plataforma.h"

class Enemy: public ObjectInGame
{
    public:
        Enemy();
        ~Enemy();

        //used for onground enemys
        void calcSpriteSpeed();
        void collidePlatform(Plataforma& visado);

//setters
        void setAble(bool _able);
        void setLocked(bool _locked);
        void setDead(bool _dead);
//getters
        bool getAble();
        bool getLocked();
        int getType();

        virtual void collidePlayer(Player& player);
        virtual void resetSpeed();
        virtual void draw();
        virtual void update(Player& player, Plataforma& plataforma1, Plataforma& plataforma2, Plataforma& plataforma3);
    protected:
        bool able, locked, dead, fall;
        int type;

        //related with sprite update
        int spriteNumber;
        float spriteCount,spriteRun;
};

#endif // ENEMY_H
