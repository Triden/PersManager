#include "GameMain.h"

GameMain::GameMain() 
{
	Core::render.SetPolygonMode(POLY_FILL);
	Core::render.SetLineWidth(1);
	Core::screen.SetFixed(false);
	
}

GameMain::~GameMain() {
};

void GameMain::Draw() {
	_skeletonManager.Draw();
};

void GameMain::Update(float dt) {
	_skeletonManager.Update(dt);
};

void GameMain::MouseDown(const IPoint& mousePos) {
	_skeletonManager.MouseDown(mousePos);
};

void GameMain::MouseMove(const IPoint& mousePos) {
	_skeletonManager.MouseMove(mousePos);
};

void GameMain::MouseUp(const IPoint& mousePos) {
	_skeletonManager.MouseUp(mousePos);
};

void GameMain::KeyPress(unsigned char key) {
};

void GameMain::SetWindowParams() {

}