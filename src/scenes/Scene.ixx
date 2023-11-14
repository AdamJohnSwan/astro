module;
#include <memory>
export module Scene;

import ServiceContainer;

export class Scene
{
protected:
	ServiceContainer& serviceContainer;
public:
	Scene(ServiceContainer& serviceContainer) : serviceContainer(serviceContainer) {
	}
	virtual const char* GetSceneName()
	{
		return typeid(this).name();
	}
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;
};