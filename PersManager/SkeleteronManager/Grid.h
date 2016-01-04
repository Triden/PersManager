#ifndef SKELETON_GRID
#define SKELETON_GRID

#include "..\Engine\Include.h"

class Grid {
private:
	int _interval;
public:
	Grid(int interval);
	void Draw(IRect rect);
	void Update(float dt);
};

#endif