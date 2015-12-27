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
	
	FPoint operator -(const FPoint& point) {
		return FPoint(x - point.x, y - point.y);
	};
	FPoint operator +(const FPoint& point) {
		return FPoint(x + point.x, y + point.y);
	};

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
	FPoint GetMin() {
		FPoint min(v1);
		if (v2.x < min.x) {
			min.x = v2.x;
		}
		if (v3.x < min.x) {
			min.x = v3.x;
		}
		if (v2.y < min.y) {
			min.y = v2.y;
		}
		if (v3.y < min.y) {
			min.y = v3.y;
		}
		return min;
	}
	FPoint GetMax() {
		FPoint max(v1);
		if (v2.x > max.x) {
			max.x = v2.x;
		}
		if (v3.x > max.x) {
			max.x = v3.x;
		}
		if (v2.y > max.y) {
			max.y = v2.y;
		}
		if (v3.y > max.y) {
			max.y = v3.y;
		}
		return max;
	}
	void Scale(float scale) {
		v1.x *= scale;
		v1.y *= scale;
		v2.x *= scale;
		v2.y *= scale; 
		v3.x *= scale;
		v3.y *= scale;
	}
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