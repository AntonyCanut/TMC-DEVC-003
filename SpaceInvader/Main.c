#include <stdio.h>
#include <SDL2.framework/Headers/SDL.h>
#include <SDL2_image.framework/Headers/SDL_image.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

SDL_Window *Window;
SDL_Renderer *Renderer;

SDL_Surface *sBackground;
SDL_Texture *tBackground;
SDL_Surface *sEarth;
SDL_Texture *tEarth;

SDL_Rect bPos;
SDL_Rect ePos;

char *srcBackgroundPicture = "img/decor/fond_1920x1080.png";
char *srcEarthPicture = "img/decor/earth_1700x3800.png";

void Init()
{
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("Init error\n");
        exit(1);
    }
    Window = SDL_CreateWindow("Space Invader", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    Renderer = SDL_CreateRenderer(Window, -1, 0);
    
    bPos.x = 0;
    bPos.y = 0;
    bPos.w = SCREEN_WIDTH;
    bPos.h = SCREEN_HEIGHT;

    ePos.x = 0;
    ePos.y = 0;
    ePos.w = SCREEN_WIDTH;
    ePos.h = SCREEN_HEIGHT;
}

void Load()
{
    tEarth = IMG_LoadTexture(Renderer, "img/decor/earth_1700x3800.png");
    tBackground = IMG_LoadTexture(Renderer, "img/decor/fond_1920x1080.png");
}

void Destroy()
{
    SDL_DestroyTexture(tEarth);
    SDL_FreeSurface(sEarth);
    SDL_DestroyTexture(tBackground);
    SDL_FreeSurface(sBackground);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void Update()
{
    if (ePos.y < 600)
    {
        ePos.y += 1;
    }else{
        ePos.y = 0;
    }

    SDL_RenderClear(Renderer);
    SDL_RenderCopy(Renderer, tEarth, 0, &ePos);
    SDL_RenderCopy(Renderer, tBackground, 0, &bPos);
    SDL_RenderPresent(Renderer);
}

int main()
{
    int isRunning = 1;
    
    Init();
    Load();
    while(isRunning == 1)
    {
        Uint32 toWait;
        Uint32 time = SDL_GetTicks();
        Update();
        toWait = SDL_GetTicks() - time;
        if (toWait < 16)
            SDL_Delay(16 - toWait);
    }
    Destroy();
    return (0);
}