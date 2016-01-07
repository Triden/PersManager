#ifndef SKELETON_MANAGER
#define SKELETON_MANAGER

#include "..\Engine\Include.h"
#include "SkeletonInstruments.h"
#include "ScaleManager.h"
#include "Field.h"

class SkeletonManager {
private:
	SkeletonInstruments _instrumentsPanel;	//Панель всех инстурментов
	ScaleManager _scaleManager;
	static SkeletonManager* _instance;
	Field _field;
public:
	SkeletonManager();
	~SkeletonManager();
	static SkeletonManager* Instance();
	void Draw();
	void Update(float dt);
	void MouseDown(const IPoint& pnt);
	void MouseMove(const IPoint& pnt);
	void MouseUp(const IPoint& pnt);
	void MouseWheel(int dir, const IPoint& mousePos);
	ScaleManager* GetScaleManager();
};

#endif