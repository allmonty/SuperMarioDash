#include "GFX.h"

//font
ALLEGRO_FONT* GFX::font(NULL);

//player
ALLEGRO_BITMAP* GFX::playerRun0(NULL);
ALLEGRO_BITMAP* GFX::playerRun00(NULL);
ALLEGRO_BITMAP* GFX::playerRun1(NULL);
ALLEGRO_BITMAP* GFX::playerRun01(NULL);
ALLEGRO_BITMAP* GFX::playerRun2(NULL);
ALLEGRO_BITMAP* GFX::playerJump0(NULL);
ALLEGRO_BITMAP* GFX::playerJump00(NULL);
ALLEGRO_BITMAP* GFX::playerJump1(NULL);
ALLEGRO_BITMAP* GFX::playerJump01(NULL);
ALLEGRO_BITMAP* GFX::playerDead(NULL);
ALLEGRO_BITMAP* GFX::playerCapeRun0(NULL);
ALLEGRO_BITMAP* GFX::playerCapeRun1(NULL);
ALLEGRO_BITMAP* GFX::playerCapeRun2(NULL);
ALLEGRO_BITMAP* GFX::playerCapeRun3(NULL);
ALLEGRO_BITMAP* GFX::playerCapeJump0(NULL);
ALLEGRO_BITMAP* GFX::playerCapeJump1(NULL);
ALLEGRO_BITMAP* GFX::playerFly0(NULL);
ALLEGRO_BITMAP* GFX::playerFly1(NULL);

//menu
ALLEGRO_BITMAP* GFX::menuInicial(NULL);
ALLEGRO_BITMAP* GFX::selectedStart(NULL);
ALLEGRO_BITMAP* GFX::selectedOption(NULL);
ALLEGRO_BITMAP* GFX::selectedHighscore(NULL);
ALLEGRO_BITMAP* GFX::selectedExit(NULL);
ALLEGRO_BITMAP* GFX::blocksBar(NULL);

//Backgrounds game
ALLEGRO_BITMAP* GFX::background(NULL);
ALLEGRO_BITMAP* GFX::montanhas1(NULL);
ALLEGRO_BITMAP* GFX::montanhas2(NULL);
ALLEGRO_BITMAP* GFX::nuvens1(NULL);
ALLEGRO_BITMAP* GFX::nuvens2(NULL);

//pause
ALLEGRO_BITMAP* GFX::pause(NULL);

//background gameover
ALLEGRO_BITMAP* GFX::gameover(NULL);

//background gameoptions
ALLEGRO_BITMAP* GFX::gameoptions(NULL);
ALLEGRO_BITMAP* GFX::gameoptionsright(NULL);
ALLEGRO_BITMAP* GFX::gameoptionsleft(NULL);
ALLEGRO_BITMAP* GFX::gameoptionsmiddle(NULL);
ALLEGRO_BITMAP* GFX::gameoptionsStar(NULL);

//background gamehighscores
ALLEGRO_BITMAP* GFX::gamehighscores(NULL);

//background submitName
ALLEGRO_BITMAP* GFX::submitName(NULL);
ALLEGRO_BITMAP* GFX::star(NULL);

//plataformas tipo 0
ALLEGRO_BITMAP* GFX::terraCentro(NULL);
ALLEGRO_BITMAP* GFX::terraEsquerdo(NULL);
ALLEGRO_BITMAP* GFX::terraDireito(NULL);
//plataformas tipo 1
ALLEGRO_BITMAP* GFX::blocks1(NULL);
//plataformas tipo 2
ALLEGRO_BITMAP* GFX::vinhas(NULL);
//plataformas tipo 3
ALLEGRO_BITMAP* GFX::pipe1(NULL);
ALLEGRO_BITMAP* GFX::pipe2(NULL);
ALLEGRO_BITMAP* GFX::pipe3(NULL);
//plataformas tipo 4
ALLEGRO_BITMAP* GFX::cloudbar(NULL);

//Inimigos
ALLEGRO_BITMAP* GFX::koopared0(NULL);
ALLEGRO_BITMAP* GFX::koopared1(NULL);
ALLEGRO_BITMAP* GFX::koopared2(NULL);
ALLEGRO_BITMAP* GFX::spiker0(NULL);
ALLEGRO_BITMAP* GFX::spiker1(NULL);
ALLEGRO_BITMAP* GFX::spiker2(NULL);
ALLEGRO_BITMAP* GFX::spiker3(NULL);

//powerups
ALLEGRO_BITMAP* GFX::mushroom(NULL);
ALLEGRO_BITMAP* GFX::feather(NULL);


//AUDIO----------------------------------------

//background
ALLEGRO_SAMPLE* GFX::intro(NULL);
ALLEGRO_SAMPLE* GFX::firstworld(NULL);
//effects
ALLEGRO_SAMPLE* GFX::herewego(NULL);
ALLEGRO_SAMPLE* GFX::thankyou(NULL);
ALLEGRO_SAMPLE* GFX::oneup(NULL);
ALLEGRO_SAMPLE* GFX::jump(NULL);
ALLEGRO_SAMPLE* GFX::message(NULL);
ALLEGRO_SAMPLE* GFX::injury(NULL);
ALLEGRO_SAMPLE* GFX::kick(NULL);
ALLEGRO_SAMPLE* GFX::powerup(NULL);
ALLEGRO_SAMPLE* GFX::lostalife(NULL);
ALLEGRO_SAMPLE* GFX::featherget(NULL);
ALLEGRO_SAMPLE* GFX::spin(NULL);
ALLEGRO_SAMPLE* GFX::caperise(NULL);

ALLEGRO_SAMPLE_INSTANCE* GFX::introInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::firstworldInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::herewegoInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::thankyouInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::oneupInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::jumpInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::messageInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::injuryInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::kickInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::powerupInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::lostalifeInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::feathergetInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::spinInstance(NULL);
ALLEGRO_SAMPLE_INSTANCE* GFX::caperiseInstance(NULL);


void GFX::load()
{
    //font
    font = al_load_ttf_font("Mario.ttf",20,0);

    //player
    playerRun0 = al_load_bitmap("Imagens/playerRun0.png");
    playerRun00 = al_load_bitmap("Imagens/playerRun00.png");
    playerRun1 = al_load_bitmap("Imagens/playerRun1.png");
    playerRun01 = al_load_bitmap("Imagens/playerRun01.png");
    playerRun2 = al_load_bitmap("Imagens/playerRun2.png");
    playerJump0 = al_load_bitmap("Imagens/playerJump0.png");
    playerJump00 = al_load_bitmap("Imagens/playerJump00.png");
    playerJump1 = al_load_bitmap("Imagens/playerJump1.png");
    playerJump01 = al_load_bitmap("Imagens/playerJump01.png");
    playerDead = al_load_bitmap("Imagens/playerDead.png");
    playerCapeRun0 = al_load_bitmap("Imagens/playerCapeRun0.png");
    playerCapeRun1 = al_load_bitmap("Imagens/playerCapeRun1.png");
    playerCapeRun2 = al_load_bitmap("Imagens/playerCapeRun2.png");
    playerCapeRun3 = al_load_bitmap("Imagens/playerCapeRun3.png");
    playerCapeJump0 = al_load_bitmap("Imagens/playerCapeJump0.png");
    playerCapeJump1 = al_load_bitmap("Imagens/playerCapeJump1.png");
    playerFly0 = al_load_bitmap("Imagens/playerFly0.png");
    playerFly1 = al_load_bitmap("Imagens/playerFly1.png");

    //menu
    menuInicial = al_load_bitmap("Imagens/MenuInicial.png");
    selectedStart = al_load_bitmap("Imagens/selectedStart.png");
    selectedOption = al_load_bitmap("Imagens/selectedOption.png");
    selectedHighscore = al_load_bitmap("Imagens/selectedHighscore.png");
    selectedExit = al_load_bitmap("Imagens/selectedExit.png");
    blocksBar = al_load_bitmap("Imagens/blocksbar.png");

    //Backgrounds game
    background = al_load_bitmap("Imagens/background.png");
    montanhas1 = al_load_bitmap("Imagens/montanhas1.png");
    montanhas2 = al_load_bitmap("Imagens/montanhas2.png");
    nuvens1 = al_load_bitmap("Imagens/nuvens1.png");
    nuvens2 = al_load_bitmap("Imagens/nuvens2.png");

    //pause
    pause = al_load_bitmap("Imagens/pause.png");

    //background gameover
    gameover = al_load_bitmap("Imagens/gameover.png");

    //background gameoptions
    gameoptions = al_load_bitmap("Imagens/Options.png");
    gameoptionsright = al_load_bitmap("Imagens/OptionsRight.png");
    gameoptionsleft = al_load_bitmap("Imagens/OptionsLeft.png");
    gameoptionsmiddle = al_load_bitmap("Imagens/OptionsMiddle.png");
    gameoptionsStar = al_load_bitmap("Imagens/OptionsStar.png");

    //background gamehighscores
    gamehighscores = al_load_bitmap("Imagens/HighScoresBackground.png");

    //background submitName
    submitName = al_load_bitmap("Imagens/submitName.png");
    star = al_load_bitmap("Imagens/Star.png");

    //plataformas tipo 0
    terraDireito = al_load_bitmap("Imagens/terraDireito.png");
    terraCentro = al_load_bitmap("Imagens/terraCentro.png");
    terraEsquerdo = al_load_bitmap("Imagens/terraEsquerdo.png");
    //plataformas tipo 1
    blocks1 = al_load_bitmap("Imagens/blocks.png");
    //plataformas tipo 2
    vinhas = al_load_bitmap("Imagens/vinhas.png");
    //plataformas tipo 3
    pipe1 = al_load_bitmap("Imagens/pipe1.png");
    pipe2 = al_load_bitmap("Imagens/pipe2.png");
    pipe3 = al_load_bitmap("Imagens/pipe3.png");
    //plataformas tipo 4
    cloudbar = al_load_bitmap("Imagens/cloudbar.png");

    //Inimigos
    koopared0 = al_load_bitmap("Imagens/koopaRed0.png");
    koopared1 = al_load_bitmap("Imagens/koopaRed1.png");
    koopared2 = al_load_bitmap("Imagens/koopaRed2.png");
    spiker0 = al_load_bitmap("Imagens/spiker0.png");
    spiker1 = al_load_bitmap("Imagens/spiker1.png");
    spiker2 = al_load_bitmap("Imagens/spiker2.png");
    spiker3 = al_load_bitmap("Imagens/spiker3.png");

    //powerups
    mushroom = al_load_bitmap("Imagens/mushroom.png");
    feather = al_load_bitmap("Imagens/feather.png");

//AUDIO---------------------------------------------------
    //background
    intro = al_load_sample("Audio/Title.wav");
    firstworld = al_load_sample("Audio/firstworld.wav");

    //effects
    herewego = al_load_sample("Audio/herewego.wav");
    thankyou = al_load_sample("Audio/thankyou.wav");
    oneup = al_load_sample("Audio/1-up.wav");
    jump = al_load_sample("Audio/jump.wav");
    message = al_load_sample("Audio/message.wav");
    injury = al_load_sample("Audio/sm64_injury.wav");
    kick = al_load_sample("Audio/kick.wav");
    powerup = al_load_sample("Audio/power-up.wav");
    lostalife = al_load_sample("Audio/lost_a_life.wav");
    featherget = al_load_sample("Audio/feather_get.wav");
    spin = al_load_sample("Audio/spin_jump.wav");
    caperise = al_load_sample("Audio/cape_rise.wav");

    //instances
    introInstance = al_create_sample_instance(intro);
        al_attach_sample_instance_to_mixer(introInstance,al_get_default_mixer());
    firstworldInstance = al_create_sample_instance(firstworld);
        al_attach_sample_instance_to_mixer(firstworldInstance,al_get_default_mixer());

    herewegoInstance = al_create_sample_instance(herewego);
        al_attach_sample_instance_to_mixer(herewegoInstance,al_get_default_mixer());
    thankyouInstance = al_create_sample_instance(thankyou);
        al_attach_sample_instance_to_mixer(thankyouInstance,al_get_default_mixer());
    oneupInstance = al_create_sample_instance(oneup);
        al_attach_sample_instance_to_mixer(oneupInstance,al_get_default_mixer());
    jumpInstance = al_create_sample_instance(jump);
        al_attach_sample_instance_to_mixer(jumpInstance,al_get_default_mixer());
    messageInstance = al_create_sample_instance(message);
        al_attach_sample_instance_to_mixer(messageInstance,al_get_default_mixer());
    injuryInstance = al_create_sample_instance(injury);
        al_attach_sample_instance_to_mixer(injuryInstance,al_get_default_mixer());
    kickInstance = al_create_sample_instance(kick);
        al_attach_sample_instance_to_mixer(kickInstance,al_get_default_mixer());
    powerupInstance = al_create_sample_instance(powerup);
        al_attach_sample_instance_to_mixer(powerupInstance,al_get_default_mixer());
    lostalifeInstance = al_create_sample_instance(lostalife);
        al_attach_sample_instance_to_mixer(lostalifeInstance,al_get_default_mixer());
    feathergetInstance = al_create_sample_instance(featherget);
        al_attach_sample_instance_to_mixer(feathergetInstance,al_get_default_mixer());
    spinInstance = al_create_sample_instance(spin);
        al_attach_sample_instance_to_mixer(spinInstance,al_get_default_mixer());
    caperiseInstance = al_create_sample_instance(caperise);
        al_attach_sample_instance_to_mixer(caperiseInstance,al_get_default_mixer());
}

void GFX::unload()
{
    //font
    al_destroy_font(font);

    //player
    al_destroy_bitmap(playerRun0);
    al_destroy_bitmap(playerRun00);
    al_destroy_bitmap(playerRun1);
    al_destroy_bitmap(playerRun01);
    al_destroy_bitmap(playerRun2);
    al_destroy_bitmap(playerJump0);
    al_destroy_bitmap(playerJump00);
    al_destroy_bitmap(playerJump1);
    al_destroy_bitmap(playerJump01);
    al_destroy_bitmap(playerDead);
    al_destroy_bitmap(playerCapeRun0);
    al_destroy_bitmap(playerCapeRun1);
    al_destroy_bitmap(playerCapeRun2);
    al_destroy_bitmap(playerCapeRun3);
    al_destroy_bitmap(playerCapeJump0);
    al_destroy_bitmap(playerCapeJump1);
    al_destroy_bitmap(playerFly0);
    al_destroy_bitmap(playerFly1);

    //menu
    al_destroy_bitmap(menuInicial);
    al_destroy_bitmap(selectedStart);
    al_destroy_bitmap(selectedOption);
    al_destroy_bitmap(selectedHighscore);
    al_destroy_bitmap(selectedExit);
    al_destroy_bitmap(blocksBar);

    //Backgrounds game
    al_destroy_bitmap(background);
    al_destroy_bitmap(montanhas1);
    al_destroy_bitmap(montanhas2);
    al_destroy_bitmap(nuvens1);
    al_destroy_bitmap(nuvens2);

    //pause
    al_destroy_bitmap(pause);

    //background gameover
    al_destroy_bitmap(gameover);

    //background gameoption
    al_destroy_bitmap(gameoptions);
    al_destroy_bitmap(gameoptionsleft);
    al_destroy_bitmap(gameoptionsright);
    al_destroy_bitmap(gameoptionsmiddle);
    al_destroy_bitmap(gameoptionsStar);

    //background gamehighscores
    al_destroy_bitmap(gamehighscores);

    //background submitName
    al_destroy_bitmap(submitName);
    al_destroy_bitmap(star);

    //plataformas tipo 0
    al_destroy_bitmap(terraDireito);
    al_destroy_bitmap(terraCentro);
    al_destroy_bitmap(terraEsquerdo);
    //plataformas tipo 1
    al_destroy_bitmap(blocks1);
    //plataformas tipo 2
    al_destroy_bitmap(vinhas);
    //plataformas tipo 3
    al_destroy_bitmap(pipe1);
    al_destroy_bitmap(pipe2);
    al_destroy_bitmap(pipe3);
    //plataformas tipo 4
    al_destroy_bitmap(cloudbar);

    //Inimigos
    al_destroy_bitmap(koopared0);
    al_destroy_bitmap(koopared1);
    al_destroy_bitmap(koopared2);
    al_destroy_bitmap(spiker0);
    al_destroy_bitmap(spiker1);
    al_destroy_bitmap(spiker2);
    al_destroy_bitmap(spiker3);

    //powerups
    al_destroy_bitmap(mushroom);
    al_destroy_bitmap(feather);

//AUDIO------------------------------------------

    al_destroy_sample_instance(introInstance);
    al_destroy_sample_instance(firstworldInstance);
    al_destroy_sample_instance(herewegoInstance);
    al_destroy_sample_instance(thankyouInstance);
    al_destroy_sample_instance(oneupInstance);
    al_destroy_sample_instance(jumpInstance);
    al_destroy_sample_instance(messageInstance);
    al_destroy_sample_instance(injuryInstance);
    al_destroy_sample_instance(kickInstance);
    al_destroy_sample_instance(powerupInstance);
    al_destroy_sample_instance(lostalifeInstance);
    al_destroy_sample_instance(feathergetInstance);
    al_destroy_sample_instance(spinInstance);
    al_destroy_sample_instance(caperiseInstance);


    //background
    al_destroy_sample(intro);
    al_destroy_sample(firstworld);
    //effects
    al_destroy_sample(herewego);
    al_destroy_sample(thankyou);
    al_destroy_sample(oneup);
    al_destroy_sample(jump);
    al_destroy_sample(message);
    al_destroy_sample(injury);
    al_destroy_sample(kick);
    al_destroy_sample(powerup);
    al_destroy_sample(lostalife);
    al_destroy_sample(featherget);
    al_destroy_sample(spin);
    al_destroy_sample(caperise);
}
