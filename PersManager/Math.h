#ifndef ENGINE_MATH
#define ENFINE_MATH

#pragma once
#include <algorithm>

class IPoint {
public:
	int x;
	int y;
	IPoint() : x(0), y(0) {}
	IPoint(int x, int y) : x(x), y(y) {}
};

class FPoint {
public:
	float x;
	float y;
	FPoint() : x(0.f), y(0.f) {}
	FPoint(float x, float y) : x(x), y(y) {}
};

class IRect {
public:
	int x;
	int y;
	int width;
	int height;

	IRect() :
		x(0),
		y(0),
		width(0),
		height(0)
	{}

	IRect(int x, int y, int width, int height) :
		x(x),
		y(y),
		width(width),
		height(height)
	{}
};

#endif