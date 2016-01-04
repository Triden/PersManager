#include "SkeletonManager.h"

SkeletonManager::SkeletonManager() :
	_grid(20),
	_scaleManager(1.f, 0.1f)
{
}

SkeletonManager::~SkeletonManager() {

}

void SkeletonManager::Draw() {
	Core::render.PushMatrix();
	FPoint move = _scaleManager.GetMove();
	Core::render.MatrixMove(move);
	Core::render.MatrixScale(_scaleManager.GetScale());
	_grid.Draw(_scaleManager.GetScaledRect());
	Core::render.PopMatrix();

	_scaleManager.Draw();
	_instrumentsPanel.Draw();
}

void SkeletonManager::Update(float dt) {
	_grid.Update(dt);
	_instrumentsPanel.Update(dt);
}

void SkeletonManager::MouseDown(const IPoint& pnt) {
	if (!_instrumentsPanel.MouseDown(pnt)) {
		_scaleManager.MouseDown(pnt);
	}
}

void SkeletonManager::MouseMove(const IPoint& pnt) {
	_instrumentsPanel.MouseMove(pnt);
	_scaleManager.MouseMove(pnt);
}

void SkeletonManager::MouseUp(const IPoint& pnt) {
	_instrumentsPanel.MouseUp(pnt);
	_scaleManager.MouseUp(pnt);
}

void SkeletonManager::MouseWheel(int dir, const IPoint& mousePos) {
	_scaleManager.MouseWheel(dir, mousePos);
}