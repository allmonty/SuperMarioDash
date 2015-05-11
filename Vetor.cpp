#include "Vetor.h"

Vetor::Vetor(float _x, float _y):x(_x),y(_y)
{
}

Vetor::~Vetor()
{
    //dtor
}

Vetor Vetor::operator+(Vetor& v) const
{
    return Vetor(x+v.getX(),y+v.getY());
}

Vetor Vetor::operator-(Vetor& v) const
{
    return Vetor(x-v.getX(),y-v.getY());
}

float Vetor::operator*(Vetor& v) const
{
    return x*v.getX() + y*v.getY();
}

void Vetor::setX(float _x)
{
    x = _x;
}

void Vetor::setY(float _y)
{
     y = _y;
}

float Vetor::getX()
{
    return x;
}

float Vetor::getY()
{
    return y;
}

float Vetor::getModulo()
{
    return (x*x+y*y)*(x*x+y*y);
}
