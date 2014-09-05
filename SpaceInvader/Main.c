
#include "header.h"

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

    InitBackground();
    InitMoon();
    InitMars();
    InitShip();
}

void LoadMain()
{
    LoadContentBackground();
    LoadContentMoon();
    LoadContentMars();
    LoadContentShip();
}

void DestroyMain()
{
    DestroyShip();
    DestroyMars();
    DestroyMoon();
    DestroyBackground();
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
    exit(0);
}

void UpdateMain()
{
    UpdateBackground();
    UpdateMoon();
    UpdateMars();  
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