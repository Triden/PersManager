#include "GameMain.h"

GameMain::GameMain() 
{
	Core::render.SetPolygonMode(POLY_FILL);
	Core::render.SetLineWidth(1);
	Core::screen.SetFixed(false);
	_button.Create(IRect(100, 100, 20, 20));
}

GameMain::~GameMain() {
};

void GameMain::Draw() {
	Core::render.DrawLine(IPoint(0, 0), IPoint(100, 100));
	_button.Draw();
};

void GameMain::Update(float dt) {
	_button.Update(dt);
};

void GameMain::MouseDown(const IPoint& mousePos) {
	SetWindowParams();
	Save();
	_button.MouseDown(mousePos);
};

void GameMain::MouseMove(const IPoint& mousePos) {
	_button.MouseMove(mousePos);
};

void GameMain::MouseUp(const IPoint& mousePos) {
	Load();
	_button.MouseUp(mousePos);
};

void GameMain::KeyPress(unsigned char key) {
};

void GameMain::SetWindowParams() {

}

void GameMain::Save() {
	Core::writer.Save();
}

void GameMain::Load() {
	Core::writer.Load();
}