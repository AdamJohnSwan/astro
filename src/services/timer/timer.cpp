#include <raylib.h>

#include "timer.h"

void TimerService::StartTimer(std::string name, float lifetime)
{
	if (TimerDictionary.count(name) == 0)
	{
		Timer timer = { 
			{ lifetime }
		};
		TimerDictionary.insert(std::pair<std::string, Timer>(name, timer));
	}
}

void TimerService::UpdateTimers()
{
	std::map<std::string, Timer>::iterator it = TimerDictionary.begin();
	while (it != TimerDictionary.end())
	{
		Timer& timer = it->second;
		timer.Lifetime -= GetFrameTime();
		if (timer.Lifetime <= 0)
		{
			it = TimerDictionary.erase(it);
		}
		else
		{
			++it;
		}
	}
}

/// <summary>
/// Returns the time left on a timer. Will also return 0 for timers that have never been added.
/// </summary>
/// <param name="name">Name of the timer</param>
/// <returns></returns>
float TimerService::TimeLeft(std::string name)
{
	if (TimerDictionary.count(name) > 0)
	{
		return TimerDictionary.at(name).Lifetime;
	}
	// Zero is returned here because timers that are expired are immediately removed from the dictionary.
	return 0;
}