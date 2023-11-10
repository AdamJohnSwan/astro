module;

export module EndingScreen;
import Scene;

export class EndingScreen : public Scene
{
private:
    int frameCounter;
public:
    EndingScreen();
    virtual ~EndingScreen();
    void Load() override;
    void Update() override;
    void Draw() override;
    void Unload() override;
};
