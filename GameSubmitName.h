#ifndef GAMESUBMITNAME_H
#define GAMESUBMITNAME_H

#include "Allegro.h"
#include "Scenario.h"
#include "StoredScore.h"

class GameSubmitName
{
public:
//Esqueleto do Mundo
    GameSubmitName();
    ~GameSubmitName();
    void processEvent(ALLEGRO_EVENT& event);
    void update(void);
    void draw(void);
    void loop();

    void drawStars();
    void addLetter(const char* _letter);
    void removeLetter();

protected:
    Scenario barraSuperior1;
    Scenario barraSuperior2;
    Scenario barraInferior1;
    Scenario barraInferior2;

    bool quit;

    StoredScore aux;

    int wordNumber;
    char word[10];
};

#endif // GAMESUBMITNAME_H
