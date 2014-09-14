
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

    right = false;
    left = false;
    shoot = false;
    menu = true;
    isUp = true;

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }
    
    musiqueBackground = Mix_LoadMUS("music/stage.wav"); //Chargement de la musique
    Mix_AllocateChannels(32); //Allouer 32 canaux
    sonBackground = Mix_LoadWAV("music/stage.wav");
    son2 = Mix_LoadWAV("music/stage.wav");
    Mix_VolumeChunk(sonBackground, MIX_MAX_VOLUME/2);
    Mix_VolumeChunk(son2, MIX_MAX_VOLUME/2);
    //Mix_PlayChannel(2, sonBackground, 0); joue un son une fois 
    InitMenu();
    InitTitre();
    InitPlay();
    InitQuit();
    InitBackground();
    InitMoon();
    InitMars();

    InitShip();
    InitLife();
    // Dépendant du vaisseau, a ne faire qu'au tir
    MyBullet = InitBullet(&Ship->Position, 0);

    // Faire une liste
    MyInvader = InitInvader(11);
    MyInvader2 = InitInvader(91);
}

void LoadMain()
{
    Menu->Load();
    Titre->Load();
    Play->Load();
    Quit->Load();
    Background->Load();
    Moon->Load();
    Mars->Load();
    Ship->Load();
    Life->Load();
    // Les tirs sont dépendant du vaisseau.
    // MyBullet->Load(MyBullet);
    // Les ennemis sont nombreux, boucle pour parcourire la liste.
    // MyInvader->Load();
}

void DestroyMain()
{
    Titre->Destroy();
    Quit->Destroy();
    Play->Destroy();
    Menu->Destroy();
    Life->Destroy();
    Ship->Destroy();
    Mars->Destroy();
    Moon->Destroy();
    Background->Destroy();
    // Les tirs ne doivent pas être détruit ici mais a leur extinction durant la partie, seuls les tirs restant 
    // (fin de partie alors que des tirs sont en cours doivent être détuuit)
    MyBullet->Destroy(MyBullet);
    // Les ennemis doivent aussi être détruit de la même façon via la liste d'invader
    MyInvader->Destroy(MyInvader);
    MyInvader2->Destroy(MyInvader2);
    // /!\ Je met une reserve mais je pense qu'il faudra ajouter une destruction des structures et des listes /!\
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    Mix_FreeChunk(sonBackground);//Libération du son 1
    Mix_FreeChunk(son2); //Libération du son 2
    Mix_FreeMusic(musiqueBackground); //Libération de la musique
    Mix_CloseAudio(); //Fermeture de l'API
    SDL_Quit();
    exit(0);
}

void UpdateMain()
{
    Background->Update();
    Moon->Update();
    Mars->Update();
    if (Ship->IsAlive < 10)
    {
        Ship->Update();
    }
    
    // Traitement a faire dans les listes

    MyBullet->Update(MyBullet);

    Life->Update();

    MyInvader->Update(MyInvader);
    MyInvader2->Update(MyInvader2);

}

void UpdateTheMenu()
{
    Menu->Update();
    Play->Update();
    Quit->Update();
    Titre->Update();
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
                    case SDLK_ESCAPE:
                        menu=true;
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
                    case SDLK_ESCAPE:
                        menu=true;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    Ship->UpdateInput();
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

void DrawMain(){
    SDL_RenderClear(Renderer);

    Background->Draw();
    Mars->Draw();
    Moon->Draw();
    if (Ship->IsAlive < 6)
    {
        Ship->Draw();
    }
    // Dépendance aux listes

    MyBullet->Draw(MyBullet);

    Life->Draw();

    MyInvader->Draw(MyInvader);
    MyInvader2->Draw(MyInvader2);
    SDL_RenderPresent(Renderer);
}

int main()
{

    InitMain();
    LoadMain();
    int isRunning = 1;

    //Mix_PlayMusic(musiqueBackground, -1); //Jouer infiniment la musique
    Mix_FadeInMusic(musiqueBackground, -1, 10000);
    while(isRunning == 1)
    {
        Uint32 toWait;
        time = SDL_GetTicks();
        if (menu == true)
        {
            UpdateTheMenuInput();
            UpdateTheMenu();
            DrawTheMenu();  
            if (quit == true)
            {
                isRunning = 0;
            }
        }
        else 
        {
            UpdateMain();
            UpdateMainInput();
            DrawMain();
            if (quit == true)
            {
                isRunning = 0;
            }
        }
        toWait = SDL_GetTicks() - time;
        if (toWait < 16)
            SDL_Delay(16 - toWait);
    }
    DestroyMain();
    return (0);
}