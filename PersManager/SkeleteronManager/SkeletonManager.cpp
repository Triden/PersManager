#include "SkeletonManager.h"

SkeletonManager* SkeletonManager::_instance = NULL;

SkeletonManager* SkeletonManager::Instance() {
	return _instance;
}

SkeletonManager::SkeletonManager() :
	_scaleManager(1.f, 0.1f)
{
	Assert(_instance == NULL);
	_instance = this;
}

SkeletonManager::~SkeletonManager() {
	_instance = NULL;
}

ScaleManager* SkeletonManager::GetScaleManager() {
	return &_scaleManager;
}

void SkeletonManager::Draw() {
	//Поле
	_field.Draw();
	//Инструменты
	_scaleManager.Draw();
	_instrumentsPanel.Draw();
}

void SkeletonManager::Update(float dt) {
	_field.Update(dt);
	_instrumentsPanel.Update(dt);
}

void SkeletonManager::MouseDown(const IPoint& pnt) {
	if (!_instrumentsPanel.MouseDown(pnt)) {
		if (!_field.MouseDown(pnt)) {
			_scaleManager.MouseDown(pnt);
		}
	}
}

void SkeletonManager::MouseMove(const IPoint& pnt) {
	_instrumentsPanel.MouseMove(pnt);
	_field.MouseMove(pnt);
	_scaleManager.MouseMove(pnt);
}

void SkeletonManager::MouseUp(const IPoint& pnt) {
	_instrumentsPanel.MouseUp(pnt);
	_field.MouseUp(pnt);
	_scaleManager.MouseUp(pnt);
}

void SkeletonManager::MouseWheel(int dir, const IPoint& mousePos) {
	_scaleManager.MouseWheel(dir, mousePos);
}

void SkeletonManager::KeyPress(unsigned char key) {
	_field.KeyPress(key);
}