#pragma once

namespace papyrus
{
	using VM = RE::BSScript::Internal::VirtualMachine;
	using StackID = RE::VMStackID;
	using Severity = RE::BSScript::ErrorLogger::Severity;

	//bool Bind(RE::BSScript::IVirtualMachine* a_vm);
	bool Bind(VM* a_vm);
	//inline constexpr auto script = "Keyhole"sv;

	void OpenKeyholeMenu(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*);
	void CloseKeyholeMenu(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*);
	bool IsKeyholePluginInstalled(VM* a_vm, StackID a_stackID, RE::StaticFunctionTag*);
}
