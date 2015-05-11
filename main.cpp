#include "Allegro.h"

#include "Game.h"
#include "GameMenu.h"
#include "GameOver.h"
#include "GameOptions.h"
#include "GameSwitch.h"
#include "GameSubmitName.h"

#include "GFX.h"
#include "GVC.h"

int main(void)
{
    Allegro::initialize(GVC::SCREENWIDTH, GVC::SCREENHEIGHT);
    {
        GFX::load();

        //prepare worlds
        GameMenu menu;
        GameOver over;
        GameOptions options;
        GameHighScores highscores;
        GameSubmitName submitName;
        Game game;

        //load worlds in the switch
        GameSwitch::load(game,menu,over,options,highscores,submitName);
        GameSwitch::alternateWorld(0);

        GVC::unload();
        GFX::unload();
    }
    Allegro::shutdown();
    return 0;
}
