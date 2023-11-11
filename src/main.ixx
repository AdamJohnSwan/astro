module;
#include <raylib.h>

export module Main;
import ServiceContainer;
import Base;

class Main
{
private:
    ServiceContainer& serviceContainer;
    Base& baseScene;
public:
    int Run();
    Main(ServiceContainer& serviceContainer, Base& baseScene);
};

export int main();