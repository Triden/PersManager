#include "PolyObject.h"
#include "Render.h"

namespace Core {
	PolyObject::PolyObject() :
		_id(""),
		_min(0.f, 0.f),
		_max(0.f, 0.f)
	{
		_polygons.clear();
	};

	void PolyObject::Draw(FPoint pos) {
		Draw(pos.x, pos.y);
	}


	void PolyObject::Draw(float x, float y) {
		for (int i = 0; i < (int)_polygons.size(); ++i) {
			render.DrawPolygon(_polygons[i], x - GetMin().x, y - GetMin().y);
		}
	}

	bool PolyObject::Default() {
		return _polygons.empty();
	}

	void PolyObject::AddPolygon(const FPolygon& polygon, bool recalcMaxAndMin) {
		_polygons.push_back(polygon);
		if (recalcMaxAndMin) {
			MakeMinAndMax();
		}
	}

	void PolyObject::MakeMinAndMax() {
		//Нет полигонов у этой модели
		if (_polygons.size() <= 0) {
			_min = FPoint(0.f, 0.f);
			_max = FPoint(0.f, 0.f);
			return;
		}
		
		//Кэшируем максимальное и минимальное значение
		_min = _polygons[0].GetMin();
		_max = _polygons[0].GetMax();

		for (int i = 1; i < (int)_polygons.size(); ++i) {
			FPoint pMin = _polygons[i].GetMin();
			FPoint pMax = _polygons[i].GetMax();
			if (_min.x > pMin.x) {
				_min.x = pMin.x;
			}
			if (_max.x < pMax.x) {
				_max.x = pMax.x;
			}
			if (_min.y > pMin.y) {
				_min.y = pMin.y;
			}
			if (_max.y < pMax.y) {
				_max.y = pMax.y;
			}
		}
	}

	FPoint PolyObject::GetSize() {
		return _max - _min;
	}

	FPoint PolyObject::GetMin() {
		return _min;
	}

	FPoint PolyObject::GetMax() {
		return _max;
	}

	void PolyObject::Scale(float scale) {
		for (int i = 0; i < (int)_polygons.size(); ++i) {
			_polygons[i].Scale(scale);
		}
		MakeMinAndMax();
	}
};