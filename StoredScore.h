#ifndef STOREDSCORE_H
#define STOREDSCORE_H

class StoredScore
{
    public:
        StoredScore();
        virtual ~StoredScore();

//getters
        float getScore();
        char* getName();
        int getPos();
//setters
        void setPos(int _pos);
        void setName(const char* _name);
        void setScore(float _score);

    protected:
    private:
        float score;
        int pos;
        char name[10];
};

#endif // STOREDSCORE_H
