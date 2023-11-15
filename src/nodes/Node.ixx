module;
#include <memory>
export module Node;

import ServiceContainer;

export class Node
{
protected:
	ServiceContainer& serviceContainer;
public:
	Node(ServiceContainer& serviceContainer) : serviceContainer(serviceContainer) {
	}
	virtual const char* GetNodeName()
	{
		return typeid(this).name();
	}
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;
};