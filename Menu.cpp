#include "Menu.h"

Menu::Menu()
{
    al_init_font_addon();
    al_init_ttf_addon();

    font = al_load_ttf_font("Candarab.ttf", 75, 0);
    if(font == NULL)
    {
        cout << "Problema carregando font" <<endl;
    }

    SELECIONADA = al_map_rgb(255,0,0);
    NAOSELECIONADA = al_map_rgb(255,255,0);

    corStart = corOption = corExit = NAOSELECIONADA;

    NUMERODEOPCOES = 3;
    START = 2;
    OPTION = 1;
    EXIT = 0;

    selected = START;

    update();
}

Menu::~Menu()
{
    al_destroy_font(font);
    al_shutdown_ttf_addon();
    al_shutdown_font_addon();
}


void Menu::draw()
{
    al_draw_text(font,corStart,400,200,ALLEGRO_ALIGN_CENTRE,"START");
    al_draw_text(font,corOption,400,300,ALLEGRO_ALIGN_CENTRE,"OPTION");
    al_draw_text(font,corExit,400,400,ALLEGRO_ALIGN_CENTRE,"EXIT");
}

void Menu::update()
{
    if(selected == START)
    {
        corStart = SELECIONADA;
        corOption = NAOSELECIONADA;
        corExit = NAOSELECIONADA;
    }
    if(selected == OPTION)
    {
        corStart = NAOSELECIONADA;
        corOption = SELECIONADA;
        corExit = NAOSELECIONADA;
    }
    if(selected == EXIT)
    {
        corStart = NAOSELECIONADA;
        corOption = NAOSELECIONADA;
        corExit = SELECIONADA;
    }
}

void Menu::up()
{
    selected++;
    selected = selected %NUMERODEOPCOES;
}

void Menu::down()
{
    selected--;
    selected = selected % NUMERODEOPCOES;
    if(selected<0) selected= NUMERODEOPCOES-1;
}
