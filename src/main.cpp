module;
#include <raylib.h>
#include <memory>
#include <di.hpp>

module Main;
import Config;
import Enums;
import TimerFactory;
import ITimerFactory;
import Mediator;
import IMediator;
import Camera;
import ICamera;
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

    ITimerFactory& timerFactory = serviceContainer.timerFactory;
    baseScene.Load();
    while (!WindowShouldClose())
    {
        timerFactory.UpdateTimers();
        baseScene.Update();
        baseScene.Draw();
    }

    baseScene.Unload();

    CloseAudioDevice();
    CloseWindow();

    return 0;

}

int main(void)
{

    namespace di = boost::di;
    auto injector = di::make_injector(
        di::bind<ITimerFactory>.to<TimerFactory>(),
        di::bind<IMediator>.to<Mediator>(),
        di::bind<ICamera>.to<CameraService>()
    );
    auto app = injector.create<Main>();

    return app.Run();
}