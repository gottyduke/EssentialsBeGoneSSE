#pragma once

#include "Exclusion.h"

#include "RE/Skyrim.h"


namespace
{
	void TryReplaceFlag(RE::Actor* a_refr)
	{
		if (!a_refr || !a_refr->GetActorBase()) {
			_MESSAGE("nullptr");
			return;
		}

		if (*Settings::timeToGrowUp) {
			// wait to be implmented
		}

		if (a_refr->GetActorBase()->IsEssential() && !Exclusion::IsExcluded(a_refr->GetBaseObject()->GetFormID())) {
			auto base = a_refr->GetActorBase();
			base->actorData.actorBaseFlags = (RE::ACTOR_BASE_DATA::Flag)((UInt32)base->actorData.actorBaseFlags ^ (1 << 1));
			if ((base->actorData.actorBaseFlags & RE::ACTOR_BASE_DATA::Flag::kProtected) == RE::ACTOR_BASE_DATA::Flag::kNone) {
				base->actorData.actorBaseFlags = (RE::ACTOR_BASE_DATA::Flag)((UInt32)base->actorData.actorBaseFlags ^ (1 << 11));
			}
			return;
		}
	}
}

