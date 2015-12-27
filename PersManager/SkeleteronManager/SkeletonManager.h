#ifndef SKELETON_MANAGER
#define SKELETON_MANAGER

#include "..\Engine\Include.h"
#include "Instruments.h"

class SkeletonManager {
private:
	SkeletonInstrumentsPanel _instrumentsPanel;	//Панель инстурментов
public:
	SkeletonManager();
	~SkeletonManager();
	void Draw();
	void Update(float dt);
	void MouseDown(const IPoint& pnt);
	void MouseMove(const IPoint& pnt);
	void MouseUp(const IPoint& pnt);
};

#endif