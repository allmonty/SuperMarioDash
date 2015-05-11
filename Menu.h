#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>

using namespace std;

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        void draw();
        void up();
        void down();
        void update();
    protected:
    private:
    int selected;
    ALLEGRO_FONT *font;
    ALLEGRO_COLOR corStart;
    ALLEGRO_COLOR corOption;
    ALLEGRO_COLOR corExit;

    ALLEGRO_COLOR SELECIONADA;
    ALLEGRO_COLOR NAOSELECIONADA;
    int NUMERODEOPCOES;
    int START;
    int OPTION;
    int EXIT;

};

#endif // MENU_H
