#ifndef ENGINE_RENDER
#define ENGINE_RENDER

#include "Math.h"
#include "Types.h"

#include "..\..\Dependencies\glew\glew.h"
#include "..\..\Dependencies\freeglut\freeglut.h"

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
		std::vector<Color> _color;
		void SetPolyMode(PolygonMode pMode);
		void SetColorMode(Color color);
	public:
		Render() {}
		void DrawLine(IPoint pnt1, IPoint pnt2);	//Рисует линию
		void DrawRect(const IRect& rect);	//Рисует пустой прямоугольник
		void DrawPolygon(const FPolygon& poly, const FPoint& pos = FPoint(0.f, 0.f));
		void DrawPolygon(const FPolygon& poly, float x, float y);
		void DrawCircle(const IPoint& pnt, float r, int accuracy);
		void DrawBone(const Bone& bone);
		void SetLineWidth(int width);	//Ширина линии
		void SetPolygonMode(PolygonMode pMode);
		void ResetPolygonMode();
		void SetColor(Color color);
		void ResetColor();

		void PushMatrix();
		void PopMatrix();
		void MatrixScale(float scale);
		void MatrixScale(FPoint scale);
		void MatrixScale(float scaleX, float scaleY, float scaleZ = 1.f);
		void MatrixMove(FPoint pnt);
	};
	extern Render render;
};
#endif