module;
#include <raylib.h>

export module EndingScreen;
import Scene;
import IRouter;
import ServiceContainer;

export class EndingScreen : public Scene
{
private:
    Font font = { 0 };
    Sound fxCoin = { 0 };
public:
    EndingScreen(ServiceContainer& serviceContainer);
    void Load() override;
    void Update() override;
    void Draw() override;
    void Unload() override;
};