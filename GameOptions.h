#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

#include "Allegro.h"
#include "Scenario.h"

class GameOptions
{
public:
//Esqueleto do Mundo
    GameOptions();
    ~GameOptions();
    void processEvent(ALLEGRO_EVENT& event);
    void update(void);
    void draw(void);
    void loop();

//controles
    void up();
    void down();

    void reset();
    void drawStars();
    void setSound();

protected:
    Scenario barraSuperior1;
    Scenario barraSuperior2;
    Scenario barraInferior1;
    Scenario barraInferior2;

    bool quit;
    int selected, numeroDeOpcoes, backgroundSound, groundNumber, effectSound, effectNumber;
};

#endif // GAMEOPTIONS_H
