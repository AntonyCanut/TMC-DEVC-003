#include "../Headers/header.h"

int countUpdateInvader = 0;
int deadInvader        = 0;

void LoadContentInvader(InvaderStruct *Invader) {
    switch (Invader->Sprite) {
        case 2 :
         Invader->Texture = IMG_LoadTexture(Renderer, "img/invader/invader2_600x3600_P_600.png");
         break;
        case 3 :
         Invader->Texture = IMG_LoadTexture(Renderer, "img/invader/invader3_600x3600_P_600.png");
         break;
        case 4:
         Invader->Texture = IMG_LoadTexture(Renderer, "img/invader/invader4_600x3600_P_600.png");
         break;
        default: 
         Invader->Texture = IMG_LoadTexture(Renderer, "img/invader/invader1_600x3600_P_600.png");
    }    
}

void UnLoadContentInvader(InvaderStruct *Invader) {
    SDL_DestroyTexture(Invader->Texture);
}

void DrawInvader(InvaderStruct *Invader) {
    SDL_RenderCopy(Renderer, Invader->Texture, &Invader->Part, &Invader->Position);
}

void UpdateInvader(InvaderStruct *Invader) {
    Uint32 ShootInvTmp=0;
    int i = 0;
    int random = 0;

    if (countUpdateInvader % 17 == 0) {
        if (Invader->Part.x <= 0) {
            Invader->Part.x = 600;
        } else if (Invader->Part.x >= 600) {
            Invader->Part.x = 0;
        }
    }

    if (countUpdateInvader % 2 == 0) {
        if (rightInvader == true) {
            Invader->Position.x += 2;
            if (Invader->Position.x >= (SCREEN_WIDTH - 70)) {
                rightInvader = false;
                Invaders *InvaderListTemp = InvaderList;
                while (InvaderListTemp != NULL)
                {
                    InvaderListTemp->Current->Position.x -= 5;
                    InvaderListTemp->Current->Position.y += 20;
                    InvaderListTemp = InvaderListTemp->Next;
                }
            }
        } else {
            Invader->Position.x -= 2;
            if (Invader->Position.x <= 10) {
                rightInvader = true;
                Invaders *InvaderListTemp = InvaderList;
                while (InvaderListTemp != NULL)
                {
                    InvaderListTemp->Current->Position.x += 5;
                    InvaderListTemp->Current->Position.y += 20;
                    InvaderListTemp = InvaderListTemp->Next;
                }
            }
        }
    }
    srand(time(NULL));
    Bullets *ShotList = ShipShootList;
    while (ShotList != NULL)
    {
        if (ShotList->Current->Direction==1 && ShotList->Current->ShootTime > ShootInvTmp)
        {
            ShootInvTmp=ShotList->Current->ShootTime;
        }
        ShotList = ShotList->Next;
    }
    if ((SDL_GetTicks() - ShootInvTmp) > 700)
    {
        random = random_number(0, 24);
        Invaders *InvaderListTemp = InvaderList;
        for(i=0; i<=random && InvaderListTemp != NULL; i++)
        {
            InvaderListTemp = InvaderListTemp->Next;
        }
        InvaderListTemp->Current->Shot(InvaderListTemp->Current);
    }
    // if (countUpdateInvaderShip == 30)
    // {
    //     deadInvaderShip = 1;
    // }
    // DeadInvaderShip();
    countUpdateInvader += 2;
}

void ShotInvader(InvaderStruct *Invader) {
        // /* On crée un nouvel élément */
    BulletStruct *MyBullet = InitBullet(&Invader->Position, 1, Invader->Sprite);
    ShipShootList = AddAtFrontBulletList(ShipShootList, MyBullet);
    Mix_PlayChannel(4, sonTir, 0);
    //  On assigne la valeur au nouvel élément 
    // newShoot->val = InitShipShoot();
 
    // /* On assigne l'adresse de l'élément suivant au nouvel élément */
    // newShoot->nxt = ShipShootList;
}

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


InvaderStruct *InitInvader(int x, int Line, int Sprite) {
    InvaderStruct *Invader;
    Invader = malloc(sizeof(*Invader));
    Invader->Position.x = x;
    Invader->Position.y = 5 + (75 * Line);
    Invader->Position.w = 70;
    Invader->Position.h = 70;

    rightInvader = true;
    Invader->Sprite = Sprite;

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
