module;

export module Enums;

namespace RoutePaths
{
	export enum Path
	{
		LOGO = 0,
		GAMEPLAY,
		ENDING
	};
}

namespace Events
{
	export enum EventType
	{
		UNKNOWN = 0,
		SCENE_ENDED,
		CLICK,
		LAST
	};
}