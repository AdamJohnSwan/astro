module;

export module LogoScreen;
import Scene;
import TimerService;

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

	TimerService timerService;

public:
	LogoScreen();
	virtual ~LogoScreen();
	void Load() override;
	void Update() override;
	void Draw() override;
	void Unload() override;
};
