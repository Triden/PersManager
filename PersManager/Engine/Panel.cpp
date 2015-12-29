#include "Panel.h"
#include "Render.h"

namespace Core {
	
	const float Panel::CAPTION_H = 10.f;

	Panel::Panel(IRect rect, float border) :
		_mouseDown(false),
		_mousePress(-1, -1),
		_rect(rect),
		_border(border)
	{

	};

	IRect Panel::GetRect() {
		return _rect;
	};

	IRect Panel::GetBorderedRect() {
		return IRect(
			_rect.x + _border,
			_rect.y + _border,
			_rect.width - _border * 2,
			_rect.height - _border * 2);
	};

	IRect Panel::GetCaptionRect() {
		IRect rect = IRect(_rect.x, _rect.y + _rect.height, _rect.width, CAPTION_H);
		return rect;
	}

	bool Panel::MouseDown(const IPoint& mousePos) {
		_mouseDown = GetCaptionRect().Contain(mousePos);
		if (_mouseDown) {
			_mousePress = mousePos;
			_prevPos = IPoint(_rect.x, _rect.y);
		}
		return _mouseDown || _rect.Contain(mousePos);
	};

	void Panel::MouseMove(const IPoint& mousePos) {
		if (_mouseDown) {
			_rect.x = _prevPos.x + (mousePos.x - _mousePress.x);
			_rect.y = _prevPos.y + (mousePos.y - _mousePress.y);
		}
	};

	void Panel::MouseUp(const IPoint& mousePos) {
		_mouseDown = false;
	};

	void Panel::KeyPress(unsigned char key) {
	};

	void Panel::Draw() {
		render.SetColor(Color::LIGHT_PINK);
		render.SetPolygonMode(POLY_FILL);
		render.DrawRect(_rect);
		render.ResetPolygonMode();
		render.ResetColor();

		render.SetColor(Color::PINK);
		render.SetPolygonMode(POLY_LINE);
		render.DrawRect(_rect);
		render.ResetPolygonMode();
		render.ResetColor();

		render.SetColor(Color::BLUE_VIOLET);
		render.SetPolygonMode(POLY_FILL);
		render.DrawRect(GetCaptionRect());
		render.ResetPolygonMode();
		render.ResetColor();
	};

	void Panel::Update(float dt) {
	};

	void Panel::MoveTo(IPoint pnt) {
		_rect.x = pnt.x;
		_rect.y = pnt.y;
	}
};