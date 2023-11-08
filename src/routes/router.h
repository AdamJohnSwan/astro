#ifndef ROUTER_H
#define ROUTER_H

#include <memory>
#include <string>
#include <gsl>

#include "interfaces/scene.h"
#include "scenes/LogoScreen.h"
#include "scenes/GameplayScreen.h"
#include "scenes/EndingScreen.h"

namespace RoutePaths
{
	enum Path
	{
		LOGO = 0,
		GAMEPLAY,
		ENDING
	};
}


class Router
{
private:
	RoutePaths::Path currentRoute;
	gsl::not_null<Scene*> GetCurrentScene();
	LogoScreen logoScreen;
	GameplayScreen gameplayScreen;
	EndingScreen endingScreen;

public:
	void SetRoute(RoutePaths::Path path);
	void RenderRoute();
};
#endif // ROUTER_H