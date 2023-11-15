module;
#include <raylib.h>

export module EndingScreen;
import Node;
import IMediator;
import ServiceContainer;

export class EndingScreen : public Node, IPublisher
{
private:
    Font font = { 0 };
public:
    EndingScreen(ServiceContainer& serviceContainer) : Node(serviceContainer) {
    
    }
    const char* GetNodeName() override
    {
        return "EndingScreen";
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
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);

        Vector2 const pos = { 20, 10 };
        DrawTextEx(font, "ENDING SCREEN", pos, font.baseSize * 3.0f, 4, DARKBLUE);
        DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
    }
    void Unload() override
    {
        UnloadFont(font);
    }
};