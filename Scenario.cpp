#include "Scenario.h"

#include "GVC.h"

Scenario::Scenario():imagem(0)
{
    //ctor
}

Scenario::~Scenario()
{
    free(&imagem);
}

void Scenario::setImagem(ALLEGRO_BITMAP* _imagem)
{
    imagem = _imagem;
    setWidth(al_get_bitmap_width(_imagem));
    setHeight(al_get_bitmap_height(_imagem));
}

void Scenario::reposiciona(Scenario& reference)
{
    if(position.getX()+width<=0)
    {
        setPosition(reference.getPosition().getX() + reference.getWidth() + speed.getX(),position.getY());
    }
}

void Scenario::draw()
{
    al_draw_bitmap(imagem, position.getX(), position.getY(),0);
}

void Scenario::update(Scenario& reference)
{
    position = position + speed;
    reposiciona(reference);
}
