module;
#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>
export module Camera;
import ICamera;

export class CameraService : public ICamera
{
private:
	Camera3D camera = { 0 };
public:
	CameraService()
	{
		camera.position = { 0.0f, 120.0f, -120.0f };
		//camera.position = { 0.0f, 25.0f, -120.0f };
		camera.target =  { 0.0f, 0.0f, 0.0f };
		camera.up =  { 0.0f, 0.0f, 1.0f };
		camera.fovy = 30.0f;
		camera.projection = CAMERA_PERSPECTIVE;
	}
	void UpdateCamera3d(Vector3 position, Vector3 target, Vector3 up, float fovy = 0) override
	{
		camera.position = position;
		camera.target = target;
		camera.up = up;
		if (fovy != 0)
		{
			camera.fovy = fovy;
		}
	}

	void FollowTarget(Vector3 targetLocation, Vector3 targetRotation) override
	{
		camera.target = targetLocation;
		
		if (IsKeyPressed(KEY_LEFT_CONTROL))
		{
			__debugbreak();
		}

		//CameraPitch(&camera, -targetRotation.y * DEG2RAD, false, true, true);
		
		//CameraRoll(&camera, targetRotation.z * DEG2RAD);
		//CameraYaw(&camera, targetRotation.z * DEG2RAD, true);

		Vector3 i = { camera.up.x, camera.up.z, camera.up.y };

		CameraYawTest(i, targetRotation.x * DEG2RAD);
		
	}

	const Camera3D& GetCamera3d() override
	{
		return camera;
	}

	void CameraYawTest(Vector3 axis, float angle)
	{
		Matrix rotation = MatrixRotate(axis, angle);
		Vector3 view = Vector3Subtract(camera.position, camera.target);
		view = Vector3Transform(view, rotation);
		Vector3 pos = Vector3Add(camera.target, view);
		camera.position = { pos.x, camera.position.y, pos.z };
	}
};