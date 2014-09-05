
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

    InitBackground();
    InitMoon();
    InitMars();
}

void LoadMain()
{
    LoadContentBackground();
    LoadContentMoon();
    LoadContentMars();
}

void DestroyMain()
{
    DestroyMars();
    DestroyMoon();
    DestroyBackground();
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void UpdateMain()
{
    UpdateBackground();
    UpdateMoon();
    UpdateMars();     
}

void UpdateMainInput()
{
    SDL_Event e;

    while (SDL_PollEvent(e))
    {
        case SDL_Quit:
            exit(0);
            break;
        case SDL_KEYDOWN:
            break;
        default:
            break;
    }
}

void DrawMain(){
    SDL_RenderClear(Renderer);

    DrawBackground();
    DrawMars();
    DrawMoon();

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
        Uint32 time = SDL_GetTicks();
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