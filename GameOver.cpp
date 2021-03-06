#include "GameOver.h"

#include "Allegro.h"

#include "GameSwitch.h"
#include "GFX.h"
#include "GVC.h"

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::processEvent(ALLEGRO_EVENT& event)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            al_play_sample_instance(GFX::thankyouInstance);
            al_rest(al_get_sample_instance_time(GFX::thankyouInstance));
            quit = true;
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            quit = true;
            GameSwitch::alternateWorld(0);
        }
    }
}

void GameOver::update(void)
{
    barraInferior1.update(barraInferior2);
    barraInferior2.update(barraInferior1);
    barraSuperior1.update(barraSuperior2);
    barraSuperior2.update(barraSuperior1);
}

void GameOver::draw(void)
{
    barraInferior1.draw();
    barraInferior2.draw();
    barraSuperior1.draw();
    barraSuperior2.draw();

    al_draw_textf(GFX::font, al_map_rgb(255,255,255), 380, 193, 0, "%.1f m", GVC::score->getScore());
    al_draw_textf(GFX::font, al_map_rgb(255,255,0), 415, 245, 0, "%s, %.1f m", aux.getName(), aux.getScore());
}

void GameOver::loop(void)
{
    bool refresh = true;
    quit = false;
    ALLEGRO_EVENT event;


//read the first in classification tab
    aux = GVC::score->getFromTab(0);

//anima��o do gameover
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
            al_draw_bitmap(GFX::gameover,0,0,0);
        }
    }
}
