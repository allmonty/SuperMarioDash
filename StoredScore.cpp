#include "StoredScore.h"

#include <cstring>
#include <cstdlib>

StoredScore::StoredScore():score(0.0),pos(0)
{
    //ctor
}

StoredScore::~StoredScore()
{
}

float StoredScore::getScore()
{
    return score;
}

char* StoredScore::getName()
{
    return name;
}

int StoredScore::getPos()
{
    return pos;
}

void StoredScore::setPos(int _pos)
{
    pos = _pos;
}

void StoredScore::setName(const char* _name)
{
    strcpy(name,_name);
}

void StoredScore::setScore(float _score)
{
    score = _score;
}
