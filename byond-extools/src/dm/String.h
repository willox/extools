#pragma once
#include <stdint.h>
#include "Ref.h"

namespace dm
{
	struct String
	{
	private:
		const char* data;
		uint32_t unk_0;
		uint32_t unk_1;
		uint32_t reference_count;
		uint32_t unk_2;
		uint32_t unk_3;
		uint32_t unk_4;

	public:
		const char* c_str()
		{
			return data;
		}
	};
	static_assert(sizeof(String) == 28);

	// VarNames are just strings that have their own reference type
	struct VarName : public String
	{};
	static_assert(sizeof(VarName) == sizeof(String));

	struct StringTable
	{
	private:
		String** strings;
		uint32_t count;

	public:
		String* Get(Ref<String> ref)
		{
			if (ref.index >= count)
				return nullptr;

			return strings[ref.index];
		}

		uint32_t Count()
		{
			return count;
		}
	};
	static_assert(sizeof(StringTable) == 8);
}