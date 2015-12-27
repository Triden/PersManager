#ifndef ENGINE_MATH
#define ENGINE_MATH

#include <algorithm>
#include <vector>

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

class FPolygon {
public:
	FPoint v1;
	FPoint v2;
	FPoint v3;
	FPolygon() :
		v1(FPoint()), v2(FPoint()), v3(FPoint())
	{}
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

	bool Contain(const IPoint& point) {
		return (point.x > x &&
				point.y > y &&
				point.x < x + width &&
				point.y < y + height);
	}
};

#endif