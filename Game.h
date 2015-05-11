#ifndef GAME_H
#define GAME_H

#include "Allegro.h"
#include "Plataforma.h"
#include "Player.h"
#include "Score.h"
#include "Scenario.h"

#include "Enemy.h"
#include "Koopa.h"
#include "Spiker.h"

#include "PowerUps.h"
#include "PowerUpsMushroom.h"
#include "PowerUpsFeather.h"

#include "GFX.h"
#include "GVC.h"

class Game
{
public:
    ALLEGRO_KEYBOARD_EVENT estadoTeclado;

//objetos do Jogo
    Player player;

    Plataforma plataforma1;
    Plataforma plataforma2;
    Plataforma plataforma3;

    Scenario montanhas1;
    Scenario montanhas2;

    Scenario nuvens1;
    Scenario nuvens2;

    Enemy **enemys;
    int enemyCounter, maxEnemys;

    PowerUps **powerUps;
    int powerUpsCounter, maxPowerUps;

    Game();
    ~Game();
    void processEvent(ALLEGRO_EVENT& event);
    void update(void);
    void draw(void);
    void loop();

    void restartGame();

    void enemysRoutine();
    void remakeEnemy(Enemy *enemy);
    void unlockEnemys();
    void updateEnemys();
    void drawEnemys();

    void powerUpsRoutine();
    void remakePowerUp(PowerUps *powerUp);
    void unlockPowerUps();
    void updatePowerUps();
    void drawPowerUps();
protected:

    bool quit, pause;
    float timer, enemyTimer, powerUpsTimer;
};

#endif // GAME_H
