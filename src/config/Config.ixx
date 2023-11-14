module;

export module Config;

export struct Config
{
	int screenWidth = 800;
	int screenHeight = 450;
	int fps = 60;
};

Config config;
export const Config& GetConfig()
{
	return config;
}

export void SetConfig(Config newConfig)
{
	config = newConfig;
}