#include "SkeletonManager.h"

SkeletonManager::SkeletonManager() {
}

SkeletonManager::~SkeletonManager() {

}

void SkeletonManager::Draw() {
	Core::render.SetColor(Color::GREEN);
	_instrumentsPanel.Draw();
	Core::render.ResetColor();
}

void SkeletonManager::Update(float dt) {
	_instrumentsPanel.Update(dt);
}

void SkeletonManager::MouseDown(const IPoint& pnt) {
	_instrumentsPanel.MouseDown(pnt);
}

void SkeletonManager::MouseMove(const IPoint& pnt) {
	_instrumentsPanel.MouseMove(pnt);
}

void SkeletonManager::MouseUp(const IPoint& pnt) {
	_instrumentsPanel.MouseUp(pnt);
}