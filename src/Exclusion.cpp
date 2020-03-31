#include "Exclusion.h"


namespace Exclusion
{
	// Need to implement those IDs, need haaaalp with tedious work
	std::unordered_set<UInt32> QuestNPC = {
		   //0x0002BF9D, // Ralof
		   //0x0002BF9F, // Hadvar
		   //0x00013BBD, // Balgruuf the Greater
		   //0x00013BB8, // Irileth
		   //0x00013BBB, // Farengar Secret-Fire

	};

	std::unordered_set<UInt32> ExcludedNPC;


	bool IsExcluded(RE::TESNPC* a_npc)
	{
		if (!*Settings::heartOfFury && QuestNPC.count(a_npc->GetFormID())) {
			return true;
		}

		if (ExcludedNPC.count(a_npc->GetFormID())) {
			return true;
		}

		return false;
	}
}