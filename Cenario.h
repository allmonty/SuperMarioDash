#ifndef CENARIO_H
#define CENARIO_H

#include "Objeto.h"

class Cenario:public Objeto
{
    public:
        Cenario();
        virtual ~Cenario();

        void setImagem(ALLEGRO_BITMAP* _imagem);
        void reposiciona();

        void draw();
        void update();
    protected:
    private:
        ALLEGRO_BITMAP* imagem;
};

#endif // CENARIO_H
