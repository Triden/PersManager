#include "Button.h"
#include "Render.h"
#include <iostream>

namespace Core {
	Button::Button() :
		_pressed(false),
		_mouseDown(false),
		_mouseMove(false),
		_rect(0, 0, 1, 1)
	{

	}

	Button::~Button() {

	}

	void Button::Draw() {
		if (_mouseDown && _mouseMove) {
			render.SetPolygonMode(POLY_FILL);
		} else {
			render.SetPolygonMode(POLY_LINE);
		}
		render.DrawRect(_rect);
		render.ResetPolygonMode();
	}

	void Button::Update(float dt) {

	}

	void Button::MouseDown(const IPoint& mousePos) {
		_mouseDown = _rect.Contain(mousePos);
		_mouseMove = _mouseDown;
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
};