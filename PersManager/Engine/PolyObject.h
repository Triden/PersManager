#ifndef ENGINE_VERTEX_OB
#define ENGINE_VERTEX_OB

#include "Math.h"
#include <list>

namespace Core {
	class PolyObject {
	private:
		std::string _id;
		std::vector<FPolygon> _polygons;
		FPoint _min;
		FPoint _max;
	public:
		PolyObject();
		void Draw(FPoint pos);
		void Draw(float x, float y);
		const std::string& GetId() const { return _id; }
		bool Default();
		void AddPolygon(const FPolygon& polygon, bool recalcMaxAndMin = true);
		FPoint GetSize();	//���������� ������� ����� ������������� � ������������ x y
		FPoint GetMin();
		FPoint GetMax();
		void MakeMinAndMax();	//������������� ������������ � ����������� x y
		void Scale(float scale);
	};
};

#endif