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
		// save a variable because the value returned by this function can change in the Update call.
		bool cameraInUse = serviceContainer.camera.UseCamera();
		if (cameraInUse)
		{
			BeginMode3D(serviceContainer.camera.GetCamera3d());
		}
		if (currentScene != nullptr)
		{
			currentScene->Draw();
		}
		if (cameraInUse)
		{
			EndMode3D();
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