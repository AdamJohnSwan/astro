module;
#include <raylib.h>
#include <memory>
#include <di.hpp>

module Main;
import Config;
import Enums;
import ITimerFactory;
import TimerFactory;
import Mediator;
import IMediator;
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

    SetMusicVolume(music, 1.0f);
    PlayMusicStream(music);

    ITimerFactory& timerFactory = serviceContainer.timerFactory;
    baseScene.Load();
    while (!WindowShouldClose())
    {
        timerFactory.UpdateTimers();
        UpdateMusicStream(music);
        baseScene.Update();
        baseScene.Draw();
    }

    baseScene.Unload();

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
        di::bind<IMediator>.to<Mediator>()
    );
    auto app = injector.create<Main>();

    return app.Run();
}