#include "Game.h"

#include "GameSwitch.h"

Game::Game():enemyCounter(0),maxEnemys(3),powerUpsCounter(0),maxPowerUps(2),quit(false),pause(false),timer(0),enemyTimer(0),powerUpsTimer(0)
{

}

Game::~Game()
{
    if(quit)
    {
        //delete enemys
        for(int i = 0; i<maxEnemys; i++)
        {
            delete enemys[i];
        }
        delete[] enemys;

    //delete powerUps
        for(int i = 0; i<maxPowerUps; i++)
        {
            delete powerUps[i];
        }
        delete[] powerUps;
    }
}

void Game::processEvent(ALLEGRO_EVENT& event)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN){
        if(event.keyboard.keycode == ALLEGRO_KEY_SPACE){
            if(!event.keyboard.repeat && !player.getDead()){
                if(pause) return;
                if(!player.getFall())
                {
                    player.jump();
                    if(!player.getFall()){
                        player.setHoldJump(true);
                    }
                    else{
                        player.setHoldJump(false);
                    }
                    player.setJumpTimer();
                }
            }
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_F){
            if(!event.keyboard.repeat && !player.getDead()){
                if(pause) return;

                if(player.getFlyingCounter() > 0)
                {
                    player.setFlying(true);
                    player.fly();
                }
            }
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){
            if(!event.keyboard.repeat){
                if(!pause)
                {
                    al_stop_sample_instance(GFX::messageInstance);
                    al_play_sample_instance(GFX::messageInstance);
                    pause = true;
                }
                else
                {
                    al_stop_sample_instance(GFX::messageInstance);
                    al_play_sample_instance(GFX::messageInstance);
                    pause = false;
                }
            }
        }
    }
    if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode == ALLEGRO_KEY_SPACE){
            if(pause) return;

            player.setHoldJump(false);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_F){
            if(pause) return;

            if(player.getFlyingCounter() > 0)
            {
                player.looseFlyingCounter();
            }
        }
    }
}

void Game::update(void)
{
    if(pause)
    {
        return;
    }
//jump control
    if(player.getHoldJump())
    {
        if((clock() - player.getJumpTimer())/CLOCKS_PER_SEC <= player.getJumpDuration()){
            player.jump();
        }
    }

//background update
    {
    montanhas1.update(montanhas2);
    montanhas2.update(montanhas1);
    montanhas1.setSpeed(GVC::gameSpeed/10.0,0);
    montanhas2.setSpeed(GVC::gameSpeed/10.0,0);

    nuvens1.update(nuvens2);
    nuvens2.update(nuvens1);
    nuvens1.setSpeed(GVC::gameSpeed/5,0);
    nuvens2.setSpeed(GVC::gameSpeed/5,0);
    }


//update dos objetos e interações
    player.update();

    player.colidePlataforma(plataforma1);
    player.colidePlataforma(plataforma2);
    player.colidePlataforma(plataforma3);

    plataforma1.recalcula(plataforma3);
    plataforma2.recalcula(plataforma1);
    plataforma3.recalcula(plataforma2);

    plataforma1.update();
    plataforma2.update();
    plataforma3.update();

    enemysRoutine();
    powerUpsRoutine();


//score
    GVC::score->add( (float) abs(GVC::gameSpeed)/10 );

//Aumenta a velocidade a cada X segundos
    if((al_get_time() - timer) >= 2)
    {
        GVC::gameSpeed -= 0.5;
        timer = al_get_time();
    }

//verifica o final do jogo
    if(player.getPosition().getX() + player.getWidth() < 0 ||
       player.getPosition().getY() > GVC::SCREENHEIGHT)
    {
        GVC::score->stop();

        al_stop_sample_instance(GFX::firstworldInstance);

        if(!al_get_sample_instance_playing(GFX::lostalifeInstance))
        {
            al_play_sample_instance(GFX::lostalifeInstance);
        }

        quit = true;
        if(GVC::score->getTop5())
        {
            GameSwitch::alternateWorld(4);
        }
        else
        {
            GameSwitch::alternateWorld(2);
        }
    }

}

void Game::draw(void)
{
//Fundo
    montanhas1.draw();
    montanhas2.draw();

    nuvens1.draw();
    nuvens2.draw();

//Objetos
    al_draw_textf(GFX::font, al_map_rgb(255,255,0), 0, 0, 0, "Game score: %.1f", GVC::score->getScore());

    plataforma1.draw();
    plataforma2.draw();
    plataforma3.draw();

    drawEnemys();
    drawPowerUps();

    al_draw_bitmap(GFX::feather,0,GVC::SCREENHEIGHT - al_get_bitmap_height(GFX::feather),0);
    al_draw_textf(GFX::font,al_map_rgb(255,0,0),al_get_bitmap_width(GFX::feather),GVC::SCREENHEIGHT - al_get_bitmap_height(GFX::feather),ALLEGRO_ALIGN_LEFT,"%d",player.getFlyingCounter());

    player.draw();

    if(pause)
    {
        al_draw_bitmap(GFX::pause,0,0,0);
    }
}

void Game::loop(void)
{
    bool refresh = true;
    quit = false;
    ALLEGRO_EVENT event;

    restartGame();

    while(!quit)
    {
        al_wait_for_event(Allegro::event_queue, &event);

        switch(event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            refresh = true;
             update(); // Update game logic
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            quit = true;
            break;
        default:
            processEvent(event); // Get user input
            break;
        }

        if(refresh && al_is_event_queue_empty(Allegro::event_queue))
        {
            refresh = false;
            draw(); // Draw game state

            al_flip_display();
            al_draw_bitmap(GFX::background,0,0,0);
        }
    }
}

void Game::restartGame()
{
    srand ( time(NULL) );

    al_set_sample_instance_playmode(GFX::firstworldInstance,ALLEGRO_PLAYMODE_LOOP);
    al_play_sample_instance(GFX::firstworldInstance);

    timer = al_get_time();
    enemyTimer = al_get_time();
    powerUpsTimer = al_get_time();

    GVC::gameSpeed = -5;
    GVC::gravity->setY(0.5);
    GVC::platformDistance = 200;
    GVC::score->reset();
    GVC::score->setPosition(10, 10);

    player.setDead(false);
    player.setLife(2);
    player.setFlyingCounter(0);
    player.setPosition(50,100);
    player.setSpeed(0,0);

    //max enemys at once
    maxEnemys = 3;
    enemys = new Enemy*[maxEnemys];
    //populate enemys
    {
    for(int i=0; i<maxEnemys; i++)
    {
        switch(rand()%2)
        {
            case 0:
                enemys[i] = new Koopa();
                remakeEnemy(enemys[i]);
                enemys[i]->setPosition(GVC::SCREENWIDTH, -100);
                break;
            case 1:
                enemys[i] = new Spiker();
                remakeEnemy(enemys[i]);
                enemys[i]->setPosition(GVC::SCREENWIDTH, -100);
                break;
        }
    }
    }

    //max powerups at once
    maxPowerUps = 5;
    powerUps = new PowerUps*[maxPowerUps];
    //populate powerups
    {
    for(int i=0; i<maxPowerUps; i++)
    {
        if(rand()%2 == 0)
        {
            powerUps[i] = new PowerUpsMushroom();
            remakePowerUp(powerUps[i]);
            break;
        }
        else if(rand()%5 == 1)
        {
            powerUps[i] = new PowerUpsFeather();
            remakePowerUp(powerUps[i]);
            break;
        }
    }
    }

    //scenario
    {
    montanhas1.setImagem(GFX::montanhas1);
    montanhas1.setPosition(0,0);
    montanhas2.setImagem(GFX::montanhas2);
    montanhas2.setPosition(montanhas1.getPosition().getX() + montanhas1.getWidth(),0);

    nuvens1.setImagem(GFX::nuvens1);
    nuvens1.setPosition(0,0);
    nuvens2.setImagem(GFX::nuvens2);
    nuvens2.setPosition(nuvens1.getPosition().getX() + nuvens1.getWidth(),0);
    }

    //plataformas
    {
    plataforma1.setAlturaMaxima(400);
    plataforma1.setAlturaMinima(100);
    plataforma1.setLarguraMaxima(1800);
    plataforma1.setLarguraMinima(1600);
    plataforma1.calculaEntrada();

    plataforma2.setAlturaMaxima(400);
    plataforma2.setAlturaMinima(100);
    plataforma2.setLarguraMaxima(1800);
    plataforma2.setLarguraMinima(1600);
    plataforma2.setWidth(0);

    plataforma3.setAlturaMaxima(400);
    plataforma3.setAlturaMinima(100);
    plataforma3.setLarguraMaxima(1800);
    plataforma3.setLarguraMinima(1600);
    plataforma3.setWidth(0);
    }
}

//ENEMYS---------------------------------------------------------------------------------
void Game::enemysRoutine()
{
    updateEnemys();
    unlockEnemys();
}
void Game::drawEnemys()
{
    for(int i=0; i<maxEnemys; i++)
    {
        enemys[i]->draw();
    }
}
void Game::remakeEnemy(Enemy* enemy)
{
    enemy->setLocked(true);
    enemy->setDead(false);
    enemy->setAble(true);
    enemy->resetSpeed();
}

void Game::unlockEnemys()
{
    if(rand()%100 == 3 && (al_get_time() - enemyTimer) >= rand()%5)
    {
        enemys[enemyCounter++]->setLocked(false);
        enemyTimer = al_get_time();
    }
    if(enemyCounter >= maxEnemys)
    {
        enemyCounter = 0;
    }
}

void Game::updateEnemys()
{
    for(int i=0; i<maxEnemys; i++)
    {
        if(!enemys[i]->getLocked())
        {
            enemys[i]->update(player, plataforma1, plataforma2, plataforma3);

            if(enemys[i]->getPosition().getX() + enemys[i]->getWidth()<0
               ||enemys[i]->getPosition().getY()>GVC::SCREENHEIGHT)
            {
                switch(rand()%2)
                {
                    case 0:
                        delete enemys[i];
                        enemys[i] = new Koopa();
                        remakeEnemy(enemys[i]);
                        enemys[i]->setPosition(GVC::SCREENWIDTH, -100);
                        break;
                    case 1:
                        delete enemys[i];
                        enemys[i] = new Spiker();
                        remakeEnemy(enemys[i]);
                        enemys[i]->setPosition(GVC::SCREENWIDTH, -100);
                        break;
                }
            }
        }
    }
}


//powerUps-------------------------------------------------------------------------------------
void Game::powerUpsRoutine()
{
    updatePowerUps();
    unlockPowerUps();
}

void Game::drawPowerUps()
{
    for(int i=0; i<maxPowerUps; i++)
    {
        powerUps[i]->draw();
    }
}

void Game::remakePowerUp(PowerUps *powerUp)
{
    powerUp->setPosition( GVC::SCREENWIDTH, powerUp->getHeight() * -1 );
    powerUp->setLocked(true);
    powerUp->setAble(true);
    powerUp->resetSpeed();
}

void Game::unlockPowerUps()
{
    if(rand()%100 == 3 && (al_get_time() - powerUpsTimer) >= rand()%5)
    {
        powerUps[powerUpsCounter++]->setLocked(false);
        powerUpsTimer = al_get_time();
    }

    if(powerUpsCounter >= maxPowerUps)
    {
        powerUpsCounter = 0;
    }
}

void Game::updatePowerUps()
{
    for(int i=0; i<maxPowerUps; i++)
    {
        powerUps[i]->update(player,plataforma1,plataforma2,plataforma3);

        if(powerUps[i]->getPosition().getX() + powerUps[i]->getWidth()<0
            ||powerUps[i]->getPosition().getY() > GVC::SCREENHEIGHT)
        {
            switch(rand()%2)
            {
                case 0:
                    delete powerUps[i];
                    powerUps[i] = new PowerUpsMushroom();
                    remakePowerUp(powerUps[i]);
                    break;
                case 1:
                    delete powerUps[i];
                    powerUps[i] = new PowerUpsFeather();
                    remakePowerUp(powerUps[i]);
                    break;
            }
        }

    }
}
