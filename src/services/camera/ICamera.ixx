module;
#include <raylib.h>
export module ICamera;

export class ICamera
{
public:
	virtual void UpdateCamera3d(Vector3 position, Vector3 target, Vector3 up, float fovy = 0, CameraMode projection = CameraMode::CAMERA_CUSTOM) = 0;
	virtual const Camera3D& GetCamera3d() = 0;
	virtual void SetUseCamera(bool use) = 0;
	virtual bool UseCamera() = 0;
};