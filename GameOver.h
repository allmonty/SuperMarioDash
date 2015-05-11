#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Allegro.h"
#include "Scenario.h"
#include "StoredScore.h"

class GameOver
{
public:
//Esqueleto do Mundo
    GameOver();
    ~GameOver();
    void processEvent(ALLEGRO_EVENT& event);
    void update(void);
    void draw(void);
    void loop();

    void animaBarras();

protected:
    Scenario barraSuperior1;
    Scenario barraSuperior2;
    Scenario barraInferior1;
    Scenario barraInferior2;

    bool quit;

    StoredScore aux;
};

#endif // GAMEOVER_H
