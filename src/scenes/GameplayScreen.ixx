module;

export module GameplayScreen;
import Scene;

export class GameplayScreen : public Scene
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
