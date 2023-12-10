module;
#include <raylib.h>
#include <rcamera.h>
#include <raymath.h>
#include <string>
#include <rcamera.h>
#include <iostream>

export module BaseShip;
import Node;

export class BaseShip : public Node
{
private:
	Model ship = { 0 };
	Texture2D texture = { 0 };
	Vector3 shipPos = { 0.0f, 0.0f, 0.0f };
public:
	BaseShip(ServiceContainer& serviceContainer) : Node(serviceContainer) {
	}
	const char* GetNodeName() override
	{
		return "BaseShip";
	}
	void Load() override
	{
		ship = LoadModel("resources/models/shuttle.glb");
		ship.transform = MatrixRotateXYZ({ 0, DEG2RAD * 90, DEG2RAD * 90 });
	};
	void Update() override
	{
		float pitch = 0.0f;
		float roll = 0.0f;
		float yaw = 0.0f;

		float forward = 0.0f;

		if (IsKeyDown(KEY_W))
		{
			forward += 0.6f;
		}
		else if (IsKeyDown(KEY_S))
		{
			forward -= 0.6f;
		}
		
		if (IsKeyDown(KEY_DOWN)) pitch += 0.6f;
		else if (IsKeyDown(KEY_UP)) pitch -= 0.6f;

		if (IsKeyDown(KEY_E)) yaw -= 1.0f;
		else if (IsKeyDown(KEY_Q)) yaw += 1.0f;

		if (IsKeyDown(KEY_LEFT)) roll -= 1.0f;
		else if (IsKeyDown(KEY_RIGHT)) roll += 1.0f;

		ship.transform = MatrixMultiply(MatrixRotateXYZ({ DEG2RAD * yaw, DEG2RAD * roll, DEG2RAD * pitch }), ship.transform);
		serviceContainer.camera.FollowTarget(shipPos, { yaw, pitch, roll });
	}
	void Draw() override
	{
		BeginMode3D(serviceContainer.camera.GetCamera3d());
		DrawModel(ship, shipPos, 10.0f, RED);
		EndMode3D();
	}
	void Unload() override
	{
		UnloadModel(ship);
	}
};