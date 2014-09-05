#include "header.h"

int countUpdateInvaderShip = 0;
int deadInvaderShip        = 0;

void LoadContentInvaderShip() {
    tInvaderShip = IMG_LoadTexture(Renderer, "img/invader/invader1_600x3600_P_600.png");
}

void UnLoadInvaderShip() {
    SDL_DestroyTexture(tInvaderShip);
}

void DrawInvaderShip() {
    SDL_RenderCopy(Renderer, tInvaderShip, &InvaderShip->Part, &InvaderShip->Position);
}

void UpdateInvaderShip() {
    // if (countUpdateInvaderShip % 3 == 0){
    //     if (InvaderShip->Part.x <= 0)
    //     {
    //         InvaderShip->Part.x = 600;
    //     }else if (InvaderShip->Part.x >= 600)
    //     {
    //         InvaderShip->Part.x == 0;
    //     }
    // }

    if (countUpdateInvaderShip > 30)
    {
        deadInvaderShip = 1;
    }
    DeadInvaderShip();
    countUpdateInvaderShip += 1;
}

void ShotInvaderShip() {}

void DeadInvaderShip() {
    if (countUpdateInvaderShip % 5 == 0 && deadInvaderShip == 1) {
        InvaderShip->Part.x = 1200;
        deadInvaderShip     = 2;
    } else if (countUpdateInvaderShip % 5 == 0 && deadInvaderShip == 2) {
        InvaderShip->Part.x = 1800;
        deadInvaderShip     = 3;
    } else if (countUpdateInvaderShip % 5 == 0 && deadInvaderShip == 3) {
        InvaderShip->Part.x = 2400;
        deadInvaderShip     = 4;
    } else if (countUpdateInvaderShip % 5 == 0 && deadInvaderShip == 4) {
        InvaderShip->Part.x = 3000;
        deadInvaderShip     = 5;
    } else if (countUpdateInvaderShip % 5 == 0 && deadInvaderShip == 5) {
        deadInvaderShip = 0;
        DestroyInvaderShip();
    }
}

void DestroyInvaderShip() {
    UnLoadInvaderShip();
    free(InvaderShip);
}


void InitInvaderShip() {
    InvaderShip = (struct InvaderShipStruct *) malloc(sizeof(struct InvaderShipStruct) + 1);
    InvaderShip->Position.x = 5;
    InvaderShip->Position.y = 5;
    InvaderShip->Position.w = 70;
    InvaderShip->Position.h = 70;

    InvaderShip->Part.x = 0;
    InvaderShip->Part.y = 0;
    InvaderShip->Part.w = 600;
    InvaderShip->Part.h = 600;
}
