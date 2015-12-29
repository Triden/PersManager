#include "Button.h"
#include "Render.h"
#include <iostream>

namespace Core {
	Button::Button() :
		_mouseDown(false),
		_mouseMove(false),
		_rect(0, 0, 1, 1),
		_icon(NULL)
	{

	}

	Button::~Button() {
		_icon = NULL;
	}

	void Button::DrawIcon() {
		if (_icon != NULL) {
			FPoint center(_rect.x + _rect.width / 2.f, _rect.y + _rect.height / 2.f);
			_icon->Draw(center.x - _icon->GetSize().x / 2.f, center.y - _icon->GetSize().y / 2.f);
		}
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

		DrawIcon();
	}

	void Button::Update(float dt) {

	}

	void Button::SetIcon(PolyObject* icon) {
		_icon = icon;
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


	ActiveButton::ActiveButton() :
		_check(false)
	{
	}

	ActiveButton::~ActiveButton() {
	}

	void ActiveButton::Draw() {
		if (!_check) {
			Button::Draw();
		} else {
			if (_mouseDown && _mouseMove) {
				render.SetColor(Color::LIGHT_RED);
			} else {
				render.SetColor(Color::RED);
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
			DrawIcon();
		}
	}

	bool ActiveButton::MouseDown(const IPoint& mousePos) {
		return Button::MouseDown(mousePos);
	}

	void ActiveButton::MouseMove(const IPoint& mousePos) {
		Button::MouseMove(mousePos);
	}

	void ActiveButton::MouseUp(const IPoint& mousePos) {
		if (_mouseDown && _mouseMove) {
			_check = !_check;
		}
		Button::MouseUp(mousePos);
	}
};