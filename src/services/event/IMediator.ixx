module;
#include <functional>
#include <memory>

export module IMediator;
import Enums;

export class IPublisher
{
};

export class Data
{
public:
	Data(IPublisher& sender) :
		Sender(sender),
		PublisherName(typeid(Sender).name())
	{
	}
	Data(IPublisher& sender, const char* publisherName) :
		Sender(sender),
		PublisherName(publisherName)
	{
	}
	const IPublisher& Sender;
	const char* PublisherName;
};

export class IMediator
{
public:
	typedef std::function<void(Data&)> DataHandler;
	virtual std::shared_ptr<DataHandler> Subscribe(Events::EventType eventType, DataHandler handler) = 0;
	virtual void UnSubscribe(Events::EventType eventType, std::shared_ptr<DataHandler> handler) = 0;
	
	virtual void Publish(Events::EventType eventType, Data& data) = 0;
};
