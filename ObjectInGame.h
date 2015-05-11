#ifndef OBJECTINGAME_H
#define OBJECTINGAME_H

#include "Allegro.h"
#include "Vetor.h"


class ObjectInGame
{
    public:
        ObjectInGame();
        virtual ~ObjectInGame();

//setters
        void setPosition(float x, float y);
        void setSpeed(float x, float y);
        void setWidth(float W);
        void setHeight(float H);
//getters
        Vetor getPosition();
        Vetor getSpeed();
        float getWidth();
        float getHeight();

        void update();
    protected:
        float width, height;
        Vetor position, speed;
    private:
};

#endif // OBJECTINGAME_H
