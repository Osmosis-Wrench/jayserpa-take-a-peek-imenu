#include "PeekMenu.h"
#include "papyrus.h"

static void SKSEMessageHandler(SKSE::MessagingInterface::Message* message)
{
	if (message->type == SKSE::MessagingInterface::kDataLoaded) {
		CustomPeekMenu::Register();
	}
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
	SKSE::Init(a_skse);
	logger::info("loaded plugin");

	SKSE::GetPapyrusInterface()->Register(Papyrus::Bind);

	const auto messaging = SKSE::GetMessagingInterface();
	if (!messaging || !messaging->RegisterListener("SKSE", SKSEMessageHandler)) {
		logger::critical("Failed to register messaging listener, plugin will not load.");
		return false;
	}
	return true;
}
