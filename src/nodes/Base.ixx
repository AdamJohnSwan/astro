module;
#include <raylib.h>
#include <functional>
#include <memory>

export module Base;
import Node;
import ServiceContainer;
import IMediator;
import Enums;
import BaseMap;

export class Base : public Node
{
private:
	
	BaseMap& baseMap;
	Node* currentScene = nullptr;
public:
	Base(ServiceContainer& serviceContainer,
		BaseMap& baseMap) : Node(serviceContainer), baseMap(baseMap)
	{
		currentScene = &baseMap;
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
		ClearBackground(WHITE);
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