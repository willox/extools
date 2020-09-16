#pragma once
#include <stdint.h>
#include "Ref.h"

namespace dm
{

enum class DataType : uint8_t
{
	NULL_D = 0x00,
	TURF = 0x01,
	OBJ = 0x02,
	MOB = 0x03,
	AREA = 0x04,
	CLIENT = 0x05,
	STRING = 0x06,
	MOB_TYPEPATH = 0x08,
	OBJ_TYPEPATH = 0x09,
	TURF_TYPEPATH = 0x0A,
	AREA_TYPEPATH = 0x0B,
	RESOURCE = 0x0C,
	IMAGE = 0x0D,
	WORLD_D = 0x0E,
	LIST = 0x0F,
	LIST_ARGS = 0x10,
	LIST_MOB_VERBS = 0x11,
	LIST_VERBS = 0x12,
	LIST_TURF_VERBS = 0x13,
	LIST_AREA_VERBS = 0x14,
	LIST_CLIENT_VERBS = 0x15,
	LIST_SAVEFILE_DIR = 0x16,
	LIST_MOB_CONTENTS = 0x17,
	LIST_TURF_CONTENTS = 0x18,
	LIST_AREA_CONTENTS = 0x19,
	LIST_WORLD_CONTENTS = 0x1A,
	LIST_GROUP = 0x1B,
	LIST_CONTENTS = 0x1C,
	DATUM_TYPEPATH = 0x20,
	DATUM = 0x21,
	SAVEFILE = 0x23,
	SAVEFILE_TYPEPATH = 0x24,
	PROCPATH = 0x26,
	FILE_ = 0x27,
	LIST_TYPEPATH = 0x28,
	PREFAB = 0x29,
	NUMBER = 0x2A,
	LIST_MOB_VARS = 0x2C,
	LIST_OBJ_VARS = 0x2D,
	LIST_TURF_VARS = 0x2E,
	LIST_AREA_VARS = 0x2F,
	LIST_CLIENT_VARS = 0x30,
	LIST_VARS = 0x31,
	LIST_MOB_OVERLAYS = 0x32,
	LIST_MOB_UNDERLAYS = 0x33,
	LIST_OVERLAYS = 0x34,
	LIST_UNDERLAYS = 0x35,
	LIST_TURF_OVERLAYS = 0x36,
	LIST_TURF_UNDERLAYS = 0x37,
	LIST_AREA_OVERLAYS = 0x38,
	LIST_AREA_UNDERLAYS = 0x39,
	APPEARANCE = 0x3A,
	CLIENT_TYPEPATH = 0x3B,
	IMAGE_TYPEPATH = 0x3F,
	LIST_IMAGE_OVERLAYS = 0x40,
	LIST_IMAGE_UNDERLAYS = 0x41,
	LIST_IMAGE_VARS = 0x42,
	LIST_IMAGE_VERBS = 0x43,
	LIST_IMAGE_CONTENTS = 0x44,
	LIST_CLIENT_IMAGES = 0x46,
	LIST_CLIENT_SCREEN = 0x47,
	LIST_TURF_VIS_CONTENTS = 0x4B,
	LIST_VIS_CONTENTS = 0x4C,
	LIST_MOB_VIS_CONTENTS = 0x4D,
	LIST_TURF_VIS_LOCS = 0x4E,
	LIST_VIS_LOCS = 0x4F,
	LIST_MOB_VIS_LOCS = 0x50,
	LIST_WORLD_VARS = 0x51,
	LIST_GLOBAL_VARS = 0x52,
	FILTERS = 0x53,
	LIST_IMAGE_VIS_CONTENTS = 0x54,
};

struct Value
{
	Value()
		: type(DataType::NULL_D)
		, _number(0.f)
	{}

	Value(DataType type, uint32_t data)
		: type(type)
		, _data(data)
	{}

	Value(float num)
		: type(DataType::NUMBER)
		, _number(num)
	{}

	Value(Ref<String> str)
		: type(DataType::STRING)
		, _string(str)
	{}

	DataType type;
	union
	{
		uint32_t _data;
		float _number;
		Ref<String> _string;
	};

	static const Value Null;
};
static_assert(sizeof(Value) == 8);

// Move to own file?
struct Variable
{
	uint32_t unk_0;
	Ref<String> name;
	Value value;
};
static_assert(sizeof(Variable) == 16);

}