#pragma once
#include "Math.h"

#include "..\Dependencies\glew\glew.h"
#include "..\Dependencies\freeglut\freeglut.h"

namespace Core {
	class Render {
	public:
		Render();
		void DrawLine(IPoint pnt1, IPoint pnt2);
	};
	extern Render render;
};