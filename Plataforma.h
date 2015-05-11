#ifndef PLATAFORMA_H
#define PLATAFORMA_H


#include "ObjectInGame.h"

class Plataforma: public ObjectInGame
{
    public:
        Plataforma();
        virtual ~Plataforma();

        void calculaEntrada();
        void recalcula(ObjectInGame& plat);
        //terra
        void calculaTipo0(ObjectInGame& plat);
        void calculaTipo1(ObjectInGame& plat);
        void calculaTipo2(ObjectInGame& plat);
        void calculaTipo3(ObjectInGame& plat);
        void calculaTipo4(ObjectInGame& plat);


//setters
        void setAlturaMaxima(float s);
        void setAlturaMinima(float s);
        void setLarguraMaxima(float s);
        void setLarguraMinima(float s);

        void update();
        void draw();

        void drawTipo0();
        void drawTipo1();
        void drawTipo2();
        void drawTipo3();
        void drawTipo4();
    protected:
    private:
        float alturaMaxima, alturaMinima, larguraMaxima, larguraMinima;
        int tipo;
        int sequenciaCores[10];
};

#endif // PLATAFORMA_H
