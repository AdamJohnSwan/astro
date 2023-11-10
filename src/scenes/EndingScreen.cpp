module;
#include <raylib.h>

module EndingScreen;
import Router;
import Main;

EndingScreen::EndingScreen()
{
    frameCounter = 0;
}

EndingScreen::~EndingScreen()
{

}

void EndingScreen::Load()
{
	
}

void EndingScreen::Update()
{
    // TODO: Update ENDING screen variables here!

    // Press enter or tap to return to TITLE screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        PlaySound(fxCoin);
        router.SetRoute(RoutePaths::GAMEPLAY);
    }
}

void EndingScreen::Draw()
{
    // TODO: Draw ENDING screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);

    Vector2 const pos = { 20, 10 };
    DrawTextEx(font, "ENDING SCREEN", pos, font.baseSize * 3.0f, 4, DARKBLUE);
    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
}

void EndingScreen::Unload()
{
    // TODO: Unload ENDING screen variables here!
}
