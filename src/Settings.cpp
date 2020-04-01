#include "Settings.h"

#include <sstream>


static std::stringstream converter;

inline UInt32 StrToHex(std::string a_str)
{
	UInt32 hex;

	converter << std::hex << a_str;
	converter >> hex;

	return hex;
}


bool Settings::LoadSettings(bool a_dumpParse)
{
	auto [log, success] = Json2Settings::load_settings(FILE_NAME, a_dumpParse);
	if (!log.empty()) {
		_ERROR("%s", log.c_str());
	}

	if (!exclusionList->empty()) {
		for (auto& npc : *exclusionList) {
			Exclusion::ExcludedNPC.insert(StrToHex(npc));
		}
		_MESSAGE("Excluded %d NPCs", Exclusion::ExcludedNPC.size());
	}

	return success;
}


decltype(Settings::heartOfFury)		Settings::heartOfFury("heartOfFury", false);
decltype(Settings::timeToGrowUp)	Settings::timeToGrowUp("timeToGrowUp", false);
decltype(Settings::exclusionList)	Settings::exclusionList("exclusionList");