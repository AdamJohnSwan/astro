module;
#include <raylib.h>

export module GameplayScreen;
import Scene;
import IRouter;

export class GameplayScreen : public Scene
{
private:
	Font font = { 0 };
	Sound fxCoin = { 0 };
public:
	GameplayScreen(ServiceContainer& serviceContainer);
	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
};