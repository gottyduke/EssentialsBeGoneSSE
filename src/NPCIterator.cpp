#include "NPCIterator.h"
#include "Exclusion.h"


auto NPCIterator::GetSingleton()
-> NPCIterator*
{
	static NPCIterator singleton;
	return std::addressof(singleton);
}


// validate and preload the npc list
void NPCIterator::PreloadNPCList()
{
	auto dataHandler = RE::TESDataHandler::GetSingleton();
	auto& roughList = dataHandler->GetFormArray<RE::TESNPC>();
	for (auto& npc : roughList) {
		if (!npc) {
			continue;
		}
		if (Exclusion::IsExcluded(npc)) {
			continue;
		}
		if (npc->IsEssential() && !_npcs.count(npc)) {
			_npcs.insert(npc);
			TryFillStats(npc);
			// Essential NPC Dump
			//_DMESSAGE("%x-%s", npc->GetFormID(), npc->GetFullName());
		}
	}
}


auto NPCIterator::GetValidNPCList()
-> std::unordered_set<RE::TESNPC*>&
{
	assert(!_npcs.empty());
	return _npcs;
}


auto NPCIterator::GetNPCAmount() const
-> size_t
{
	assert(!_npcs.empty());
	return _npcs.size();
}


void NPCIterator::TryFillStats(RE::TESNPC* a_npc)
{
	auto file = a_npc->GetFile()->fileName;
	if (_stats.find(file) == _stats.end())
		_stats.insert({ file, 1 });
	else
		_stats.at(file) += 1;
}


void NPCIterator::DumpStats()
{
	for (auto it = _stats.begin(); it != _stats.end(); ++it) {
		_MESSAGE("%-3d (%3.1f%%)[%s]", it->second, (float)it->second / GetNPCAmount() * 100, it->first);
	}
	_MESSAGE("Registered %d NPCs", GetNPCAmount());
	_MESSAGE("NPCIterator finished preloading");
}