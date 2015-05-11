#ifndef VETOR_H
#define VETOR_H


class Vetor
{
    public:
        Vetor(float _x, float _y);
        virtual ~Vetor();

        Vetor operator+(Vetor& v) const;
        Vetor operator-(Vetor& v) const;
        float operator*(Vetor& v) const;

        void setX(float _x);
        void setY(float _y);
        float getX();
        float getY();

        float getModulo();
    protected:
    private:
        float x,y;
};

#endif // VETOR_H
