#include "Settings.h"

bool Settings::LoadSettings(bool a_dumpParse = false)
{
	auto [log, success] = Json2Settings::load_settings(FILE_NAME, a_dumpParse);
	if (!log.empty()) {
		_ERROR("%s", log.c_str());
	}

	return success;
}

decltype(Settings::enforceQuest)	Settings::enforceQuest("enforceQuest", true);
decltype(Settings::heartOfFury)		Settings::heartOfFury("heartOfFury", false);
decltype(Settings::exclusionList)	Settings::exclusionList("exclusionList");
