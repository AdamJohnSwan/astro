module;

export module LogoScreen;
import Scene;
import ServiceContainer;
import ITimerFactory;
import IRouter;

export class LogoScreen : public Scene
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

public:
	LogoScreen(ServiceContainer& serviceContainer);
	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
};
