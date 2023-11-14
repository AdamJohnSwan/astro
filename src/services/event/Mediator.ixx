module;
#include <unordered_map>
#include <vector>
#include <memory>
#include <functional>

export module Mediator;
import Enums;
import IMediator;

export class Mediator : public IMediator
{
private:
	typedef std::vector<std::shared_ptr<DataHandler>> HandlerList;
	std::unordered_map<Events::EventType, HandlerList> eventHandlers;
public:
	~Mediator()
	{
		eventHandlers.clear();
	}
	Mediator(const Mediator& other) = delete;
	Mediator& operator=(const Mediator& other) = delete;

	Mediator()
	{
		using namespace Events;
		for (int i = UNKNOWN; i < LAST; ++i)
		{
			EventType eventType = (EventType)i;
			eventHandlers[eventType] = HandlerList();
		}
		
	}
	std::shared_ptr<DataHandler> Subscribe(Events::EventType eventType, DataHandler handler) override
	{
		auto sharedHandler = std::make_shared<DataHandler>(handler);
		eventHandlers[eventType].push_back(sharedHandler);
		return sharedHandler;
	}

	virtual void UnSubscribe(Events::EventType eventType, std::shared_ptr<DataHandler> handler) override
	{
		HandlerList& handlers = eventHandlers[eventType];
		HandlerList::iterator handlerIndexToRemove = std::find(handlers.begin(), handlers.end(), handler);
		if (handlerIndexToRemove != handlers.end())
		{
			handlers.erase(handlerIndexToRemove);
		}
	}
	void Publish(Events::EventType eventType, Data& data) override
	{
		HandlerList& handlers = eventHandlers[eventType];
		for (std::shared_ptr<DataHandler>& handler : handlers)
		{
			(*handler)(data);
		}
	}
};