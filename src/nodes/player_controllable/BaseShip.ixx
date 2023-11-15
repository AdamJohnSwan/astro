module;
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>

export module BaseShip;
import Node;

export class BaseShip : public Node
{
private:
	Model ship = { 0 };
	Texture2D texture = { 0 };
	float pitch = 0.0f;
	float roll = 0.0f;
	float yaw = 0.0f;
	Vector3 shipPos = { 0.0f, -8.0f, 0.0f };
public:
	BaseShip(ServiceContainer& serviceContainer) : Node(serviceContainer) {
	}
	const char* GetNodeName() override
	{
		return "BaseShip";
	}
	void Load() override
	{
		serviceContainer.camera.SetUseCamera(true);
	};
	void Update() override
	{
		if (IsKeyDown(KEY_W))
		{
			shipPos.z += 0.6f;
		}

		if (IsKeyDown(KEY_DOWN)) pitch += 0.6f;
		else if (IsKeyDown(KEY_UP)) pitch -= 0.6f;

		if (IsKeyDown(KEY_S)) yaw -= 1.0f;
		else if (IsKeyDown(KEY_A)) yaw += 1.0f;

		if (IsKeyDown(KEY_LEFT)) roll -= 1.0f;
		else if (IsKeyDown(KEY_RIGHT)) roll += 1.0f;

		ship.transform = MatrixRotateXYZ({ DEG2RAD* pitch, DEG2RAD* yaw, DEG2RAD* roll });
		const Camera3D& camera = serviceContainer.camera.GetCamera3d();
		Vector3 newPos = { camera.position.x, camera.position.y, shipPos.z - 120.0f};
		serviceContainer.camera.UpdateCamera3d(newPos, shipPos, camera.up);
	}
	void Draw() override
	{
		rlPushMatrix();
		rlRotatef(pitch, 1, 0, 0);
		rlRotatef(yaw, 0, 1, 0);
		rlRotatef(roll, 0, 0, 1);
		DrawCube(shipPos, 25.0f, 25.0f, 50.0f, BLUE);

		Vector3 wingsPos = { shipPos.x, shipPos.y, shipPos.z };
		DrawCube(wingsPos, 80.0f, 15.0f, 25.0f, RED);
		rlPopMatrix();
	}
	void Unload() override
	{
		serviceContainer.camera.SetUseCamera(false);
	}
};