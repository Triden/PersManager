#include "Types.h"

const Color Color::RED = Color(1.f, 0.f, 0.f);
const Color Color::WHITE = Color(1.f, 1.f, 1.f);
const Color Color::GREEN = Color(0.f, 1.f, 0.f);
const Color Color::BLUE = Color(0.f, 0.f, 1.f);
const Color Color::LIGHT_PINK = Color(0.99f, 0.612f, 1.f);
const Color Color::PINK = Color(1.f, 0.f, 1.f);
const Color Color::BLUE_VIOLET = Color(0.62352f, 0.372549f, 0.623529f);
const Color Color::LIGHT_GRAY = Color(0.92f, 0.93f, 0.925f);
const Color Color::YELLOW = Color(0xFD / 255.f, 0xFD / 255.f, 0x99 / 255.f);
const Color Color::LIGHT_RED = Color(0xFF / 255.f, 0x96 / 255.f, 0x96 / 255.f);
const Color Color::DARK_RED = Color(94.f / 255.f, 4.f / 255.f, 14.f / 255.f);
const Color Color::DARK_BLUE = Color(0.f, 0.f, 0.5f);

Bone Bone::PointsToBone(FPoint pnt1, FPoint pnt2) {
	Bone bone;
	bone.p = pnt1;
	float h = pnt2.y - pnt1.y;
	float w = pnt2.x - pnt1.x;
	float r2 = w * w + h * h;
	bone.l = sqrtf(r2);

	float a = atan2(pnt1.y - pnt2.y, pnt1.x - pnt2.x) / M_PI * 180.f;
	a = (a < 0) ? a + 360.f : a;   //Без этого диапазон от 0...180 и -1...-180
	a -= 180.f;

	bone.a = a / 180.f * M_PI;
	return bone;
}

FPolygon Bone::BoneToPolygon(const Bone& bone) {
	FPolygon poly;
	const float W = 0.05f * bone.l;	//Ширина основания
	poly.v1 = FPoint(W * cosf(bone.a - M_PI / 2.f),
		W * sinf(bone.a - M_PI / 2.f)) + bone.p;
	poly.v2 = FPoint(W * cosf(bone.a + M_PI / 2.f),
		W * sinf(bone.a + M_PI / 2.f)) + bone.p;
	poly.v3 = FPoint(bone.l * cosf(bone.a), bone.l * sinf(bone.a)) + bone.p;
	return poly;
}