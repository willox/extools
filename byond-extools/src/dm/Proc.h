#pragma once
#include <stdint.h>
#include "Ref.h"
#include "Value.h"

namespace dm
{
struct Misc;

struct Proc
{
	Ref<String> path;
	Ref<String> name;
	uint32_t unk_0;
	uint32_t unk_1;
	uint32_t unk_2;
	uint32_t unk_3;
	Ref<Misc> bytecode;
	Ref<Misc> locals;
	Ref<Misc> test;
};
static_assert(sizeof(Proc) == 36);

struct ProcInstance
{
	Ref<Proc> proc;
	int unknown1;
	Value usr;
	Value src;
	union
	{
		ExecutionContext* context;
		ProcInstance* next; // When we're part of the global `procinstance_freelist` linked list, this is the next element
	};
	int argslist_id;
	int unknown4;
	union
	{
		int unknown5;
		int extended_profile_id;
	};
	int arg_count;
	Value* args;
	char unknown6[0x58];
	int time_to_resume;
};

// TODO: rename?
struct ExecutionContext
{
	ProcInstance* proc_instance;
	ExecutionContext* parent_context;
	Ref<String> dbg_proc_file;
	uint32_t dbg_current_line;
	uint32_t* bytecode;
	uint16_t current_opcode;
	char test_flag;
	char unknown1;
	Value cached_datum;
	char unknown2[16];
	Value dot;
	Value* local_variables;
	Value* stack;
	uint16_t local_var_count;
	uint16_t stack_size;
	int32_t unknown;
	Value* current_iterator;
	uint32_t iterator_allocated;
	uint32_t iterator_length;
	uint32_t iterator_index;
	uint32_t another_unknown2;
	char unknown4[3];
	char iterator_filtered_type;
	char unknown5;
	char iterator_unknown;
	char unknown6;
	uint32_t infinite_loop_count;
	char unknown7[2];
	bool paused;
	char unknown8[51];
};
// TODO: Size?

struct ProcTable
{
	Proc* procs;
	uint32_t count;
};
static_assert(sizeof(ProcTable) == 8);

}