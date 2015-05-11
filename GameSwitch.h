#ifndef GAMESWITCH_H
#define GAMESWITCH_H

#include "Game.h"
#include "GameMenu.h"
#include "GameOver.h"
#include "GameOptions.h"
#include "GameHighScores.h"
#include "GameSubmitName.h"

class GameSwitch
{
    public:
        GameSwitch();
        virtual ~GameSwitch();

        static void load(Game& _game, GameMenu& _menu, GameOver& _over, GameOptions& _options,
                        GameHighScores& _highscores, GameSubmitName& _submitName);
        static void alternateWorld(int world);
    protected:
    private:
        static Game* game;
        static GameMenu* menu;
        static GameOver* over;
        static GameOptions* options;
        static GameHighScores* highscores;
        static GameSubmitName* submitName;
};

#endif // GAMESWITCH_H
