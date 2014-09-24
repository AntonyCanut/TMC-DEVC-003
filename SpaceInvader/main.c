
#include "Headers/header.h"

void InitMain()
{
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("Init error\n");
        exit(1);
    }
    Window = SDL_CreateWindow("Space Invader", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    Renderer = SDL_CreateRenderer(Window, -1, 0);

    right = false;
    left = false;
    shoot = false;
    menu = true;
    isUp = true;
    paused = false;
    play = false;
    destroy = false;
    lose = false;
    victory = false;

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }

    musiqueBackground = Mix_LoadMUS("music/stage.mp3"); //Chargement de la musique
    Mix_AllocateChannels(32); //Allouer 32 canaux
    sonMenu = Mix_LoadWAV("music/menu.wav");
    sonTir = Mix_LoadWAV("sounds/tirShip.wav");
    sonExplosion = Mix_LoadWAV("sounds/explosionShip.wav");
    sonLaser = Mix_LoadWAV("sounds/lazor.wav");
    sonBoss = Mix_LoadWAV("music/boss_stage.wav");
    sonBonus = Mix_LoadWAV("sounds/bonus.wav");
    Mix_VolumeChunk(sonMenu, MIX_MAX_VOLUME);
    Mix_Volume(15, 0);

    //Mix_PlayChannel(2, sonBackground, 0); joue un son une fois
    InitMenu();
    InitTitre();
    InitPlay();
    InitQuit();
}

void LoadMain()
{
    Menu->Load();
    Titre->Load();
    Play->Load();
    Quit->Load();
}


void DestroyMain()
{
    Pause->Destroy();
    Titre->Destroy();
    Quit->Destroy();
    Play->Destroy();
    Menu->Destroy();
    Life->Destroy();
    Layout->Destroy();
    Boss->Destroy();
    // /!\ Je met une reserve mais je pense qu'il faudra ajouter une destruction des structures et des listes /!\
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    Mix_FreeChunk(sonMenu); //Libération du son 2
    Mix_FreeMusic(musiqueBackground); //Libération de la musique
    Mix_CloseAudio(); //Fermeture de l'API
    SDL_Quit();
    exit(0);
}

void UpdateTheMenu()
{
    Menu->Update();
    Play->Update();
    Quit->Update();
    Titre->Update();
}

void UpdateThePauseInput()
{
 while (SDL_PollEvent(&e))
    {
        switch(e.type){
            case SDL_QUIT:
                DestroyMain();
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym){
                    case SDLK_o:
                        paused = false;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(e.key.keysym.sym){
                    case SDLK_o:
                        paused = false;
                        break;
                    default:
                        break;
                }
                break;
        }
    }
    Pause->UpdateInput();
}

void UpdateTheMenuInput()
{
     while (SDL_PollEvent(&e))
    {
        switch(e.type){
            case SDL_QUIT:
                DestroyMain();
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym){
                    case SDLK_RETURN:
                        if (isUp == true)
                        {
                            menu = false;
                            play = true;
                        }
                        else
                        {
                            quit = true;
                        }
                        break;
                    case SDLK_DOWN:
                        if (isUp == true)
                        {
                            isUp = false;
                        }
                        break;
                    case SDLK_UP:
                        if (isUp == false)
                        {
                            isUp = true;
                        }
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(e.key.keysym.sym){
                    case SDLK_RETURN:
                        if (isUp == true)
                        {
                            menu = false;
                            play = true;
                        }
                        else
                        {
                            quit = true;
                        }
                        break;
                    case SDLK_DOWN:
                        if (isUp == true)
                        {
                            isUp = false;
                        }
                        break;
                    case SDLK_UP:
                        if (isUp == false)
                        {
                            isUp = true;
                        }
                        break;
                    default:
                        break;
                }
                break;
        }
    }
    Menu->UpdateInput();
}

void UpdateTheEndInput()
{
     while (SDL_PollEvent(&e))
    {
        switch(e.type){
            case SDL_QUIT:
                DestroyMain();
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym){
                    case SDLK_ESCAPE:
                        menu=true;
                        destroy = true;
                        play = false;
                        lose = false;
                        victory = false;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(e.key.keysym.sym){
                    case SDLK_ESCAPE:
                        menu=true;
                        destroy = true;
                        play = false;
                        lose = false;
                        victory = false;
                        break;
                    default:
                        break;
                }
                break;
        }
    }
    Menu->UpdateInput();
}


void DrawTheMenu()
{
    SDL_RenderClear(Renderer);
    Menu->Draw();
    Titre->Draw();
    Quit->Draw();
    Play->Draw();
    SDL_RenderPresent(Renderer);
}

int main()
{

    InitMain();
    LoadMain();
    InitGame();
    LoadGame();
    int isRunning = 1;


    Mix_PlayChannel(1, sonMenu, -1);
    Mix_PlayMusic(musiqueBackground, -1);
    //Mix_PlayMusic(musiqueBackground, -1); //Jouer infiniment la musique
    //Mix_FadeInMusic(musiqueBackground, -1, 10000);
    while(isRunning == 1)
    {
        Uint32 toWait;
        timeTick = SDL_GetTicks();
        if (menu == true)
        {
            pausedMusic = false;
            Mix_RewindMusic();
            Mix_PauseMusic();
            Mix_Volume(1, MIX_MAX_VOLUME);
            Mix_Volume(15, 0);
            UpdateTheMenuInput();
            UpdateTheMenu();
            DrawTheMenu();
            if (quit == true)
            {
                isRunning = 0;
            }
            if (play == true)
            {
                if (destroy == true)
                {
                    DestroyGame();
                    InitGame();
                    LoadGame();
                }
            }
        }
        else if (paused == true)
        {
                Mix_PauseMusic();
                UpdateThePauseInput();
                DrawGame();
        }
        else if (lose == true)
        {
                Mix_PauseMusic();
                UpdateTheEndInput();
                DrawGame();
        }
        else if (victory == true)
        {
                Mix_PauseMusic();
                UpdateTheEndInput();
                DrawGame();
        }
        else
        {
            if (isBoss == true)
            {
                Mix_PauseMusic();
                Mix_PlayChannel(15, sonBoss, -1);
                Mix_Volume(15, MIX_MAX_VOLUME);
                pausedMusic = true;
                isBoss = false;
            }
            if(Mix_PausedMusic() == 1 && pausedMusic == false)//Si la musique est en pause
            {
                Mix_ResumeMusic(); //Reprendre la musique
                Mix_Volume(1, 0);
            }
            UpdateGame();
            UpdateGameInput();
            DrawGame();
            if (quit == true)
            {
                isRunning = 0;
            }
        }
        toWait = SDL_GetTicks() - timeTick;
        if (toWait < 16)
            SDL_Delay(16 - toWait);
    }
    DestroyMain();
    return (0);
}
