#include "GameSwitch.h"

#include "GVC.h"

Game* GameSwitch::game = NULL;
GameMenu* GameSwitch::menu = NULL;
GameOver* GameSwitch::over = NULL;
GameOptions* GameSwitch::options = NULL;
GameHighScores* GameSwitch::highscores = NULL;
GameSubmitName* GameSwitch::submitName = NULL;

GameSwitch::GameSwitch()
{
}

GameSwitch::~GameSwitch()
{
    delete(game);
    delete(menu);
    delete(over);
    delete(options);
    delete(highscores);
    delete(submitName);
}

void GameSwitch::load(Game& _game, GameMenu& _menu, GameOver& _over, GameOptions& _options,
                           GameHighScores& _highscores, GameSubmitName& _submitName)
{
    GameSwitch::game = &_game;
    GameSwitch::menu = &_menu;
    GameSwitch::over = &_over;
    GameSwitch::options = &_options;
    GameSwitch::highscores = &_highscores;
    GameSwitch::submitName = &_submitName;
}

void GameSwitch::alternateWorld(int world)
{
    if(world == 0)
    {
        menu->loop();
    }
    else
    {
        if(world==1)
        {
            game->loop();
        }
        else
        {
            if(world==2)
            {
                over->loop();
            }
            else
            {
                if(world==3)
                {
                    highscores->loop();
                }
                else
                {
                    if(world==4)
                    {
                        submitName->loop();
                    }
                    else
                    {
                        if(world==5)
                        {
                            options->loop();
                        }
                    }
                }
            }
        }
    }
    return;
}
