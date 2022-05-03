#pragma once

namespace Papyrus
{
	using VM = RE::BSScript::Internal::VirtualMachine;
	using StackID = RE::VMStackID;

	bool Bind(VM* a_vm);

	namespace Keyhole
	{
		std::uint32_t IsKeyholePluginInstalled(VM*, StackID, RE::StaticFunctionTag*);

		void OpenKeyholeMenu(VM*, StackID, RE::StaticFunctionTag*);
		void CloseKeyholeMenu(VM*, StackID, RE::StaticFunctionTag*);

		void Bind(VM& a_vm);
	}
}
