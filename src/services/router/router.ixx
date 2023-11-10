module;
#include <memory>
#include <string>

export module Router;
import Scene;
import LogoScreen;
import GameplayScreen;
import EndingScreen;

namespace RoutePaths
{
	enum Path
	{
		LOGO = 0,
		GAMEPLAY,
		ENDING
	};
}


export class Router
{
private:
	RoutePaths::Path currentRoute;
	Scene* GetCurrentScene();
	LogoScreen logoScreen;
	GameplayScreen gameplayScreen;
	EndingScreen endingScreen;

public:
	void SetRoute(RoutePaths::Path path);
	void RenderRoute();
};