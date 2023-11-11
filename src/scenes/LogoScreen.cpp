module;
#include <raylib.h>

module LogoScreen;
import Enums;

LogoScreen::LogoScreen(ServiceContainer& serviceContainer) : Scene(serviceContainer)
{
    framesCounter = 0;

    logoPositionX = 0;
    logoPositionY = 0;

    lettersCount = 0;

    topSideRecWidth = 0;
    leftSideRecHeight = 0;

    bottomSideRecWidth = 0;
    rightSideRecHeight = 0;

    state = 0;
    alpha = 1.0f;
}

void LogoScreen::Load()
{
    framesCounter = 0;
    lettersCount = 0;

    logoPositionX = GetScreenWidth() / 2 - 128;
    logoPositionY = GetScreenHeight() / 2 - 128;

    topSideRecWidth = 16;
    leftSideRecHeight = 16;
    bottomSideRecWidth = 16;
    rightSideRecHeight = 16;

    state = 0;
    alpha = 1.0f;
    serviceContainer.timerFactory.StartTimer("state0", 1);
}

void LogoScreen::Update()
{   
    ITimerFactory& timerFactory = serviceContainer.timerFactory;
    if (state == 0)                 // State 0: Top-left square corner blink logic
    {
        // First, a second before showing anything
        if (timerFactory.TimeLeft("state0") == 0)
        {
            timerFactory.StartTimer("state1", 2);
            state = 1;
        }
    }
    else if (state == 1)            // State 1: Bars animation logic: top and left
    {
        float timeLeft = timerFactory.TimeLeft("state1");
        topSideRecWidth = static_cast<int>(256.0 * ((1.0 - timeLeft) / 1.0));
        leftSideRecHeight = static_cast<int>(256.0 * ((1.0 - timeLeft) / 1.0));

        if (timeLeft == 0)
        {
            timerFactory.StartTimer("state2", 1);
            state = 2;
        }
    }
    else if (state == 2)            // State 2: Bars animation logic: bottom and right
    {
        float timeLeft = timerFactory.TimeLeft("state2");
        bottomSideRecWidth = static_cast<int>(256.0 * ((1.0 - timeLeft) / 1.0));
        rightSideRecHeight = static_cast<int>(256.0 * ((1.0 - timeLeft) / 1.0));

        if (timeLeft == 0)
        {
            timerFactory.StartTimer("letterCounter", 0.2f);
            state = 3;
        }
    }
    else if (state == 3)            // State 3: "raylib" text-write animation logic
    {
        if (timerFactory.TimeLeft("letterCounter") == 0)
        {
            lettersCount++;
            timerFactory.StartTimer("letterCounter", 0.2f);
        }
        if (lettersCount == 10)
        {
            timerFactory.StartTimer("fadeOutTimer", 0.5f);
            state = 4;
        }
    }
    else if (state = 4)
    {
        float timeLeft = timerFactory.TimeLeft("fadeOutTimer");
        alpha = timeLeft / 0.5f;

        if (timeLeft == 0)
        {
            alpha = 0.0f;
            serviceContainer.router.SetRoute(RoutePaths::GAMEPLAY);
        }
    }
}

//  Screen Draw logic
void LogoScreen::Draw()
{
    ClearBackground(RAYWHITE);

    if (state == 0)         // Draw blinking top-left square corner
    {
        if ((framesCounter / 10) % 2) DrawRectangle(logoPositionX, logoPositionY, 16, 16, BLACK);
    }
    else if (state == 1)    // Draw bars animation: top and left
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);
    }
    else if (state == 2)    // Draw bars animation: bottom and right
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, BLACK);
        DrawRectangle(logoPositionX, logoPositionY, 16, leftSideRecHeight, BLACK);

        DrawRectangle(logoPositionX + 240, logoPositionY, 16, rightSideRecHeight, BLACK);
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, BLACK);
    }
    else if (state == 3)    // Draw "raylib" text-write animation + "powered by"
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLACK, alpha));

        DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(BLACK, alpha));

        DrawRectangle(GetScreenWidth() / 2 - 112, GetScreenHeight() / 2 - 112, 224, 224, Fade(RAYWHITE, alpha));

        DrawText(TextSubtext("raylib", 0, lettersCount), GetScreenWidth() / 2 - 44, GetScreenHeight() / 2 + 48, 50, Fade(BLACK, alpha));
    }
    else if (state = 4)
    {
        DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 16, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 16, 16, leftSideRecHeight - 32, Fade(BLACK, alpha));

        DrawRectangle(logoPositionX + 240, logoPositionY + 16, 16, rightSideRecHeight - 32, Fade(BLACK, alpha));
        DrawRectangle(logoPositionX, logoPositionY + 240, bottomSideRecWidth, 16, Fade(BLACK, alpha));

        DrawRectangle(GetScreenWidth() / 2 - 112, GetScreenHeight() / 2 - 112, 224, 224, Fade(RAYWHITE, alpha));

        DrawText(TextSubtext("raylib", 0, lettersCount), GetScreenWidth() / 2 - 44, GetScreenHeight() / 2 + 48, 50, Fade(BLACK, alpha));
    }
}

//  Screen Unload logic
void LogoScreen::Unload()
{
    // Unload LOGO screen variables here!
}