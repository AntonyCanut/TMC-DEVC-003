#include "../Headers/header.h"

int countUpdateInvader = 0;
int deadInvader        = 0;

void LoadContentInvader(InvaderStruct *Invader) {
    Invader->Texture = IMG_LoadTexture(Renderer, "img/invader/invader1_600x3600_P_600.png");
}

void UnLoadContentInvader(InvaderStruct *Invader) {
    SDL_DestroyTexture(Invader->Texture);
}

void DrawInvader(InvaderStruct *Invader) {
    SDL_RenderCopy(Renderer, Invader->Texture, &Invader->Part, &Invader->Position);
}

void UpdateInvader(InvaderStruct *Invader) {
    if (countUpdateInvader % 17 == 0) {
        if (Invader->Part.x <= 0) {
            Invader->Part.x = 600;
        } else if (Invader->Part.x >= 600) {
            Invader->Part.x = 0;
        }
    }

    if (countUpdateInvader % 2 == 0) {
        if (rightInvader == true) {
            Invader->Position.x += 5;
            if (Invader->Position.x >= (SCREEN_WIDTH - 70)) {
                rightInvader = false;
                Invader->Position.x -= 5;
                Invader->Position.y += 70;
            }
        } else {
            Invader->Position.x -= 5;
            if (Invader->Position.x <= 10) {
                rightInvader = true;
                Invader->Position.x += 5;
                Invader->Position.y += 70;
            }
        }
    }

    // if (countUpdateInvaderShip == 30)
    // {
    //     deadInvaderShip = 1;
    // }
    // DeadInvaderShip();
    countUpdateInvader += 1;
}

void ShotInvader(InvaderStruct *Invader) {}

void DeadInvader(InvaderStruct *Invader) {
    if (countUpdateInvader % 5 == 0 && deadInvader == 1) {
        Invader->Part.x = 1200;
        deadInvader     = 2;
    } else if (countUpdateInvader % 5 == 0 && deadInvader == 2) {
        Invader->Part.x = 1800;
        deadInvader     = 3;
    } else if (countUpdateInvader % 5 == 0 && deadInvader == 3) {
        Invader->Part.x = 2400;
        deadInvader     = 4;
    } else if (countUpdateInvader % 5 == 0 && deadInvader == 4) {
        Invader->Part.x = 3000;
        deadInvader     = 5;
    } else if (countUpdateInvader % 5 == 0 && deadInvader == 5) {
        deadInvader = 0;
        Invader->Destroy(Invader);
    }
}
    
void DestroyInvader(InvaderStruct *Invader) {
    Invader->UnLoad(Invader);
    free(Invader);
}


InvaderStruct *InitInvader(int x) {
    InvaderStruct *Invader;
    Invader = malloc(sizeof(*Invader));
    Invader->Position.x = x;
    Invader->Position.y = 5;
    Invader->Position.w = 70;
    Invader->Position.h = 70;

    rightInvader = true;

    Invader->Part.x = 0;
    Invader->Part.y = 0;
    Invader->Part.w = 600;
    Invader->Part.h = 600;

    Invader->Load = LoadContentInvader;
    Invader->UnLoad = UnLoadContentInvader;
    Invader->Update = UpdateInvader;
    Invader->Draw = DrawInvader;
    Invader->Shot = ShotInvader;
    Invader->Dead = DeadInvader;
    Invader->Destroy = DestroyInvader;
    Invader->Load(Invader);
    return (Invader);
}
