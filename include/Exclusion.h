#pragma once

#include "Settings.h"

#include "RE/Skyrim.h"

#include <unordered_set> // unordered_set


namespace Exclusion
{
	extern std::unordered_set<UInt32> QuestNPC;
	extern std::unordered_set<UInt32> ExcludedNPC;


	bool IsExcluded(UInt32 a_formID);
}