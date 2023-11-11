module;
#include <raylib.h>

export module Base;
import Scene;
import ServiceContainer;
import LogoScreen;
import GameplayScreen;
import EndingScreen;

export class Base : public Scene
{
private:
	LogoScreen& logoScreen;
	GameplayScreen& gameplayScreen;
	EndingScreen& endingScreen;
	Scene* currentScene = nullptr;
public:
	Base(ServiceContainer& serviceContainer,
		LogoScreen& logoScreen,
		GameplayScreen& gameplayScreen,
		EndingScreen& endingScreen) : Scene(serviceContainer), logoScreen(logoScreen), gameplayScreen(gameplayScreen), endingScreen(endingScreen)
	{
		currentScene = &logoScreen;
	}
	void Load() override
	{
		if (currentScene != nullptr)
		{
			currentScene->Load();
		}
	}
	virtual void Update() override
	{
		if (currentScene != nullptr)
		{
			currentScene->Update();
		}
	}
	virtual void Draw() override
	{
		BeginDrawing();
		if (currentScene != nullptr)
		{
			currentScene->Draw();
		}
		EndDrawing();
	}
	virtual void Unload() override
	{
		if (currentScene != nullptr)
		{
			currentScene->Unload();
		}
	}
};