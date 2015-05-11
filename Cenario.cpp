#include "Cenario.h"

#include "Game.h"

Cenario::Cenario():imagem(0)
{
    //ctor
}

Cenario::~Cenario()
{
    //dtor
}

void Cenario::setImagem(ALLEGRO_BITMAP* _imagem)
{
    imagem = _imagem;
    setWidth(al_get_bitmap_width(_imagem));
    setHeight(al_get_bitmap_height(_imagem));
}

void Cenario::reposiciona()
{
    if(posicao.getX()+width<=0)
    {
        setPosicao(Game::WIDTH,posicao.getY());
    }
}

void Cenario::draw()
{
    al_draw_bitmap(imagem, posicao.getX(), posicao.getY(),0);
}

void Cenario::update()
{
    posicao = posicao + velocidade;
    reposiciona();
}
