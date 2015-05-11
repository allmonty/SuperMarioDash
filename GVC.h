#ifndef GVC_H
#define GVC_H

#include "Vetor.h"
#include "Score.h"

class GVC
{
    public:

    static void unload();
//constants
    static const int SCREENWIDTH, SCREENHEIGHT;

//variables
    static float gameSpeed;
    static Vetor* gravity;
    static int platformDistance;
    static Score* score;
    static float effectsGain, bakcgroundGain;
};

#endif // GVC_H
