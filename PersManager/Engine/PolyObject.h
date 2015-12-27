#ifndef ENGINE_VERTEX_OB
#define ENGINE_VERTEX_OB

#include "Math.h"
#include <list>

namespace Core {
	class PolyObject {
	private:
		std::string _id;
		std::vector<FPolygon> _polygons;
	public:
		PolyObject();
		void Draw();
		const std::string& GetId() { return _id; }
	};
};

#endif