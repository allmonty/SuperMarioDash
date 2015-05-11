#ifndef OBJETO_H
#define OBJETO_H

#include "Allegro.h"
#include "Vetor.h"


class Objeto
{
    public:
        Objeto();
        virtual ~Objeto();

        //setters
        void setPosicao(int x, int y);
        void setVelocidade(int x, int y);
        void setWidth(float W);
        void setHeight(float H);
        //getters
        Vetor getPosicao();
        Vetor getVelocidade();
        float getWidth();
        float getHeight();

        void update();
    protected:
        float width, height;
        Vetor posicao, velocidade;
    private:
};

#endif // OBJETO_H
