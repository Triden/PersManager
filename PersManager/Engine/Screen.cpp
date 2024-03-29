#include "Screen.h"

namespace Core {
	#define DEFAULT_ONE_SECOND 1000.f

	Screen::Screen(int fps, int screenWidth, int screenHeight, int glWidth, int glHeight) :
		_fps(fps),
		_width(screenWidth),
		_height(screenHeight),
		_glWidth(glWidth),
		_glHeight(glHeight),
		_fixed(true),
		_ONE_SECOND(DEFAULT_ONE_SECOND)
	{

	}

	Screen::Screen() :
		_fps(60),
		_width(640),
		_height(480),
		_glWidth(266),
		_glHeight(200),
		_fixed(true),
		_ONE_SECOND(DEFAULT_ONE_SECOND)
	{

	}

	void Screen::SetSize(int width, int height) {
		_width = width;
		_height = height;
	}

	void Screen::SetGlSize(float glWidth, float glHeight) {
		_glWidth = glWidth;
		_glHeight = glHeight;
	}

	void Screen::SetFPS(int fps) {
		_fps = fps;
	}

	void Screen::SetFixed(bool fixed) {
		_fixed = fixed;
	}

	int Screen::Width() {
		return _width;
	}

	int Screen::Height() {
		return _height;
	}

	float Screen::GLWidth() {
		return _glWidth;
	}

	float Screen::GLHeight() {
		return _glHeight;
	}

	int Screen::FPS() {
		return _fps;
	}

	bool Screen::Fixed() {
		return _fixed;
	}

	float Screen::OneSecond() {
		return _ONE_SECOND;
	}

	void Screen::SetOneSecond(float oneSecond) {
		_ONE_SECOND = oneSecond;
	}

	int Screen::UpdateRate() {
		return int((OneSecond() * 1.f) / FPS());
	}

	void Screen::OnResize(int width, int height) {
		if (_fixed) {
			_width = width;
			_height = height;
			SetGlSize(_glWidth, _glHeight);
		} else {
			int oldW = _width;
			int oldH = _height;

			float oldGW = _glWidth;
			float oldGH = _glHeight;

			SetSize(width, height);

			float coefW = oldGW / oldW;
			float coefH = oldGH / oldH;

			SetGlSize(width * coefW, height * coefH);
		}
	}

	void Screen::MouseDown(const IPoint& mousePos) {
		_mousePos = mousePos;
	}

	void Screen::MouseMove(const IPoint& mousePos) {
		_mousePos = mousePos;
	}

	void Screen::MouseUp(const IPoint& mousePos) {
		_mousePos = mousePos;
	}
};