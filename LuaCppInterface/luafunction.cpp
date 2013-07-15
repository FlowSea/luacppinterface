#include <cassert>
#include "luafunction.h"
#include "luatable.h"

LuaFunctionBase::LuaFunctionBase(std::tr1::shared_ptr<lua_State> state, int index) : LuaReference(state, index)
{
	auto type = GetType();
	if (type != LuaType::function)
	{
		LuaTable metatable = GetMetaTable();
		assert(metatable.GetTypeOfValueAt("__call") == LuaType::function);
	}
	else
	{
		assert(type == LuaType::function);
	}
}
