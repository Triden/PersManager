#ifndef ENGINE_ASSERT
#define ENFINE_ASSERT

#pragma once

#include <assert.h>

void Assert(bool value) {
	assert(value);
}
#endif