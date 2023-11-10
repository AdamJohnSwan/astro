module;
#include <raylib.h>

module GameplayScreen;
import Main;

GameplayScreen::GameplayScreen()
{
    framesCounter = 0;
}

GameplayScreen::~GameplayScreen()
{

}

void GameplayScreen::Load()
{

}

void GameplayScreen::Update()
{
    // TODO: Update ENDING screen variables here!

    // Press enter or tap to return to TITLE screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        router.SetRoute(RoutePaths::ENDING);
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
    // TODO: Unload ENDING screen variables here!
}
