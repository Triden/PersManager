#ifndef ENGINE_ASSERT
#define ENGINE_ASSERT

#include <crtdbg.h>

inline void Assert(bool value) {
	if (!value) {
		_CrtDbgBreak();
	}
};

#endif