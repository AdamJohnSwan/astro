#ifndef TIMER_H
#define TIMER_H


#include <map>
#include <string>

/// <summary>
/// Timer with a life time in seconds
/// </summary>
typedef struct Timer
{
    float Lifetime;
} Timer;

class TimerService
{
private:
    std::map<std::string, Timer> TimerDictionary;
public:
    void StartTimer(std::string name, float lifetime);

    /// <summary>
    /// Should be called on every frame in order to update the time left in the timers.
    /// </summary>
    void UpdateTimers();

    float TimeLeft(std::string name);
};

#endif // !TIMER_H