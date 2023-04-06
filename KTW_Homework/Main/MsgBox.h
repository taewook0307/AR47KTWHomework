#pragma once

#include <Windows.h>
#include <assert.h>

#define MsgBoxAssert(Text) MessageBoxA(nullptr, Text, "Error", MB_OK); assert(false);