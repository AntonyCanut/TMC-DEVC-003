
#include "header.h"

Mix_Music *musique; 
   Mix_Chunk *sonBackground;//Créer un pointeur pour stocker un .WAV
   Mix_Chunk *son2;

void InitMain()
{
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("Init error\n");
        exit(1);
    }
    Window = SDL_CreateWindow("Space Invader", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    Renderer = SDL_CreateRenderer(Window, -1, 0);

    right=false;
    left=false;
    shoot=false;

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }
    
    Mix_AllocateChannels(32); //Allouer 32 canaux
    sonBackground = Mix_LoadWAV("music/stage.wav"); //Charger un wav dans un pointeur
    son2 = Mix_LoadWAV("music/stage.wav");
    Mix_VolumeChunk(sonBackground, MIX_MAX_VOLUME); //Mettre un volume pour ce wav
    Mix_VolumeChunk(son2, MIX_MAX_VOLUME);
    Mix_PlayChannel(2, sonBackground, -1);
    InitBackground();
    InitMoon();
    InitMars();

    InitShip();
    InitShipShoot();
}

void LoadMain()
{
    LoadContentBackground();
    LoadContentMoon();
    LoadContentMars();

    LoadContentShipShoot();
    LoadContentShip();
}

void DestroyMain()
{
    DestroyShip();
    DestroyShipShoot();

    DestroyMars();
    DestroyMoon();
    DestroyBackground();
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    Mix_FreeChunk(sonBackground);//Libération du son 1
    Mix_FreeChunk(son2);
    Mix_CloseAudio(); //Fermeture de l'API
    SDL_Quit();
    exit(0);
}

void UpdateMain()
{
    UpdateBackground();
    UpdateMoon();
    UpdateMars();

    UpdateShipShoot();  
    UpdateShip();    
}

void UpdateMainInput()
{
    while (SDL_PollEvent(&e))
    {
        switch(e.type){
            case SDL_QUIT:
                DestroyMain();
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym){
                    case SDLK_RIGHT:
                        right=true;
                        break;
                    case SDLK_LEFT:
                        left=true;
                        break;
                    case SDLK_SPACE:
                        shoot=true;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(e.key.keysym.sym){
                    case SDLK_RIGHT:
                        right=false;
                        break;
                    case SDLK_LEFT:
                        left=false;
                        break;
                    case SDLK_SPACE:
                        shoot=false;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    UpdateInputShip();
}

void DrawMain(){
    SDL_RenderClear(Renderer);

    DrawBackground();
    DrawMars();
    DrawMoon();

    DrawShipShoot();
    DrawShip();

    SDL_RenderPresent(Renderer);
}

int main()
{
    int isRunning = 1;
    
    InitMain();
    LoadMain();
    while(isRunning == 1)
    {
        Uint32 toWait;
        time = SDL_GetTicks();
        UpdateMain();
        UpdateMainInput();
        DrawMain();
        toWait = SDL_GetTicks() - time;
        if (toWait < 16)
            SDL_Delay(16 - toWait);
    }
    DestroyMain();
    return (0);
}