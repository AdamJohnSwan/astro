module;
#include <string>
#include <memory>
#include <stdexcept>
#include <raylib.h>

module Router;

void Router::SetRoute(RoutePaths::Path path)
{
	Scene* oldScene = GetCurrentScene();
	oldScene->Unload();
	currentRoute = path;
	Scene* newScene = GetCurrentScene();
	newScene->Load();
}

Scene* Router::GetCurrentScene()
{
	switch (currentRoute)
	{
		case(RoutePaths::LOGO):
			return &logoScreen;
		case(RoutePaths::GAMEPLAY):
			return &gameplayScreen;
		case(RoutePaths::ENDING):
			return &endingScreen;
		default:
			throw std::invalid_argument("Received invalid path");
	}
}

void Router::RenderRoute()
{
	Scene* scene = GetCurrentScene();
	scene->Update();
	BeginDrawing();
	DrawFPS(10, 10);
	scene->Draw();
	EndDrawing();
}