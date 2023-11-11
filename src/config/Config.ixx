module;

export module Config;

export struct Config
{
	int screenWidth = 450;
	int screenHeight = 800;
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