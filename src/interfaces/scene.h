#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;
};

#endif 