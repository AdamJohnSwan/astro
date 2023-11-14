module;

export module ServiceContainer;
import ITimerFactory;
import IMediator;

export class ServiceContainer
{
public:
	ServiceContainer(ITimerFactory& tf, IMediator& m) : timerFactory(tf), mediator(m)
	{
	}
	ITimerFactory& timerFactory;
	IMediator& mediator;
};