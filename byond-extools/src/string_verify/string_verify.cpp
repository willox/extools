#include "string_verify.h"
#include <set>

extern "C" EXPORT const char* string_verify_initialize(int n_args, const char** args)
{
	if (!(Core::initialize() && string_verify::initialize()))
		return Core::FAIL;
	return Core::SUCCESS;
}

namespace string_verify
{

static void verify()
{
	std::set<std::string> strings;
	
	for (uint32_t i = 0; i < Core::string_table->length; i++)
	{
		String* str = Core::string_table->strings[i];
		if (str == nullptr || i == 65535)
			continue;

		auto res = strings.insert(std::string{str->stringData});
		if (!res.second)
		{
			// Big bad!;
#ifdef _WIN32
			__debugbreak();
#else
			__asm__("int3");
#endif
		}
	}
}

static GetStringTableIndexUTF8Ptr oGetStringTableIndexUTF8;
static unsigned int REGPARM3 hGetStringTableIndexUTF8(const char* string, int utf8, int handleEscapes, int duplicateString)
{
	static uint32_t i = 0;
	unsigned int ret = oGetStringTableIndexUTF8(string, utf8, handleEscapes, duplicateString);
	if (++i >= 4096)
	{
		verify();
		i = 0;
	}
	return ret;
}

bool initialize()
{
	verify();
	oGetStringTableIndexUTF8 = Core::install_hook(GetStringTableIndexUTF8, hGetStringTableIndexUTF8);
	return true;
}


}

