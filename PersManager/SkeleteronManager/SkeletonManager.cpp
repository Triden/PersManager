#include "SkeletonManager.h"

SkeletonManager::SkeletonManager() {
}

SkeletonManager::~SkeletonManager() {

}

void SkeletonManager::Draw() {
	_instrumentsPanel.Draw();
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