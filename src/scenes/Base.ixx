module;
#include <raylib.h>
#include <functional>
#include <memory>

export module Base;
import Scene;
import ServiceContainer;
import LogoScreen;
import GameplayScreen;
import EndingScreen;
import IMediator;
import Enums;

export class Base : public Scene
{
private:
	Sound fxCoin = { 0 };
	LogoScreen& logoScreen;
	GameplayScreen& gameplayScreen;
	EndingScreen& endingScreen;
	Scene* currentScene = nullptr;
	Scene* nextScene = nullptr;

	std::shared_ptr<IMediator::DataHandler> sceneEndedEventToken;
	std::shared_ptr<IMediator::DataHandler> clickEventToken;

	void HandleSceneEnded(Data& data)
	{
		nextScene = &gameplayScreen;
	}
	void HandleClick(Data& data)
	{
		PlaySound(fxCoin);
		if (data.PublisherName == "EndingScreen")
		{
			nextScene = &gameplayScreen;
		}
		else {
			nextScene = &endingScreen;
		}
	}
	void ChangeScene()
	{
		if (nextScene != nullptr)
		{
			currentScene->Unload();
			currentScene = nextScene;
			nextScene = nullptr;
			currentScene->Load();
		}
	}
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
		sceneEndedEventToken = serviceContainer.mediator.Subscribe(Events::SCENE_ENDED, [&](Data& d)
		{
			HandleSceneEnded(d);
		});
		clickEventToken = serviceContainer.mediator.Subscribe(Events::CLICK, [&](Data& d)
		{
			HandleClick(d);
		});

		fxCoin = LoadSound("resources/coin.wav");
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
		if (nextScene != nullptr)
		{
			ChangeScene();
		}
	}
	virtual void Unload() override
	{
		if (sceneEndedEventToken != nullptr)
		{
			serviceContainer.mediator.UnSubscribe(Events::SCENE_ENDED, sceneEndedEventToken);
		}
		if (clickEventToken != nullptr)
		{
			serviceContainer.mediator.UnSubscribe(Events::SCENE_ENDED, clickEventToken);
		}

		UnloadSound(fxCoin);

		if (currentScene != nullptr)
		{
			currentScene->Unload();
		}
	}
};