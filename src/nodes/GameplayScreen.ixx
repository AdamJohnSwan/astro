module;
#include <raylib.h>

export module GameplayScreen;
import Node;
import IMediator;

export class GameplayScreen : public Node,  IPublisher
{
private:
	Font font = { 0 };
public:
    GameplayScreen(ServiceContainer& serviceContainer) : Node(serviceContainer)
    {
    
    }
    const char* GetNodeName() override
    {
        return "GameplayScreen";
    }
    void Load() override
    {
        font = LoadFont("resources/mecha.png");
    }
    void Update() override
    {
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        {
            Data data = Data(*this, GetNodeName());
            serviceContainer.mediator.Publish(Events::CLICK, data);
        }
    }
    void Draw() override
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
        Vector2 pos = { 20, 10 };
        DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize * 3.0f, 4, MAROON);
        DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
    }
    void Unload() override
    {
        UnloadFont(font);
    }
};