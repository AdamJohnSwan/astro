module;
#include <raylib.h>
#include <memory>
#include <di.hpp>

module Main;
import Config;
import Enums;
import ITimerFactory;
import TimerFactory;
import Router;
import IRouter;
import ServiceContainer;

Main::Main(ServiceContainer& serviceContainer, Base& baseScene) :
    serviceContainer(serviceContainer), baseScene(baseScene)
{

}

int Main::Run()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    const Config& config = GetConfig();
    SetTargetFPS(config.fps);
    InitWindow(config.screenWidth, config.screenHeight, "raylib game template");

    InitAudioDevice();
    Music music = LoadMusicStream("resources/ambient.ogg");

    SetMusicVolume(music, 0.5f);
    PlayMusicStream(music);

    IRouter& router = serviceContainer.router;
    ITimerFactory& timerFactory = serviceContainer.timerFactory;
    baseScene.Load();
    while (!WindowShouldClose())
    {
        timerFactory.UpdateTimers();
        UpdateMusicStream(music);
        baseScene.Update();
        baseScene.Draw();
    }

    UnloadMusicStream(music);

    CloseAudioDevice();

    CloseWindow();

    return 0;

}

int main(void)
{

    namespace di = boost::di;
    auto injector = di::make_injector(
        di::bind<ITimerFactory>.to<TimerFactory>(),
        di::bind<IRouter>.to<Router>()
    );
    auto app = injector.create<Main>();

    return app.Run();
}