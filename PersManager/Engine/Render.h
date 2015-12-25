#ifndef ENGINE_RENDER
#define ENGINE_RENDER

#include "Math.h"

#include "..\..\Dependencies\glew\glew.h"
#include "..\..\Dependencies\freeglut\freeglut.h"
#include <vector>

//Режимы отрисовки полигона
enum PolygonMode {
	POLY_FILL,	//Заполненный
	POLY_LINE,	//Линиями
	POLY_POINT	//Точками
};

namespace Core {
	class Render {
	private:
		std::vector<PolygonMode> _polygonMode;
		void SetPolyMode(PolygonMode pMode);
	public:
		Render() {}
		void DrawLine(IPoint pnt1, IPoint pnt2);	//Рисует линию
		void DrawRect(const IRect& rect);	//Рисует пустой прямоугольник
		void SetLineWidth(int width);	//Ширина линии
		void SetPolygonMode(PolygonMode pMode);
		void ResetPolygonMode();
	};
	extern Render render;
};
#endif