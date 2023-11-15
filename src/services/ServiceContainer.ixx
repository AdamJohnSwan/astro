module;

export module ServiceContainer;
import ITimerFactory;
import IMediator;
import ICamera;

export class ServiceContainer
{
public:
	ServiceContainer(ITimerFactory& tf, IMediator& m, ICamera& c) : timerFactory(tf), mediator(m), camera(c)
	{
	}
	ITimerFactory& timerFactory;
	IMediator& mediator;
	ICamera& camera;
};