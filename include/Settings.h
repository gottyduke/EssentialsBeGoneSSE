#pragma once

#include "Json2Settings.h"

namespace J2S = Json2Settings;

class Settings
{
public:

	Settings() = delete;

	static bool	LoadSettings(bool a_dumpParse = false);

	static J2S::bSetting			enforceQuest;
	static J2S::bSetting			heartOfFury;
	static J2S::bSetting			excludeNPC;
	static J2S::aSetting<UInt32>	exclusionList;

private:
	static constexpr char* FILE_NAME = "Data\\SKSE\\Plugins\\EssentialsBeGoneSSE.json";
};
