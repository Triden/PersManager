#ifndef SKELETON_FIELD
#define SKELETON_FIELD

#include "Grid.h"
#include "SkeletonData.h"

//Инструменты кружочки
class CircleInstrument {
private:
	Circle _circle;
	bool _mouseDown;
public:
	static const float DEFAULT_RADIUS;

	CircleInstrument(float radius = DEFAULT_RADIUS) {
		_circle.r = radius;
		_circle.c = FPoint();
	};

	bool Contain(FPoint pnt) {
		return _circle.Contain(pnt);
	}

	void Draw() {
		Core::render.DrawCircle(_circle.c, _circle.r, 8);
	}

	bool MouseDown(const IPoint& pnt) {
		_mouseDown = Contain(pnt);
		return _mouseDown;
	}

	void MouseMove(const IPoint& pnt) {
	}

	void MouseUp(const IPoint& pnt) {
		_mouseDown = false;
	}

	void SetCenter(const FPoint& center) {
		_circle.c = center;
	}

	bool Pressed() {
		return _mouseDown;
	}
	
	float GetRadius() {
		return _circle.r;
	}
};

class Field {
private:
	Grid _grid;	//Сетка
	SkeletonData _data;	//Данные о скелете, его анимациях и прочее
	static Field* _instance;
	bool _mouseDown;
	FPoint _mousePos;
	
	//Видимые инструменты для работы с костями
	CircleInstrument _rotateCI;
	CircleInstrument _scaleCI;
	bool _circleInstrumentsVisible;
public:
	Field();
	~Field();
	void Draw();
	void Update(float dt);
	bool MouseDown(const IPoint& pnt);
	void MouseMove(const IPoint& pnt);
	void MouseUp(const IPoint& pnt);
	static Field* Instance() { return _instance; }
	SkeletonData* GetData() { return &_data; }
	bool CircleInstrumentsVisible();
	void UpdateCInstrumentsPos();
};
#endif