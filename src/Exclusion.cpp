#include "Exclusion.h"


namespace Exclusion
{
	// only covers the main quest
	std::unordered_set<UInt32> QuestNPC = {
		// unbound
		0x0002BF9D, // Ralof
		0x0002BF9F, // Hadvar
		0x0008E4F1, // Alduin
		0x0001414D, // Ulfric
		// before the storm
		0x00013BBD, // Balgruuf
		0x00013BB8, // Irileth
		// bleak falls barrow
		0x00013BBB, // Farengar
		0x0001347A, // Lucan
		0x00013478, // Delphine, does she deserve protection
		// dragon rising
		0x00013BBA, // Proventus
		// the way of the voice
		0x000136BB, // Wilhelm
		0x0002C6CE, // Borri
		0x0002C6C7, // Arngeir
		0x0002C6CA, // Wulfgar
		// the horn of jurgen windcaller
		// a blade in the dark
		// diplomatic immunity
		0x00036194, // Malborn
		0x00013269, // Elenwen
		0x000368C8, // Razelan
		0x0001326A, // Elisif
		0x00013272, // Erikur
		0x0001327E, // Tullius
		0x000135EB, // Idgrod
		0x0001339F, // Igmund
		0x0001336A, // Maven
		0x00013653, // Siddgeir
		0x0001327A, // Vittoria
		// a cornered rat
		0x0001B07D, // Brynjolf
		0x00013358, // Esbern
		0x00013380, // Vekel
		0x00013365, // Keerava
		// alduin's wall
		// the throad of the world
		0x0003C57C, // Paarthurnax, but why killing
		0x0002C6CC, // Einarth
		// elder knowledge
		0x0001C193, // Urag
		0x0001C197, // Faralda
		// alduin's bane
		0x00044238, // Hakon
		0x00044236, // Gormlaith
		// the fallen
		0x00045920, // Odahviing
		0x00013BB5, // Vignar
		// the world-eater's eyrie
		// sovngrade
		0x000EA578, // Torygg
		0x00016C87, // Svaknir
		0x0001A68E, // Kodlak
		0x000132A1, // Rikke
		0x00014128, // Galmar
		0x0004F828, // Tsun
		0x00098BD1, // Ysgramor
		0x00044237, // Felldir
		// dragonslayer
	};

	std::unordered_set<UInt32> ExcludedNPC;


	bool IsExcluded(UInt32 a_formID)
	{
		if (!*Settings::heartOfFury && QuestNPC.count(a_formID)) {
			return true;
		}

		if (ExcludedNPC.count(a_formID)) {
			return true;
		}

		return false;
	}
}