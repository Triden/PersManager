#include "Panel.h"
#include "Render.h"

namespace Core {

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

	void Panel::MouseDown(const IPoint& mousePos) {
		_mouseDown = _rect.Contain(mousePos);
		if (_mouseDown) {
			_mousePress = mousePos;
			_prevPos = IPoint(_rect.x, _rect.y);
		}
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
		render.SetPolygonMode(POLY_LINE);
		render.DrawRect(_rect);
		render.ResetPolygonMode();
	};

	void Panel::Update(float dt) {
	};
};