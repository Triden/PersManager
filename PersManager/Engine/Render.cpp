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

	void Render::DrawPolygon(const FPolygon& poly, const FPoint& pos) {
		DrawPolygon(poly, pos.x, pos.y);
	}

	void Render::DrawPolygon(const FPolygon& poly, float x, float y) {
		glBegin(GL_POLYGON);//begin drawing of polygon
		glVertex3f(poly.v1.x + x, poly.v1.y + y, 0.0f);
		glVertex3f(poly.v2.x + x, poly.v2.y + y, 0.0f);
		glVertex3f(poly.v3.x + x, poly.v3.y + y, 0.0f);
		glEnd();//end drawing of polygon
	}

	void Render::PushMatrix() {
		glPushMatrix();
	}
	void Render::PopMatrix() {
		glPopMatrix();
	}

	void Render::MatrixMove(FPoint pnt) {
		glTranslatef(pnt.x, pnt.y, 0.f);
	}

	void Render::MatrixScale(float scale) {
		MatrixScale(scale, scale, 1.f);
	}

	void Render::MatrixScale(FPoint scale) {
		MatrixScale(scale.x, scale.y);
	}

	void Render::MatrixScale(float scaleX, float scaleY, float scaleZ) {
		glScalef(scaleX, scaleY, scaleZ);
	}
};