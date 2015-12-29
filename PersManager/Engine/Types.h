#ifndef ENGINE_TYPES
#define ENGINE_TYPES
#include <string>
#include <map>

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

	float r;
	float g;
	float b;
	Color() : r(0.f), g(0.f), b(0.f) {};
	Color(float r_, float g_, float b_) : r(r_), g(g_), b(b_) {};
};

#endif ENGINE_TYPES