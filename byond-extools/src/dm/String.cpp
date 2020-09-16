#include "String.h"
#include "Globals.h"

namespace dm
{
	template<>
	String* Ref<String>::get()
	{
		return Globals::Strings->Get(*this);
	};

	template<>
	VarName* Ref<VarName>::get()
	{
		// TODO: There are no bounds checks on VarNames. It doesn't seem to have a length stored anywhere in memory?
		return static_cast<VarName*>(Globals::VarNames[index].get());
	};
}