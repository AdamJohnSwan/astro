module;
#include <raylib.h>
export module ICamera;

export class ICamera
{
public:
	virtual void UpdateCamera3d(Vector3 position, Vector3 target, Vector3 up, float fovy = 0) = 0;
	virtual void FollowTarget(Vector3 targetLocation, Vector3 targetRotation) = 0;
	virtual const Camera3D& GetCamera3d() = 0;
};