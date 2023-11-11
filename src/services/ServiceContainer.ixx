module;

export module ServiceContainer;
import ITimerFactory;
import IRouter;

export class ServiceContainer
{
public:
	ServiceContainer(ITimerFactory& tf, IRouter& r) : timerFactory(tf), router(r)
	{}
	ITimerFactory& timerFactory;
	IRouter& router;

};