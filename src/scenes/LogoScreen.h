#ifndef LOGOSCREEN_H
#define LOGOSCREEN_H

#include "interfaces/scene.h"
#include "services/timer/timer.h"

class LogoScreen : public Scene
{
private:
	int framesCounter;

	int logoPositionX;
	int logoPositionY;

	int lettersCount;

	int topSideRecWidth;
	int leftSideRecHeight;

	int bottomSideRecWidth;
	int rightSideRecHeight;

	int state;
	float alpha;

	TimerService timerService;

public:
	LogoScreen();
	virtual ~LogoScreen();
	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
};

#endif // !LOGOSCREEN_H
