#ifndef ENDINGSCREEN_H
#define ENDINGSCREEN_H

#include "interfaces/scene.h"

class EndingScreen : public Scene
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

#endif