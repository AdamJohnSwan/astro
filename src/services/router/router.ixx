module;
#include <string>

export module Router;

import IRouter;
import Enums;

export class Router : public IRouter
{

public:
	void SetRoute(RoutePaths::Path path);
};