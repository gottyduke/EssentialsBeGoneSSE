#pragma once

#include "Settings.h" // exclusion
#include "RE/Skyrim.h" // Thank You Ryan

#include <unordered_set> // unordered_set
#include <unordered_map> // unordered_map


class NPCIterator
{
public:
	static NPCIterator* GetSingleton();

	void PreloadNPCList();
	std::unordered_set<RE::TESNPC*>& GetValidNPCList();
	size_t GetNPCAmount() const;

	void DumpStats();

protected:
	NPCIterator() = default;
	NPCIterator(const NPCIterator&) = delete;
	NPCIterator(NPCIterator&&) = delete;
	~NPCIterator() = default;


	void TryFillStats(RE::TESNPC* a_npc); 

private:
	std::unordered_set<RE::TESNPC*> _npcs;
	std::unordered_map<char*, int> _stats;
};