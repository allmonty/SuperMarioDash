#ifndef GAMEHIGHSCORES_H
#define GAMEHIGHSCORES_H

#include "Allegro.h"
#include "Scenario.h"
#include "storedScore.h"

class GameHighScores
{
public:
//Esqueleto do Mundo
    GameHighScores();
    ~GameHighScores();
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
    StoredScore first, second, third, fourth, fifth;
};

#endif // GAMEHIGHSCORES_H
