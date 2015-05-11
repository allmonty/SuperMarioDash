#ifndef PLAYER_H
#define PLAYER_H

#include "ObjectInGame.h"
#include "Plataforma.h"

class Player: public ObjectInGame
{
    public:
        Player();
        virtual ~Player();

        void looseLife();
        void setLife(int _life);
        int getLife();

        void fly();
        void looseFeather();
        void looseFlyingCounter();
        void setFlyingCounter(int _flyingcounter);
        int getFlyingCounter();

        void setDead(bool _dead);
        bool getDead();

        void setFall(bool _fall);
        bool getFall();

        void setJumping(bool _jumping);
        bool getJumping();

        void setFlying(bool _Flying);
        bool getFlying();

        void jump();
        void setHoldJump(bool hold);
        bool getHoldJump();
        void setJumpTimer();
        float getJumpTimer();
        float getJumpDuration();

        void colidePlataforma(Plataforma& visado);
        void calcSpriteSpeed();

        void update();
        void draw();
    protected:
    private:
        int life, flyingCounter;
        bool dead, fall, jumping, flying, holdJump;
        float jumpDuration, jumpTimer, spriteRun,spriteCount;
};

#endif // PLAYER_H
