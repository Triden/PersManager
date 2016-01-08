#ifndef ENGINE_TYPES
#define ENGINE_TYPES
#include <string>
#include <map>
#include "Math.h"

namespace Int {
	inline std::string ToString(const int& i) {
		return std::to_string(i);
	};
};

namespace String {
	inline int ToInt(const std::string& str) {
		return std::stoi(str);
	}
	inline float ToFloat(const std::string& str) {
		return std::stof(str);
	}
}

class Color {
public:
	static const Color RED;
	static const Color WHITE;
	static const Color GREEN;
	static const Color BLUE;
	static const Color LIGHT_PINK;
	static const Color PINK;
	static const Color BLUE_VIOLET;
	static const Color LIGHT_GRAY;
	static const Color YELLOW;
	static const Color LIGHT_RED;
	static const Color DARK_RED;
	static const Color DARK_BLUE;

	float r;
	float g;
	float b;
	Color() : r(0.f), g(0.f), b(0.f) {};
	Color(float r_, float g_, float b_) : r(r_), g(g_), b(b_) {};
};

struct Bone {
	FPoint p;	//Точка из которой выходит луч
	float l;	//Длина луча
	float a;	//Угол под которым этот луч расположен
	static Bone PointsToBone(FPoint pnt1, FPoint pnt2);
	static FPolygon BoneToPolygon(const Bone& bone);
};


#endif ENGINE_TYPES