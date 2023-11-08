#include <raylib.h>
#include <memory>

#include "main.h"
#include "interfaces/scene.h"
#include "scenes/LogoScreen.h"
#include "routes/router.h"


Font font = {
    0
};
Music music = {
    { nullptr }
};
Sound fxCoin = {
    { nullptr }
};
Router router = Router();

namespace 
{
    static constexpr int screenWidth = 800;
    static constexpr int screenHeight = 450;
}


int main(void)
{

    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(144);
    InitWindow(screenWidth, screenHeight, "raylib game template");

    InitAudioDevice();

    font = LoadFont("resources/mecha.png");
    music = LoadMusicStream("resources/ambient.ogg");
    fxCoin = LoadSound("resources/coin.wav");

    SetMusicVolume(music, 0.0f);
    PlayMusicStream(music);

    router.SetRoute(RoutePaths::LOGO);


    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        router.RenderRoute();
    }

    UnloadFont(font);
    UnloadMusicStream(music);
    UnloadSound(fxCoin);

    CloseAudioDevice();

    CloseWindow();

    return 0;
}