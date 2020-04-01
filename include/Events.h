#pragma once

#include "FormManipulator.h"

#include "RE/Skyrim.h"


namespace Events
{
	class TESObjectLoadedEventHandler : public RE::BSTEventSink<RE::TESObjectLoadedEvent>
	{
	public:
		using EventResult = RE::BSEventNotifyControl;


		static TESObjectLoadedEventHandler* GetSingleton()
		{
			static TESObjectLoadedEventHandler singleton;
			return std::addressof(singleton);
		}


		virtual EventResult ProcessEvent(const RE::TESObjectLoadedEvent* a_event, RE::BSTEventSource<RE::TESObjectLoadedEvent>* a_eventSource) override
		{
			if (!a_event) {
				return EventResult::kContinue;
			}

			auto refr = RE::TESForm::LookupByID<RE::Actor>(a_event->formID);
			if (refr) {
				TryReplaceFlag(refr);
			}

			return EventResult::kContinue;
		}

	protected:
		TESObjectLoadedEventHandler() = default;
		TESObjectLoadedEventHandler(const TESObjectLoadedEventHandler&) = delete;
		TESObjectLoadedEventHandler(TESObjectLoadedEventHandler&&) = delete;
		virtual ~TESObjectLoadedEventHandler() = default;

		TESObjectLoadedEventHandler& operator=(const TESObjectLoadedEventHandler&) = delete;
		TESObjectLoadedEventHandler& operator=(TESObjectLoadedEventHandler&&) = delete;
	};
}