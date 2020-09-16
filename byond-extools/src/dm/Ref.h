#pragma once
#include <stdint.h>

namespace dm
{
//
// Reference forward declarations
//
struct String;
struct VarName;

//
// Reference type used in many internal structures. Specializiations exist to pull data from the correct location.
//
template<typename T, typename I=uint32_t>
struct Ref
{
	I index;
	T* get();

	bool operator==(const Ref<T>& rhs) const
	{
		return index == rhs.index;
	}

	bool operator!=(const Ref<T>& rhs) const
	{
		return index != rhs.index;
	}
};
static_assert(sizeof(Ref<void>) == 4);


}