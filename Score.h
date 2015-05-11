#ifndef SCORE_H
#define SCORE_H

#include "Allegro.h"
#include "Vetor.h"
#include "StoredScore.h"

#include <iostream>
#include <fstream>

using namespace std;

class Score
{
    public:
        Score();
        virtual ~Score();

        void stop();
        void save(const char* _name);
        void reset();
        void prepareTab();
//setters
        void setPosition(float _x, float _y);
//getters
        float getScore();
        Vetor getPosition();
        StoredScore getFromTab(int _num);
        bool getTop5();
        int getTabPos();

        void add(float x);

    protected:
    private:
        float score;
        int tabPos;
        bool stuck, top5;

        Vetor position;
        fstream myfile;
};

#endif // SCORE_H
