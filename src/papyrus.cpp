#include "papyrus.h"
#include "PeekMenu.h"

#define BIND(a_method, ...) a_vm.RegisterFunction(#a_method##sv, script, a_method __VA_OPT__(, ) __VA_ARGS__)

namespace papyrus
{
	void papyrus::OpenKeyholeMenu(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*)
	{
		logger::info("Open Menu request.");
		SKSE::GetTaskInterface()->AddUITask([]() {
			CustomPeekMenu::Show();
		});
	}

	void papyrus::CloseKeyholeMenu(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*)
	{
		logger::info("Close Menu request.");
		SKSE::GetTaskInterface()->AddUITask([]() {
			CustomPeekMenu::Show();
		});
	}

	bool papyrus::IsKeyholePluginInstalled(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*)
	{
		logger::info("Request for plugin existance detected.");
		return true;
	}

	bool papyrus::Bind(VM* a_vm)
	{
		if (!a_vm) {
			logger::info("No Virtual Machine!");
			return false;
		}

		//BIND(papyrus::OpenKeyholeMenu);

		a_vm->RegisterFunction("OpenKeyholeMenu", "Keyhole", papyrus::OpenKeyholeMenu);
		//a_vm->RegisterFunction("CloseKeyholeMenu", "Keyhole", CloseKeyholeMenu);
		a_vm->RegisterFunction("IsKeyholePluginInstalled", "Keyhole", papyrus::IsKeyholePluginInstalled);
		logger::info("bound functions");
		return true;
	}
}
