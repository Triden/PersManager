#include "Render.h"
#include "Assertion.h"

namespace Core {
	void Render::SetColor(Color color) {
		SetColorMode(color);
		_color.push_back(color);
	}

	void Render::ResetColor() {
		if (_color.size() > 0) {
			_color.pop_back();
			if (_color.size() <= 0) {
				//~Assert(false);
			} else {
				SetColorMode(_color.back());
			}
		} else {
			Assert(false);
		}
	}

	void Render::SetColorMode(Color color) {
		glColor3f(color.r, color.g, color.b);
	}

	void Render::SetPolyMode(PolygonMode pMode) {
		if (pMode == POLY_FILL) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		} else if (pMode == POLY_LINE) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		} else if (pMode == POLY_POINT) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		} else {
			Assert(false);
		}
	}

	void Render::SetPolygonMode(PolygonMode pMode) {
		SetPolyMode(pMode);
		_polygonMode.push_back(pMode);
	}

	void Render::ResetPolygonMode() {
		if (_polygonMode.size() > 0) {
			_polygonMode.pop_back();
			if (_polygonMode.size() <= 0) {
				//~Assert(false);
			} else {
				SetPolyMode(_polygonMode.back());
			}
		} else {
			Assert(false);
		}
	}

	void Render::SetLineWidth(int width) {	//Ширина линии
		glLineWidth(width);
	}

	void Render::DrawLine(IPoint pnt1, IPoint pnt2) {
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(pnt1.x, pnt1.y, 0);
		glVertex3f(pnt2.x, pnt2.y, 0);
		glEnd();
	};

	void Render::DrawRect(const IRect& rect) {
		glBegin(GL_QUADS);
		glVertex3f(rect.x, rect.y + rect.height, 0.0f);	// Top Left
		glVertex3f(rect.x + rect.width, rect.y + rect.height, 0.0f);	// Top Right
		glVertex3f(rect.x + rect.width, rect.y, 0.0f);	// Bottom Right
		glVertex3f(rect.x, rect.y, 0.0f);	// Bottom Left
		glEnd();   
	}
};