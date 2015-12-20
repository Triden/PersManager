#include "Render.h"

namespace Core {
	Render::Render() {
	};

	void Render::DrawLine(IPoint pnt1, IPoint pnt2) {
		glLineWidth(1);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(pnt1.x, pnt1.y, 0);
		glVertex3f(pnt2.x, pnt2.y, 0);
		glEnd();
	};
};