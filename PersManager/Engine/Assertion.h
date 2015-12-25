#ifndef ENGINE_ASSERT
#define ENGINE_ASSERT

#include <assert.h>

inline void Assert(bool value) {
	assert(value);
};

class Obj {
public:
	Obj() { ; };
};

#endif