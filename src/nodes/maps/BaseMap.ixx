module;
#include <raylib.h>

export module BaseMap;
import Node;
import BaseShip;

export class BaseMap : public Node
{
private:
	BaseShip& baseShip;
public:
	BaseMap(ServiceContainer& serviceContainer, BaseShip& baseShip) : Node(serviceContainer), baseShip(baseShip)
	{
	
	}
	const char* GetNodeName() override
	{
		return "BaseMap";
	}
	void Load() override
	{
		baseShip.Load();
	};
	void Update() override
	{
		baseShip.Update();
	}
	void Draw() override
	{
		baseShip.Draw();
		BeginMode3D(serviceContainer.camera.GetCamera3d());
		DrawGrid(100, 10.0f);
		EndMode3D();
	}
	void Unload() override
	{
		baseShip.Unload();
	}
};