module;
#include <raylib.h>

module GameplayScreen;
import Main;
import Enums;

GameplayScreen::GameplayScreen(ServiceContainer& serviceContainer) : Scene(serviceContainer)
{
}

void GameplayScreen::Load()
{
    font = LoadFont("resources/mecha.png");
    fxCoin = LoadSound("resources/coin.wav");
}

void GameplayScreen::Update()
{
    // Press enter or tap to return to TITLE screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        serviceContainer.router.SetRoute(RoutePaths::ENDING);
        PlaySound(fxCoin);
    }
}

void GameplayScreen::Draw()
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
    Vector2 pos = { 20, 10 };
    DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize * 3.0f, 4, MAROON);
    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
}

void GameplayScreen::Unload()
{
    UnloadFont(font);
    UnloadSound(fxCoin);
}
