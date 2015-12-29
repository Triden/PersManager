#ifndef SKELETON_INSTRUMENTS
#define SKELETON_INSTRUMENTS

#include "..\Engine\Include.h"
#include "MainInstruments.h"

class SkeletonInstrumentsPanel {
private:
	std::vector<MainInstruments *> _instruments;
public:
	SkeletonInstrumentsPanel();
	~SkeletonInstrumentsPanel();
	virtual void Draw();
	virtual void Update(float dt);
	virtual bool MouseDown(const IPoint& pnt);
	virtual void MouseMove(const IPoint& pnt);
	virtual void MouseUp(const IPoint& pnt);
};

#endif