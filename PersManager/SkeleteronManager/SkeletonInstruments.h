#ifndef SKELETON_INSTRUMENTS
#define SKELETON_INSTRUMENTS

#include "..\Engine\Include.h"
#include "InstrumentsPanel.h"
#include "States.h"

class SkeletonInstruments {
private:
	SkeletonState _state;
	std::vector<InstrumentsPanel *> _instruments;
	static SkeletonInstruments* _instance;
public:
	static SkeletonInstruments* Instance() { return _instance; }
	SkeletonInstruments();
	~SkeletonInstruments();
	void Draw();
	void Update(float dt);
	bool MouseDown(const IPoint& pnt);
	void MouseMove(const IPoint& pnt);
	void MouseUp(const IPoint& pnt);
	const SkeletonState& GetState() const { return _state; }	//¬озвращает, что мы хотим делать, если нажали на поле
	void SetState(SkeletonState state);
};

#endif