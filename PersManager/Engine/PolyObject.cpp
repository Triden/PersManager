#include "PolyObject.h"
#include "Render.h"

namespace Core {
	PolyObject::PolyObject() :
		_id("")
	{
		_polygons.clear();
	};

	void PolyObject::Draw() {
		render.SetPolygonMode(POLY_LINE);
		for (int i = 0; i < (int)_polygons.size(); ++i) {
			render.DrawPolygon(_polygons[i]);
		}
		render.ResetPolygonMode();
	}
};