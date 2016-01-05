#include "ScaleManager.h"

ScaleManager::ScaleManager(float initScale, float speed) :
	_scale(initScale),
	_speed(speed),
	_basePos(0.f, 0.f),
	_pressed(false),
	_mouseDown()
{
}

void ScaleManager::MouseWheel(int dir, const IPoint& pnt) {
	//pnt - точка в оригинальных координатах
	//Когда мы скроллим _startPnt тоже изменяется
	FPoint scaled = GetPointScaled(pnt);

	float coef = 0.f;
	if (dir > 0) {	//zoom in
		coef = 1.f;
	} else if (dir < 0) {	//zoom out
		coef = -1.f;
	}

	float scale = _scale + coef * _speed;
	if (scale > _speed) {
		_scale = scale;
		//Меняем базовую точку в зависимости от масштаба
		_basePos.x -= coef * scaled.x / (1.f / _speed);
		_basePos.y -= coef * scaled.y / (1.f / _speed);
	}
}

void ScaleManager::Update(float dt) {
}

float ScaleManager::GetScale() {
	return _scale;
}

const FPoint& ScaleManager::GetMove() {
	return _basePos;
}

FPoint ScaleManager::GetPointScaled(const FPoint& point) {
	FPoint res(point);
	res -= _basePos;
	res /= _scale;
	return res;
}

FPoint ScaleManager::GetPointField(const FPoint& point) {
	FPoint res(point);
	res *= _scale;
	res += _basePos;
	return res;
}

void ScaleManager::MouseDown(const IPoint& pnt) {
	_points.push_back(GetPointScaled(pnt));

	_pressed = true;
	_mouseDown = pnt;
}

void ScaleManager::MouseMove(const IPoint& pnt) {
	if (_pressed) {
		_basePos = _basePos + pnt - _mouseDown;
		_mouseDown = pnt;
	}
}

void ScaleManager::MouseUp(const IPoint& pnt) {
	_pressed = false;
}

void ScaleManager::Draw() {
	for (int i = 0; i < (int)_points.size(); ++i) {
		FPoint pnt = GetPointField(_points[i]);
		Core::render.DrawRect(IRect(pnt.x, pnt.y, 2, 2));
	}
}

IRect ScaleManager::GetScaledRect() {
	FPoint topRigth(Core::screen.GLWidth(), Core::screen.GLHeight());
	FPoint bottomLeft(0, 0);
	topRigth = GetPointScaled(topRigth);
	bottomLeft = GetPointScaled(bottomLeft);
	return IRect(bottomLeft.x, bottomLeft.y, topRigth.x, topRigth.y);
}