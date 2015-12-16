#include "Screen.h"

Screen::Screen(int fps, int screenWidth, int screenHeight, int glWidth, int glHeight) :
	_fps(fps),
	_width(screenWidth),
	_height(screenHeight),
	_glWidth(glWidth),
	_glHeight(glHeight),
	_fixed(true),
	_ONE_SECOND(1000.f)
{

}

void Screen::SetSize(int width, int height) {
	_width = width;
	_height = height;
}

void Screen::SetGlSize(int glWidth, int glHeight) {
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

int Screen::GLWidth() {
	return _glWidth;
}

int Screen::GLHeight() {
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