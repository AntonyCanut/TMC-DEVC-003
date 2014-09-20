
#include "../Headers/header.h"

void LoadContentLayout(){
    Background->Load();
    Mars->Load();
    Moon->Load();
}

void UnLoadContentLayout(){
    Background->UnLoad();
    Mars->UnLoad();
    Moon->UnLoad();
}

void DrawLayout(){
    Background->Draw();
    Mars->Draw();
    Moon->Draw();
}

void UpdateLayout(){
    Background->Update();
    Mars->Update();
    Moon->Update();
}

void DestroyLayout(){
    Background->Destroy();
    Mars->Destroy();
    Moon->Destroy();
}


void InitLayout(){
    Layout = malloc(sizeof(*Layout));
    Layout->Load = LoadContentLayout;
    Layout->UnLoad = UnLoadContentLayout;
    Layout->Draw = DrawLayout;
    Layout->Update = UpdateLayout;
    Layout->Destroy = DestroyLayout;
    InitBackground();
    InitMars();
    InitMoon();
    Layout->Load();
}
