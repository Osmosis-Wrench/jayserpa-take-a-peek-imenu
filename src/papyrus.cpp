#include "Papyrus.h"
#include "PeekMenu.h"

namespace Papyrus
{
	bool Bind(VM* a_vm)
	{
		if (!a_vm) {
			logger::critical("couldn't get VM State"sv);
			return false;
		}

		logger::info("{:*^30}", "FUNCTIONS"sv);

		Keyhole::Bind(*a_vm);

		return true;
	}

	std::uint32_t Keyhole::IsKeyholePluginInstalled(VM*, StackID, RE::StaticFunctionTag*)
	{
		std::uint32_t a = 1;
		return a;
	}

	void Keyhole::OpenKeyholeMenu(VM*, StackID, RE::StaticFunctionTag*)
	{
		SKSE::GetTaskInterface()->AddUITask([]() {
			CustomPeekMenu::Show();
		});
	}

	void Keyhole::CloseKeyholeMenu(VM*, StackID, RE::StaticFunctionTag*)
	{
		SKSE::GetTaskInterface()->AddUITask([]() {
			CustomPeekMenu::Hide();
		});
	}

	void Keyhole::Bind(VM& a_vm)
	{
		constexpr auto script = "Keyhole"sv;

		a_vm.RegisterFunction("IsKeyholePluginInstalled", script, IsKeyholePluginInstalled, true);

		a_vm.RegisterFunction("OpenKeyholeMenu", script, OpenKeyholeMenu);
		a_vm.RegisterFunction("CloseKeyholeMenu", script, CloseKeyholeMenu);

		logger::info("Registered keyhole functions"sv);
	}
}
