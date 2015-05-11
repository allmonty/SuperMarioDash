#include "Plataforma.h"

#include "GFX.h"
#include "GVC.h"

#include <cmath>

Plataforma::Plataforma():ObjectInGame(),alturaMaxima(0),alturaMinima(0),larguraMaxima(0),larguraMinima(0),tipo(0)
{
}

Plataforma::~Plataforma()
{
    //dtor
}

void Plataforma::calculaEntrada()
{
        //reseta o tipo;
        tipo = 0;

        int aux1 = (int) 0.5 + ((larguraMaxima - larguraMinima)/al_get_bitmap_width(GFX::terraCentro));
        int aux2 = (int) 0.5 + larguraMinima / al_get_bitmap_width(GFX::terraCentro);
        width = al_get_bitmap_width(GFX::terraDireito) + al_get_bitmap_width(GFX::terraEsquerdo) + (al_get_bitmap_width(GFX::terraCentro) * aux2) + (al_get_bitmap_width(GFX::terraCentro) * rand()%aux1);

        float aux3 = alturaMaxima - alturaMinima;
        height = (aux3/20) * (rand()%20) + alturaMinima;

        setPosition(0, GVC::SCREENHEIGHT - height);
}

void Plataforma::recalcula(ObjectInGame& plataforma)
{
    if(position.getX() + width <= 0 || width == 0)
    {
        tipo = rand()%5;

        switch(tipo)
        {
            case 0:
                calculaTipo0(plataforma);
                break;
            case 1:
                calculaTipo1(plataforma);
                break;
            case 2:
                calculaTipo2(plataforma);
                break;
            case 3:
                calculaTipo3(plataforma);
                break;
            case 4:
                calculaTipo4(plataforma);
                break;
        }
    }
    else
    {
        return;
    }
}

//earth
void Plataforma::calculaTipo0(ObjectInGame& plataforma)
{
        int aux1 = (int) 0.5 + ((larguraMaxima - larguraMinima)/al_get_bitmap_width(GFX::terraCentro));
        int aux2 = (int) 0.5 + larguraMinima / al_get_bitmap_width(GFX::terraCentro);
        width = al_get_bitmap_width(GFX::terraDireito) + al_get_bitmap_width(GFX::terraEsquerdo) + (al_get_bitmap_width(GFX::terraCentro) * aux2) + (al_get_bitmap_width(GFX::terraCentro) * rand()%aux1);

        float aux = alturaMaxima - alturaMinima;
        height = (aux/20) * (rand()%20) + alturaMinima;

        setPosition(plataforma.getPosition().getX()  + plataforma.getWidth() + GVC::platformDistance, GVC::SCREENHEIGHT - height);
}

//blocks
void Plataforma::calculaTipo1(ObjectInGame& plataforma)
{
        int aux1 = (int) 0.5 + ((larguraMaxima - larguraMinima)/al_get_bitmap_width(GFX::blocks1));
        int aux2 = (int) 0.5 + larguraMinima / al_get_bitmap_width(GFX::blocks1);
        width = (al_get_bitmap_width(GFX::blocks1) * aux2) + (al_get_bitmap_width(GFX::blocks1) * rand()%aux1);

        height = al_get_bitmap_height(GFX::blocks1);

        float aux = alturaMaxima - alturaMinima;
        setPosition(plataforma.getPosition().getX()  + plataforma.getWidth() + GVC::platformDistance, GVC::SCREENHEIGHT - ((aux/20) * (rand()%20) + alturaMinima));
}

//vines
void Plataforma::calculaTipo2(ObjectInGame& plataforma)
{
        int aux1 = (int) 0.5 + ((larguraMaxima - larguraMinima)/al_get_bitmap_width(GFX::vinhas));
        int aux2 = (int) 0.5 + larguraMinima / al_get_bitmap_width(GFX::vinhas);
        width = (al_get_bitmap_width(GFX::vinhas) * aux2) + (al_get_bitmap_width(GFX::vinhas) * rand()%aux1);

        float aux = alturaMaxima - alturaMinima;
        height = (aux/20) * (rand()%20) + alturaMinima;

        setPosition(plataforma.getPosition().getX()  + plataforma.getWidth() + GVC::platformDistance, GVC::SCREENHEIGHT - height);

        setWidth(width);
        setHeight(height);
}

//pipes
void Plataforma::calculaTipo3(ObjectInGame& plataforma)
{
        for(int i=0;i<10;i++)
        {
            sequenciaCores[i] = rand()%3;
        }


        int aux1 = (int) 0.5 + ((larguraMaxima - larguraMinima)/al_get_bitmap_width(GFX::pipe2));
        int aux2 = (int) 0.5 + larguraMinima / al_get_bitmap_width(GFX::pipe1);
        width = (al_get_bitmap_width(GFX::pipe1) * aux2) + (al_get_bitmap_width(GFX::pipe2) * rand()%aux1);

        float aux = alturaMaxima - alturaMinima;
        height = (aux/20) * (rand()%20) + alturaMinima;

        setPosition(plataforma.getPosition().getX()  + plataforma.getWidth() + GVC::platformDistance, GVC::SCREENHEIGHT - height);
}

//clouds
void Plataforma::calculaTipo4(ObjectInGame& plataforma)
{
        int aux1 = (int) 0.5 + ((larguraMaxima - larguraMinima)/al_get_bitmap_width(GFX::cloudbar));
        int aux2 = (int) 0.5 + larguraMinima / al_get_bitmap_width(GFX::cloudbar);
        width = (al_get_bitmap_width(GFX::cloudbar) * aux2) + (al_get_bitmap_width(GFX::cloudbar) * rand()%aux1);

        height = al_get_bitmap_height(GFX::cloudbar);

        float aux = alturaMaxima - alturaMinima;
        setPosition(plataforma.getPosition().getX()  + plataforma.getWidth() + GVC::platformDistance, GVC::SCREENHEIGHT - ((aux/20) * (rand()%20) + alturaMinima));
}

void Plataforma::setAlturaMaxima(float s)
{
    alturaMaxima = s;
}

void Plataforma::setAlturaMinima(float s)
{
    alturaMinima = s;
}

void Plataforma::setLarguraMaxima(float s)
{
    larguraMaxima = s;
}

void Plataforma::setLarguraMinima(float s)
{
    larguraMinima = s;
}

void Plataforma::update()
{
    setSpeed(GVC::gameSpeed,0);
    position = position + speed;
}

void Plataforma::draw()
{
    switch(tipo)
    {
        case 0:
            drawTipo0();
            break;
        case 1:
            drawTipo1();
            break;
        case 2:
            drawTipo2();
            break;
        case 3:
            drawTipo3();
            break;
        case 4:
            drawTipo4();
            break;
    }
}

void Plataforma::drawTipo0()
{
    al_draw_bitmap(GFX::terraEsquerdo, position.getX(), position.getY(),0);
    int aux = (width - (al_get_bitmap_width(GFX::terraDireito) + al_get_bitmap_width(GFX::terraEsquerdo)))/al_get_bitmap_width(GFX::terraCentro);
    for(int i=0;i<aux;i++)
    {
        al_draw_bitmap(GFX::terraCentro, position.getX() + al_get_bitmap_width(GFX::terraEsquerdo) + i*al_get_bitmap_width(GFX::terraCentro), position.getY(),0);
    }
    al_draw_bitmap(GFX::terraDireito, position.getX() + al_get_bitmap_width(GFX::terraEsquerdo) + aux*al_get_bitmap_width(GFX::terraCentro), position.getY(),0);
}

void Plataforma::drawTipo1()
{
    int aux = width/al_get_bitmap_width(GFX::blocks1);
    for(int i=0;i<aux;i++)
    {
        al_draw_bitmap(GFX::blocks1, position.getX() + i*al_get_bitmap_width(GFX::blocks1), position.getY(),0);
    }
}

void Plataforma::drawTipo2()
{
    int aux = width/al_get_bitmap_width(GFX::vinhas);
    for(int i=0;i<aux;i++)
    {
        al_draw_bitmap(GFX::vinhas, position.getX() + i*al_get_bitmap_width(GFX::vinhas), position.getY(),0);
    }
}

void Plataforma::drawTipo3()
{
    int aux = width/al_get_bitmap_width(GFX::pipe1);
    for(int i=0;i<aux;i++)
    {
        switch(sequenciaCores[i%10])
        {
            case 0:
                al_draw_bitmap(GFX::pipe1, position.getX() + i*al_get_bitmap_width(GFX::pipe1), position.getY(),0);
                break;
            case 1:
                al_draw_bitmap(GFX::pipe2, position.getX() + i*al_get_bitmap_width(GFX::pipe2), position.getY(),0);
                break;
            case 2:
                al_draw_bitmap(GFX::pipe3, position.getX() + i*al_get_bitmap_width(GFX::pipe3), position.getY(),0);
                break;
        }

    }
}

void Plataforma::drawTipo4()
{
    int aux = width/al_get_bitmap_width(GFX::cloudbar);
    for(int i=0;i<aux;i++)
    {
        al_draw_bitmap(GFX::cloudbar, position.getX() + i*al_get_bitmap_width(GFX::cloudbar), position.getY(),0);
    }
}
