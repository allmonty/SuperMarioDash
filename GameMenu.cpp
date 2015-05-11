#include "GameMenu.h"

#include "GameSwitch.h"
#include "GFX.h"
#include "GVC.h"

GameMenu::GameMenu()
{
    numeroDeOpcoes = 4;
    start = 3;
    option = 2;
    highscore = 1;
    exit = 0;

    reset();
}

GameMenu::~GameMenu()
{
}

void GameMenu::processEvent(ALLEGRO_EVENT& event)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN){
        if(!event.keyboard.repeat){
            if(event.keyboard.keycode == ALLEGRO_KEY_UP||
               event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                up();
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_DOWN||
               event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                down();
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                if(selected == start)
                {
                    al_stop_sample_instance(GFX::introInstance);

                    al_play_sample_instance(GFX::herewegoInstance);
                    quit = true;
                    reset();
                    GameSwitch::alternateWorld(1);
                }
                if(selected == highscore)
                {
                    al_play_sample_instance(GFX::oneupInstance);
                    quit = true;
                    reset();
                    GameSwitch::alternateWorld(3);
                }
                if(selected == option)
                {
                    al_play_sample_instance(GFX::oneupInstance);
                    quit = true;
                    reset();
                    GameSwitch::alternateWorld(5);
                }
                if(selected == exit)
                {
                    al_play_sample_instance(GFX::oneupInstance);
                    quit = true;
                }
            }
        }
    }
}

void GameMenu::update(void)
{
    if(selected == start)
    {
        al_draw_bitmap(GFX::selectedStart,0,0,0);
    }
    if(selected == highscore)
    {
        al_draw_bitmap(GFX::selectedHighscore,0,0,0);
    }
    if(selected == option)
    {
        al_draw_bitmap(GFX::selectedOption,0,0,0);
    }
    if(selected == exit)
    {
        al_draw_bitmap(GFX::selectedExit,0,0,0);
    }

    barraInferior1.update(barraInferior2);
    barraInferior2.update(barraInferior1);
    barraSuperior1.update(barraSuperior2);
    barraSuperior2.update(barraSuperior1);
}

void GameMenu::draw(void)
{
    barraInferior1.draw();
    barraInferior2.draw();
    barraSuperior1.draw();
    barraSuperior2.draw();
}

void GameMenu::loop(void)
{
    bool refresh = true;
    quit = false;
    ALLEGRO_EVENT event;


    al_set_sample_instance_playmode(GFX::introInstance,ALLEGRO_PLAYMODE_LOOP);
    al_play_sample_instance(GFX::introInstance);

//animação do menu
    barraInferior1.setImagem(GFX::blocksBar);
    barraInferior1.setSpeed(-1,0);
    barraInferior1.setPosition(0,0);

    barraInferior2.setImagem(GFX::blocksBar);
    barraInferior2.setSpeed(-1,0);
    barraInferior2.setPosition(al_get_bitmap_width(GFX::blocksBar),0);

    barraSuperior1.setImagem(GFX::blocksBar);
    barraSuperior1.setSpeed(-1,0);
    barraSuperior1.setPosition(0,GVC::SCREENHEIGHT-al_get_bitmap_height(GFX::blocksBar));

    barraSuperior2.setImagem(GFX::blocksBar);
    barraSuperior2.setSpeed(-1,0);
    barraSuperior2.setPosition(al_get_bitmap_width(GFX::blocksBar),GVC::SCREENHEIGHT-al_get_bitmap_height(GFX::blocksBar));



    while(!quit)
    {
        al_wait_for_event(Allegro::event_queue, &event);

        switch(event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            refresh = true;
            update(); // Update game logic
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            quit = true;
            break;
        default:
            processEvent(event); // Get user input
            break;
        }

        if(refresh && al_is_event_queue_empty(Allegro::event_queue))
        {
            refresh = false;
            draw(); // Draw game state

            al_flip_display();
            al_draw_bitmap(GFX::menuInicial,0,0,0);
        }
    }
}

void GameMenu::up()
{
    selected++;
    selected = selected % numeroDeOpcoes;
}

void GameMenu::down()
{
    selected--;
    selected = selected % numeroDeOpcoes;
    if(selected<0)
        selected = numeroDeOpcoes-1;
}

void GameMenu::reset()
{
    selected = start;
}
