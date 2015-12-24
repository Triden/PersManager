#ifndef ENGINE_ASSERT
#define ENGINE_ASSERT

#include <assert.h>

void Assert(bool value) {
	assert(value);
}
#endif