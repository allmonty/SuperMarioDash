#include "GameSubmitName.h"

#include "GameSwitch.h"
#include "GFX.h"
#include "GVC.h"

GameSubmitName::GameSubmitName()
{
}

GameSubmitName::~GameSubmitName()
{
}

void GameSubmitName::processEvent(ALLEGRO_EVENT& event)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if(event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            quit = true;
            GVC::score->save(word);
            GameSwitch::alternateWorld(2);
        }

        if(wordNumber>0)
        {
            if(event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE)
            {
                removeLetter();
                wordNumber--;
            }
        }

        if(wordNumber<=10)
        {
            if(event.keyboard.keycode == ALLEGRO_KEY_A)
            {
                addLetter("a");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_B)
            {
                addLetter("b");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_C)
            {
                addLetter("c");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_D)
            {
                addLetter("d");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_E)
            {
                addLetter("e");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_F)
            {
                addLetter("f");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_G)
            {
                addLetter("g");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_H)
            {
                addLetter("h");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_I)
            {
                addLetter("i");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_J)
            {
                addLetter("j");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_K)
            {
                addLetter("k");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_L)
            {
                addLetter("l");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_M)
            {
                addLetter("m");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_N)
            {
                addLetter("n");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_O)
            {
                addLetter("o");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_P)
            {
                addLetter("p");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_Q)
            {
                addLetter("q");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_R)
            {
                addLetter("r");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_S)
            {
                addLetter("s");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_T)
            {
                addLetter("t");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_U)
            {
                addLetter("u");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_V)
            {
                addLetter("v");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_W)
            {
                addLetter("w");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_X)
            {
                addLetter("x");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_Y)
            {
                addLetter("y");
                wordNumber++;
            }
            if(event.keyboard.keycode == ALLEGRO_KEY_Z)
            {
                addLetter("z");
                wordNumber++;
            }
        }
    }
}

void GameSubmitName::update(void)
{
    barraInferior1.update(barraInferior2);
    barraInferior2.update(barraInferior1);
    barraSuperior1.update(barraSuperior2);
    barraSuperior2.update(barraSuperior1);
}

void GameSubmitName::draw(void)
{
    barraInferior1.draw();
    barraInferior2.draw();
    barraSuperior1.draw();
    barraSuperior2.draw();

    al_draw_textf(GFX::font, al_map_rgb(255,255,0), 280, 185, 0, "%d", GVC::score->getTabPos());

    al_draw_textf(GFX::font, al_map_rgb(255,255,0), 200, 260, 0, "%s", word);

    drawStars();

}

void GameSubmitName::loop(void)
{
    bool refresh = true;
    quit = false;
    ALLEGRO_EVENT event;

    wordNumber = 0;
    strcpy(word,"");

//read the first in classification tab
    aux = GVC::score->getFromTab(0);
    aux.setPos(1);

//animação do GameSubmitName
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
            al_draw_bitmap(GFX::submitName,0,0,0);
        }
    }
}

void GameSubmitName::drawStars()
{
    int max = 0;
    if(GVC::score->getTabPos() == 1)
        max = 5;
    if(GVC::score->getTabPos() == 2)
        max = 4;
    if(GVC::score->getTabPos() == 3)
        max = 3;
    if(GVC::score->getTabPos() == 4)
        max = 2;
    if(GVC::score->getTabPos() == 5)
        max = 1;

    for(int i=0; i<max; i++)
    {
        al_draw_bitmap(GFX::star,50 + al_get_bitmap_width(GFX::star)*i + 50*i, 435, 0);
    }
}

void GameSubmitName::addLetter(const char* _letter)
{
    strcat(word, _letter);
}

void GameSubmitName::removeLetter()
{
    int i = 0;
    for(i=0; word[i]; i++){}

    word[i-1] = '\x0';
}
