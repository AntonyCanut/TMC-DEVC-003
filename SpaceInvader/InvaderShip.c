#include "header.h"

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
    if (InvaderShip->Position.x < ((SCREEN_WIDTH / 2) - 150)) {
        InvaderShip->Position.x += 4;
        InvaderShip->Position.y -= 1;
    } else if (InvaderShip->Position.x > SCREEN_WIDTH + 400) {
        InvaderShip->Position.x = -400;
        InvaderShip->Position.y = 400;
    } else {
        InvaderShip->Position.x += 4;
        InvaderShip->Position.y += 1;
    }
}

void DeadInvaderShip() {
    InvaderShip->Part.x = 12800;
    InvaderShip->Part.y = 0;
    InvaderShip->Part.w = 3200;
    InvaderShip->Part.h = 3200;
}

void DestroyInvaderShip() {
    UnLoadInvaderShip();
    free(InvaderShip);
}


void InitInvaderShip() {
    InvaderShip = (struct InvaderShipStruct *) malloc(sizeof(struct InvaderShipStruct) + 1);
    InvaderShip->Position.x = -400;
    InvaderShip->Position.y = 400;
    InvaderShip->Position.w = 300;
    InvaderShip->Position.h = 300;

    InvaderShip->Part.x = 0;
    InvaderShip->Part.y = 0;
    InvaderShip->Part.w = 3200;
    InvaderShip->Part.h = 3200;

    // InvaderShip->LoadContent = LoadContentMoon();
    // Moon->UnLoadContent = UnLoadContentMoon();
    // Moon->Draw = DrawMoon();
    // Moon->Update = UpdateMoon();
    // Moon->Dead = DeadMoon();
}
