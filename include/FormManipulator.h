#pragma once

#include "NPCIterator.h"

#include "RE/Skyrim.h"

#include <bitset> // bitset


namespace
{
	static std::bitset<32> flagBase;

	void TryReplaceFlag()
	{
		auto npcIter = NPCIterator::GetSingleton();
		for (auto& npc : npcIter->GetValidNPCList()) {
			flagBase.reset();
			flagBase = std::bitset<32>((UInt32)npc->actorData.actorBaseFlags);
			flagBase[1].flip();
			npc->actorData.actorBaseFlags = static_cast<RE::ACTOR_BASE_DATA::Flag>(flagBase.to_ulong());
			assert(!npc->IsEssential());
		}
		_MESSAGE("Stripped off %d immortalities", npcIter->GetNPCAmount());
	}
}