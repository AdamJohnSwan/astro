#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include "interfaces/scene.h"

class GameplayScreen : public Scene
{
private:
	int framesCounter;
public:
	GameplayScreen();
	virtual ~GameplayScreen();
	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
};

#endif
