export module IRouter;
import Enums;

export class IRouter
{
public:
	virtual void SetRoute(RoutePaths::Path path) = 0;
};