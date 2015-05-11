#include "GVC.h"

void GVC::unload()
{
    delete(gravity);
    delete(score);
}

//constants
    const int GVC::SCREENWIDTH(800);
    const int GVC::SCREENHEIGHT(600);

//variables
    float GVC::gameSpeed(0);
    Vetor* GVC::gravity = new Vetor(0.0,0.0);
    int GVC::platformDistance(0);
    Score* GVC::score = new Score();

    float GVC::effectsGain(1.0);
    float GVC::bakcgroundGain(1.0);


