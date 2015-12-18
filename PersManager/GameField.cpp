#include "GameField.h"

GameField::GameField() 
{
}

GameField::~GameField() {
};

void GameField::Draw() {
	Core::render.DrawLine(IPoint(0, 0), IPoint(100, 100));
};

void GameField::Update(float dt) {
};

void GameField::MouseDown(const IPoint& mousePos) {
	SetWindowParams();
	Save();
};

void GameField::MouseMove(const IPoint& mousePos) {
};

void GameField::MouseUp(const IPoint& mousePos) {
	Load();
};

void GameField::KeyPress(unsigned char key) {
};

void GameField::SetWindowParams() {
	Core::screen.SetFixed(true);
	IPoint screenSize(Core::application.ScreenSize());
	Core::screen.SetSize(screenSize.x / 2, screenSize.y / 2);
	Core::application.OnResize();
	Core::application.SetWindowPos(IPoint(0, 0));
}

void GameField::Save() {
	Core::writer.Save();
}

void GameField::Load() {
	Core::writer.Load();
}