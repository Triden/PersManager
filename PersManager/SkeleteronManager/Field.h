#ifndef SKELETON_FIELD
#define SKELETON_FIELD

#include "Grid.h"
#include "SkeletonData.h"

class Field {
private:
	Grid _grid;	//Сетка
	SkeletonData _data;	//Данные о скелете, его анимациях и прочее
public:
	Field();
	~Field();
	void Draw();
	void Update(float dt);
	bool MouseDown(const IPoint& pnt);
	void MouseMove(const IPoint& pnt);
	void MouseUp(const IPoint& pnt);
};
#endif