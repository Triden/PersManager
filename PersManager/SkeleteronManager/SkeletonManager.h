#ifndef SKELETON_MANAGER
#define SKELETON_MANAGER

#include "..\Engine\Include.h"
#include "Instruments.h"
#include "Grid.h"
#include "ScaleManager.h"

class SkeletonManager {
private:
	SkeletonInstrumentsPanel _instrumentsPanel;	//Панель всех инстурментов
	Grid _grid;	//Сетка
	ScaleManager _scaleManager;
public:
	SkeletonManager();
	~SkeletonManager();
	void Draw();
	void Update(float dt);
	void MouseDown(const IPoint& pnt);
	void MouseMove(const IPoint& pnt);
	void MouseUp(const IPoint& pnt);
	void MouseWheel(int dir, const IPoint& mousePos);
};

#endif