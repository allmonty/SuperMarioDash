#ifndef GFX_H
#define GFX_H

#include "Allegro.h"

class GFX
{
    public:
        static void load();
        static void unload();

        //font
        static ALLEGRO_FONT* font;

//images------------------------------------------
        //player
        static ALLEGRO_BITMAP* playerRun0;
        static ALLEGRO_BITMAP* playerRun00;
        static ALLEGRO_BITMAP* playerRun1;
        static ALLEGRO_BITMAP* playerRun01;
        static ALLEGRO_BITMAP* playerRun2;
        static ALLEGRO_BITMAP* playerJump0;
        static ALLEGRO_BITMAP* playerJump00;
        static ALLEGRO_BITMAP* playerJump1;
        static ALLEGRO_BITMAP* playerJump01;
        static ALLEGRO_BITMAP* playerDead;
        static ALLEGRO_BITMAP* playerCapeRun0;
        static ALLEGRO_BITMAP* playerCapeRun1;
        static ALLEGRO_BITMAP* playerCapeRun2;
        static ALLEGRO_BITMAP* playerCapeRun3;
        static ALLEGRO_BITMAP* playerCapeJump0;
        static ALLEGRO_BITMAP* playerCapeJump1;
        static ALLEGRO_BITMAP* playerFly0;
        static ALLEGRO_BITMAP* playerFly1;

        //menu
        static ALLEGRO_BITMAP* menuInicial;
        static ALLEGRO_BITMAP* selectedStart;
        static ALLEGRO_BITMAP* selectedOption;
        static ALLEGRO_BITMAP* selectedHighscore;
        static ALLEGRO_BITMAP* selectedExit;
        static ALLEGRO_BITMAP* blocksBar;

        //Backgrounds game
        static ALLEGRO_BITMAP* background;
        static ALLEGRO_BITMAP* montanhas1;
        static ALLEGRO_BITMAP* montanhas2;
        static ALLEGRO_BITMAP* nuvens1;
        static ALLEGRO_BITMAP* nuvens2;

        //pause
        static ALLEGRO_BITMAP* pause;

        //background gameover
        static ALLEGRO_BITMAP* gameover;

        //background gameoptions
        static ALLEGRO_BITMAP* gameoptions;
        static ALLEGRO_BITMAP* gameoptionsright;
        static ALLEGRO_BITMAP* gameoptionsleft;
        static ALLEGRO_BITMAP* gameoptionsmiddle;
        static ALLEGRO_BITMAP* gameoptionsStar;

        //background highscores
        static ALLEGRO_BITMAP* gamehighscores;

        //background submitName
        static ALLEGRO_BITMAP* submitName;
        static ALLEGRO_BITMAP* star;

        //plataformas tipo 0
        static ALLEGRO_BITMAP* terraDireito;
        static ALLEGRO_BITMAP* terraCentro;
        static ALLEGRO_BITMAP* terraEsquerdo;
        //plataformas tipo 1
        static ALLEGRO_BITMAP* blocks1;
        //plataformas tipo 2
        static ALLEGRO_BITMAP* vinhas;
        //plataformas tipo 3
        static ALLEGRO_BITMAP* pipe1;
        static ALLEGRO_BITMAP* pipe2;
        static ALLEGRO_BITMAP* pipe3;
        //plataforma tipo 4
        static ALLEGRO_BITMAP* cloudbar;

        //inimigos
        static ALLEGRO_BITMAP* koopared0;
        static ALLEGRO_BITMAP* koopared1;
        static ALLEGRO_BITMAP* koopared2;
        static ALLEGRO_BITMAP* spiker0;
        static ALLEGRO_BITMAP* spiker1;
        static ALLEGRO_BITMAP* spiker2;
        static ALLEGRO_BITMAP* spiker3;

        //powerUps
        static ALLEGRO_BITMAP* mushroom;
        static ALLEGRO_BITMAP* feather;


//AUDIO-------------------------------------------------
        //background
        static ALLEGRO_SAMPLE* intro;
        static ALLEGRO_SAMPLE* firstworld;
        //effects
        static ALLEGRO_SAMPLE* herewego;
        static ALLEGRO_SAMPLE* thankyou;
        static ALLEGRO_SAMPLE* oneup;
        static ALLEGRO_SAMPLE* jump;
        static ALLEGRO_SAMPLE* message;
        static ALLEGRO_SAMPLE* injury;
        static ALLEGRO_SAMPLE* kick;
        static ALLEGRO_SAMPLE* powerup;
        static ALLEGRO_SAMPLE* lostalife;
        static ALLEGRO_SAMPLE* featherget;
        static ALLEGRO_SAMPLE* spin;
        static ALLEGRO_SAMPLE* caperise;

        //instance
        static ALLEGRO_SAMPLE_INSTANCE* introInstance;
        static ALLEGRO_SAMPLE_INSTANCE* firstworldInstance;
        static ALLEGRO_SAMPLE_INSTANCE* herewegoInstance;
        static ALLEGRO_SAMPLE_INSTANCE* thankyouInstance;
        static ALLEGRO_SAMPLE_INSTANCE* oneupInstance;
        static ALLEGRO_SAMPLE_INSTANCE* jumpInstance;
        static ALLEGRO_SAMPLE_INSTANCE* messageInstance;
        static ALLEGRO_SAMPLE_INSTANCE* injuryInstance;
        static ALLEGRO_SAMPLE_INSTANCE* kickInstance;
        static ALLEGRO_SAMPLE_INSTANCE* powerupInstance;
        static ALLEGRO_SAMPLE_INSTANCE* lostalifeInstance;
        static ALLEGRO_SAMPLE_INSTANCE* feathergetInstance;
        static ALLEGRO_SAMPLE_INSTANCE* spinInstance;
        static ALLEGRO_SAMPLE_INSTANCE* caperiseInstance;

};

#endif // GFX_H
