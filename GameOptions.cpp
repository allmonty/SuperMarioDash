#include "GameOptions.h"

#include "GameSwitch.h"
#include "GFX.h"
#include "GVC.h"

GameOptions::GameOptions():selected(0), groundNumber(0), effectNumber(0)
{
    numeroDeOpcoes = 2;
    backgroundSound = 0;
    effectSound = 1;

    reset();
}

GameOptions::~GameOptions()
{
}

void GameOptions::processEvent(ALLEGRO_EVENT& event)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN){
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            al_play_sample_instance(GFX::oneupInstance);
            quit = true;
            GameSwitch::alternateWorld(0);
        }
        if(!event.keyboard.repeat){
            if(event.keyboard.keycode == ALLEGRO_KEY_UP)
            {
                up();
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_DOWN)
            {
                down();
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                if(selected == backgroundSound && GVC::bakcgroundGain>0.0)
                {
                    al_draw_bitmap(GFX::gameoptionsleft,550,225,0);
                    GVC::bakcgroundGain -= 0.5;
                    setSound();
                }
                if(selected == effectSound && GVC::effectsGain>0.0)
                {
                    al_draw_bitmap(GFX::gameoptionsleft,550,375,0);
                    GVC::effectsGain -= 0.5;
                    setSound();
                    al_stop_sample_instance(GFX::oneupInstance);
                    al_play_sample_instance(GFX::oneupInstance);
                }
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                if(selected == backgroundSound && GVC::bakcgroundGain<2.0)
                {
                    al_draw_bitmap(GFX::gameoptionsright,550,225,0);
                    GVC::bakcgroundGain += 0.5;
                    setSound();
                }
                if(selected == effectSound && GVC::effectsGain<2.0)
                {
                    al_draw_bitmap(GFX::gameoptionsright,550,375,0);
                    GVC::effectsGain += 0.5;
                    setSound();
                    al_stop_sample_instance(GFX::oneupInstance);
                    al_play_sample_instance(GFX::oneupInstance);
                }
            }
        }
    }
}

void GameOptions::update(void)
{
    if(selected == backgroundSound)
    {
        al_draw_bitmap(GFX::gameoptionsmiddle,550,225,0);
    }
    if(selected == effectSound)
    {
        al_draw_bitmap(GFX::gameoptionsmiddle,550,375,0);
    }

    barraInferior1.update(barraInferior2);
    barraInferior2.update(barraInferior1);
    barraSuperior1.update(barraSuperior2);
    barraSuperior2.update(barraSuperior1);

    if(GVC::bakcgroundGain == 0.0)
        groundNumber = 1;
    if(GVC::bakcgroundGain == 0.5)
        groundNumber = 2;
    if(GVC::bakcgroundGain == 1.0)
        groundNumber = 3;
    if(GVC::bakcgroundGain == 1.5)
        groundNumber = 4;
    if(GVC::bakcgroundGain == 2.0)
        groundNumber = 5;


    if(GVC::effectsGain == 0.0)
        effectNumber = 1;
    if(GVC::effectsGain == 0.5)
        effectNumber = 2;
    if(GVC::effectsGain == 1.0)
        effectNumber = 3;
    if(GVC::effectsGain == 1.5)
        effectNumber = 4;
    if(GVC::effectsGain == 2.0)
        effectNumber = 5;
}

void GameOptions::draw(void)
{
    barraInferior1.draw();
    barraInferior2.draw();
    barraSuperior1.draw();
    barraSuperior2.draw();

    drawStars();
}

void GameOptions::loop(void)
{
    bool refresh = true;
    quit = false;
    ALLEGRO_EVENT event;

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
            al_draw_bitmap(GFX::gameoptions,0,0,0);
        }
    }
}

void GameOptions::up()
{
    selected++;
    selected = selected % numeroDeOpcoes;
}

void GameOptions::down()
{
    selected--;
    selected = selected % numeroDeOpcoes;
    if(selected<0)
        selected = numeroDeOpcoes-1;
}

void GameOptions::reset()
{
    selected = backgroundSound;
}

void GameOptions::drawStars()
{
    //background
    for(int i=0; i<groundNumber; i++)
    {
        al_draw_bitmap(GFX::gameoptionsStar,al_get_bitmap_width(GFX::gameoptionsStar)*i + 220, 200, 0);
    }

    //effects
    for(int i=0; i<effectNumber; i++)
    {
        al_draw_bitmap(GFX::gameoptionsStar,al_get_bitmap_width(GFX::gameoptionsStar)*i + 220, 350, 0);
    }

}

void GameOptions::setSound()
{
    al_set_sample_instance_gain(GFX::introInstance, GVC::bakcgroundGain);
    al_set_sample_instance_gain(GFX::firstworldInstance, GVC::bakcgroundGain);

    al_set_sample_instance_gain(GFX::herewegoInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::thankyouInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::oneupInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::jumpInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::messageInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::injuryInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::kickInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::powerupInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::lostalifeInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::feathergetInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::spinInstance, GVC::effectsGain);
    al_set_sample_instance_gain(GFX::caperiseInstance, GVC::effectsGain);
}
