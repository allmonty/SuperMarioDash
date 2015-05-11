#ifndef SCENARIO_H
#define SCENARIO_H

#include "ObjectInGame.h"

class Scenario:public ObjectInGame
{
    public:
        Scenario();
        virtual ~Scenario();

        void setImagem(ALLEGRO_BITMAP* _imagem);
        void reposiciona(Scenario& reference);

        void draw();
        void update(Scenario& reference);
    protected:
    private:
        ALLEGRO_BITMAP* imagem;
};

#endif // SCENARIO_H
