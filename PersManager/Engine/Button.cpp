#include "Button.h"
#include "Render.h"
#include <iostream>

namespace Core {
	Button::Button() :
		_mouseDown(false),
		_mouseMove(false),
		_rect(0, 0, 1, 1)
	{

	}

	Button::~Button() {

	}

	void Button::Draw() {
		if (_mouseDown && _mouseMove) {
			render.SetColor(Color::LIGHT_GRAY);
		} else {
			render.SetColor(Color::YELLOW);
		}
		render.SetPolygonMode(POLY_FILL);
		render.DrawRect(_rect);
		render.ResetPolygonMode();
		render.ResetColor();

		render.SetColor(Color::PINK);
		render.SetPolygonMode(POLY_LINE);
		render.DrawRect(_rect);
		render.ResetPolygonMode();
		render.ResetColor();
	}

	void Button::Update(float dt) {

	}

	bool Button::MouseDown(const IPoint& mousePos) {
		_mouseDown = _rect.Contain(mousePos);
		_mouseMove = _mouseDown;
		return _mouseDown;
	}

	void Button::MouseMove(const IPoint& mousePos) {
		_mouseMove = _rect.Contain(mousePos);
	}

	void Button::MouseUp(const IPoint& mousePos) {
		_mouseDown = false;
		_mouseMove = false;
	}

	void Button::Create(const IRect& rect) {
		_rect = rect;
	}

	void Button::MoveTo(const IPoint& pos) {
		_rect.x = pos.x;
		_rect.y = pos.y;
	}
};