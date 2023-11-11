module;
#include <string>

export module ITimerFactory;

export class ITimerFactory
{
public:
    virtual void StartTimer(std::string name, float lifetime) = 0;

    /// <summary>
    /// Should be called on every frame in order to update the time left in the timers.
    /// </summary>
    virtual void UpdateTimers() = 0;

    virtual float TimeLeft(std::string name) const = 0;
};