#ifndef ENGINE_MATH
#define ENGINE_MATH

#include <algorithm>
#include <vector>

#define M_PI 3.14159265359f

class FPoint;

class IPoint {
public:
	int x;
	int y;

	IPoint operator +(const IPoint& point) {
		return IPoint(x + point.x, y + point.y);
	};
	IPoint operator -(const IPoint& point) {
		return IPoint(x - point.x, y - point.y);
	};
	IPoint operator-() const {
		return IPoint(-x, -y);
	}

	IPoint() : x(0), y(0) {}
	IPoint(const FPoint& point);
	IPoint(int x, int y) : x(x), y(y) {}
};

class FPoint {
public:
	float x;
	float y;
	
	FPoint operator -(const FPoint& point) const {
		return FPoint(x - point.x, y - point.y);
	};
	FPoint operator +(const FPoint& point) const {
		return FPoint(x + point.x, y + point.y);
	};
	FPoint operator *(const float& p) const {
		return FPoint(x * p, y * p);
	};
	FPoint operator /(const float& p) const {
		return FPoint(x / p, y / p);
	};
	void operator *=(const float& p) {
		x *= p;
		y *= p;
	};
	void operator /=(const float& p) {
		x /= p;
		y /= p;
	};
	FPoint operator-() const {
		return FPoint(-x, -y);
	}
	void operator +=(const FPoint& p) {
		x += p.x;
		y += p.y;
	}
	void operator -=(const FPoint& p) {
		x -= p.x;
		y -= p.y;
	}
	FPoint(const IPoint& point) : x(point.x), y(point.y) {}
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
		v1 *= scale;
		v2 *= scale;
		v3 *= scale;
	}
	bool Contain(FPoint pnt) {
		float k1 = (v1.x - pnt.x) * (v2.y - v1.y) - (v2.x - v1.x) * (v1.y - pnt.y);
		float k2 = (v2.x - pnt.x) * (v3.y - v2.y) - (v3.x - v2.x) * (v2.y - pnt.y);
		float k3 = (v3.x - pnt.x) * (v1.y - v3.y) - (v1.x - v3.x) * (v3.y - pnt.y);
		return ((k1 >= 0 && k2 >= 0 && k3 >= 0) ||
				(k1 < 0 && k2 < 0 && k3 < 0));
	}
};

class Circle {
public:
	FPoint c;	//Центр
	float r;
	Circle(FPoint center, float radius) : c(center), r(radius) {};
	Circle() {};
	bool Contain(FPoint pnt) {
		return ((pnt.x - c.x) * (pnt.x - c.x) + (pnt.y - c.y) * (pnt.y - c.y) <= r * r);
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