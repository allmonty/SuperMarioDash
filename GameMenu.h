#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "Allegro.h"
#include "Scenario.h"

class GameMenu
{
public:
//Esqueleto do Mundo
    GameMenu();
    ~GameMenu();
    void processEvent(ALLEGRO_EVENT& event);
    void update(void);
    void draw(void);
    void loop();

//controles
    void up();
    void down();

    void reset();

protected:
    Scenario barraSuperior1;
    Scenario barraSuperior2;
    Scenario barraInferior1;
    Scenario barraInferior2;

    bool quit;
    int selected, numeroDeOpcoes, start, option, highscore, exit;
};

#endif // GAMEMENU_H
