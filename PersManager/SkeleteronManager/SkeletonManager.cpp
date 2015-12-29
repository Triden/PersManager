#include "SkeletonManager.h"

SkeletonManager::SkeletonManager() {
}

SkeletonManager::~SkeletonManager() {

}

void SkeletonManager::Draw() {
	Core::render.SetColor(Color::GREEN);
	_instrumentsPanel.Draw();
	_instrumentsPanel2.Draw();
	Core::render.ResetColor();
}

void SkeletonManager::Update(float dt) {
	_instrumentsPanel.Update(dt);
	_instrumentsPanel2.Update(dt);
}

void SkeletonManager::MouseDown(const IPoint& pnt) {
	if (!_instrumentsPanel.MouseDown(pnt)) {
		_instrumentsPanel2.MouseDown(pnt);
	}
}

void SkeletonManager::MouseMove(const IPoint& pnt) {
	_instrumentsPanel.MouseMove(pnt);
	_instrumentsPanel2.MouseMove(pnt);
}

void SkeletonManager::MouseUp(const IPoint& pnt) {
	_instrumentsPanel.MouseUp(pnt);
	_instrumentsPanel2.MouseUp(pnt);
}