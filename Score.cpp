#include "Score.h"

#include "GFX.h"
#include "GVC.h"

#include <iomanip>

Score::Score():score(0.0),tabPos(0),stuck(false),top5(false),position(0.0,0.0)
{
    prepareTab();
}

Score::~Score()
{
}

void Score::stop()
{
    stuck = true;

    if(!myfile.is_open())
    {
        myfile.open("ScoreTab.bin",ios::binary|ios::in|ios::out);
    }

    StoredScore aux;

    if(myfile.is_open())
    {
        if(myfile.good())
        {
            myfile.seekg(0,ios::beg);
            while(!myfile.eof())
            {
                myfile.read((char*)&aux,sizeof(StoredScore));
                if(score >= aux.getScore())
                {
                    top5 = true;
                    tabPos = aux.getPos();
                    break;
                }
            }
        }
    }

    myfile.close();
}

void Score::save(const char* _name)
{
    if(!myfile.is_open())
    {
        myfile.open("ScoreTab.bin",ios::out|ios::in|ios::binary);
    }

    StoredScore aux;

    if(myfile.is_open())
    {
        if(myfile.good())
        {
            if(top5)
            {
                StoredScore tab[5];
                for(int i = 0; i<5; i++)
                {
                    tab[i] = getFromTab(i);
                }

                for(int i = 4; i>=0; i--)
                {
                    if(tab[i].getPos() >= tabPos)
                    {
                        if(tab[i].getPos() < 5)
                        {
                            tab[i].setPos(tab[i].getPos() + 1);
                            tab[i+1] = tab[i];
                            tab[i].setPos(tab[i].getPos() - 1);
                        }
                    }
                    if(tab[i].getPos() == tabPos)
                    {
                        tab[i].setName(_name);
                        tab[i].setPos(tabPos);
                        setprecision(1);
                        tab[i].setScore(score);
                    }
                }

                myfile.close();
                myfile.open("ScoreTab.bin",ios::out|ios::binary);

                myfile.seekp(0);
                myfile.seekg(0);
                for(int i=0; i<5; i++)
                {
                    aux = tab[i];
                    myfile.write((char *)(&aux), sizeof(StoredScore));
                }
            }
        }
    }
    myfile.close();
}

void Score::prepareTab()
{
    myfile.open("ScoreTab.bin",ios::binary|ios::in);

    int end = 0;
    myfile.seekp(0,ios::end);
    end = (int) myfile.tellp();
    myfile.close();

    if(end <= 0)
    {
        myfile.open("ScoreTab.bin",ios::binary|ios::out);
        StoredScore aux;

        myfile.seekp(0,ios::beg);

        cout<<"Score losted, building a new one..."<<endl;

        aux.setName("Mario");
        aux.setScore(10000.0);
        aux.setPos(1);
        myfile.write(reinterpret_cast<char *>(&aux), sizeof(StoredScore));

        aux.setName("Luigi");
        aux.setScore(7500.0);
        aux.setPos(2);
        myfile.write(reinterpret_cast<char *>(&aux), sizeof(StoredScore));

        aux.setName("Bowser");
        aux.setScore(5000.0);
        aux.setPos(3);
        myfile.write(reinterpret_cast<char *>(&aux), sizeof(StoredScore));

        aux.setName("Koopa");
        aux.setScore(2500.0);
        aux.setPos(4);
        myfile.write(reinterpret_cast<char *>(&aux), sizeof(StoredScore));

        aux.setName("Peach");
        aux.setScore(1000.0);
        aux.setPos(5);
        myfile.write(reinterpret_cast<char *>(&aux), sizeof(StoredScore));
    }

    myfile.close();
}


void Score::reset()
{
    stuck = false;
    top5 = false;
    score = 0;
    tabPos = 0;
}

void Score::setPosition(float _x, float _y)
{
    position.setX(_x);
    position.setY(_y);
}

float Score::getScore()
{
    return score;
}

Vetor Score::getPosition()
{
    return position;
}

StoredScore Score::getFromTab(int _num)
{
    if(!myfile.is_open())
    {
        myfile.open("ScoreTab.bin",ios::binary|ios::in);
    }

    StoredScore aux;

    if(myfile.is_open())
    {
        if(myfile.good())
        {
            myfile.seekg(sizeof(StoredScore)*(_num),ios::beg);
            myfile.read((char*)&aux,sizeof(StoredScore));
        }
    }
    myfile.close();

    return aux;
}

bool Score::getTop5()
{
    return top5;
}

int Score::getTabPos()
{
    return tabPos;
}

void Score::add(float x)
{
    if(!stuck)
    {
        score += x;
    }
}
