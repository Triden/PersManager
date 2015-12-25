#ifndef ENGINE_RENDER
#define ENGINE_RENDER

#include "Math.h"

#include "..\..\Dependencies\glew\glew.h"
#include "..\..\Dependencies\freeglut\freeglut.h"
#include <vector>

//������ ��������� ��������
enum PolygonMode {
	POLY_FILL,	//�����������
	POLY_LINE,	//�������
	POLY_POINT	//�������
};

namespace Core {
	class Render {
	private:
		std::vector<PolygonMode> _polygonMode;
		void SetPolyMode(PolygonMode pMode);
	public:
		Render() {}
		void DrawLine(IPoint pnt1, IPoint pnt2);	//������ �����
		void DrawRect(const IRect& rect);	//������ ������ �������������
		void SetLineWidth(int width);	//������ �����
		void SetPolygonMode(PolygonMode pMode);
		void ResetPolygonMode();
	};
	extern Render render;
};
#endif