#include "GameField.h"

GameField::GameField() 
{
	Core::render.SetPolygonMode(POLY_FILL);
	Core::render.SetLineWidth(1);
	Core::screen.SetFixed(false);
	_button.Create(IRect(100, 100, 20, 20));
}

GameField::~GameField() {
};

void GameField::Draw() {
	Core::render.DrawLine(IPoint(0, 0), IPoint(100, 100));
	_button.Draw();
};

void GameField::Update(float dt) {
	_button.Update(dt);
};

void GameField::MouseDown(const IPoint& mousePos) {
	SetWindowParams();
	Save();
	_button.MouseDown(mousePos);
};

void GameField::MouseMove(const IPoint& mousePos) {
	_button.MouseMove(mousePos);
};

void GameField::MouseUp(const IPoint& mousePos) {
	Load();
	_button.MouseUp(mousePos);
};

void GameField::KeyPress(unsigned char key) {
};

void GameField::SetWindowParams() {

}

void GameField::Save() {
	Core::writer.Save();
}

void GameField::Load() {
	Core::writer.Load();
}