#pragma once
#include "Ref.h"

namespace dm
{
	struct StringTable;

	namespace Globals
	{
		extern StringTable* Strings;
		extern Ref<String>* VarNames;
	}
}