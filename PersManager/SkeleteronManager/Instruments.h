#ifndef SKELETON_INSTRUMENTS
#define SKELETON_INSTRUMENTS

#include "..\Engine\Include.h"

class SkeletonInstrumentsPanel : public Core::Panel {
private:
	const int BUTTONS_IN_THE_ROW = 2;
	const int B_WIDTH = 20;

	Core::Button _makeBone;
	std::vector<Core::Button *> _buttons;
public:
	SkeletonInstrumentsPanel();
	~SkeletonInstrumentsPanel();
	virtual void Draw();
	virtual void Update(float dt);
	virtual bool MouseDown(const IPoint& pnt);
	virtual void MouseMove(const IPoint& pnt);
	virtual void MouseUp(const IPoint& pnt);
	virtual void MoveButtons();
};

#endif