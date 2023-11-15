module;
#include <raylib.h>
export module Camera;
import ICamera;

export class CameraService : public ICamera
{
private:
	Camera3D camera = { 0 };
	bool cameraInUse = false;
public:
	CameraService()
	{
		camera.position = { 0.0f, 50.0f, -120.0f };
		camera.target =  { 0.0f, 0.0f, 0.0f };
		camera.up =  { 0.0f, 1.0f, 0.0f };
		camera.fovy = 30.0f;
		camera.projection = CAMERA_CUSTOM;
	}
	void UpdateCamera3d(Vector3 position, Vector3 target, Vector3 up, float fovy = 0, CameraMode projection = CameraMode::CAMERA_CUSTOM) override
	{
		camera.position = position;
		camera.target = target;
		camera.up = up;
		if (fovy != 0)
		{
			camera.fovy = fovy;
		}
		if (camera.projection != projection)
		{
			camera.projection = projection;
		}

	}
	const Camera3D& GetCamera3d() override
	{
		return camera;
	}

	void SetUseCamera(bool use) override
	{
		cameraInUse = use;
	}
	bool UseCamera() override
	{
		return cameraInUse;
	}
};