#include "GameField.h"

GameField::GameField() 
{
	Core::screen.SetFixed(false);
}

GameField::~GameField() {
};

void GameField::Draw() {
	Core::render.DrawLine(IPoint(0, 0), IPoint(100, 100));
};

void GameField::Update(float dt) {
};

void GameField::MouseDown(const IPoint& mousePos) {
};

void GameField::MouseMove(const IPoint& mousePos) {
};

void GameField::MouseUp(const IPoint& mousePos) {
};

void GameField::KeyPress(unsigned char key) {
};