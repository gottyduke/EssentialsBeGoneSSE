#pragma once

#include "Exclusion.h"

#include "Json2Settings.h"


namespace J2S = Json2Settings;

class Settings
{
public:

	Settings() = delete;

	static bool	LoadSettings(bool a_dumpParse = false);

	static J2S::bSetting				heartOfFury;
	static J2S::aSetting<std::string>	exclusionList;

private:
	static constexpr char* FILE_NAME = "Data\\SKSE\\Plugins\\EssentialsBeGoneSSE.json";
};
