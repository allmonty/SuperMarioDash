#include "Objeto.h"

#include "Game.h"

Objeto::Objeto():width(0),height(0),posicao(0,0),velocidade(0,0)
{

}

Objeto::~Objeto()
{
    //dtor
}

void Objeto::setPosicao(int x, int y)
{
    posicao = Vetor(x,y);
}

void Objeto::setVelocidade(int x, int y)
{
    velocidade = Vetor(x,y);

}

void Objeto::setWidth(float w)
{
    width = w;

}

void Objeto::setHeight(float h)
{
    height = h;

}

Vetor Objeto::getPosicao()
{
    return posicao;
}

Vetor Objeto::getVelocidade()
{
    return velocidade;
}

float Objeto::getWidth()
{
    return width;
}

float Objeto::getHeight()
{
    return height;
}

void Objeto::update()
{
    velocidade = velocidade + Game::GRAVIDADE;
    posicao = posicao + velocidade;
}
