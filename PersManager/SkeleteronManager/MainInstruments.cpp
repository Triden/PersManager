#include "MainInstruments.h"

#define SKELETON_INSTRUMENTS_W 60
#define SKELETON_INSTRUMENTS_H 120

const int MainInstruments::BUTTONS_IN_THE_ROW = 2;
const int MainInstruments::B_WIDTH = 20;

MainInstruments::MainInstruments() :
	Core::Panel(
		IRect(Core::screen.GLWidth() - SKELETON_INSTRUMENTS_W,
			Core::screen.GLHeight() - SKELETON_INSTRUMENTS_H,
			SKELETON_INSTRUMENTS_W,
			SKELETON_INSTRUMENTS_H), 5)
{
	MoveTo(IPoint(GetRect().x, GetRect().y - GetCaptionRect().height));

	//Init buttons
	_makeBone.Create(IRect(0, 0, B_WIDTH, B_WIDTH));
	_makeBone.SetIcon(Core::resourceManager.GetPoly("bone"));
}

void MainInstruments::Init() {
	_buttons.clear();
	_buttons.push_back(&_makeBone);

	MoveButtons();
}

MainInstruments::~MainInstruments() {
}

void MainInstruments::MoveButtons() {
	float x = GetBorderedRect().x;
	float y = GetBorderedRect().y;
	int bSize = _buttons.size();
	for (int i = 0; i < bSize; ++i) {
		if (i % 2 == 0 && i != 0) {
			x += B_WIDTH;
		}
		else {
			x = GetBorderedRect().x;
		}

		if (i % 2 == 0 && i != 0) {
			y -= B_WIDTH;
		}

		_buttons[i]->MoveTo(IPoint(x, y));
	}
}

void MainInstruments::Draw() {
	Panel::Draw();
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->Draw();
	}
}

void MainInstruments::Update(float dt) {
	Panel::Update(dt);
	MoveButtons();
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->Update(dt);
	}
}

bool MainInstruments::MouseDown(const IPoint& pnt) {
	bool res = Panel::MouseDown(pnt);
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->MouseDown(pnt);
	}
	return res;
}

void MainInstruments::MouseMove(const IPoint& pnt) {
	Panel::MouseMove(pnt);
	int bSize = _buttons.size();
	for (int i = 0; i < bSize; ++i) {
		if (_buttons[i] != NULL) {
			_buttons[i]->MouseMove(pnt);
		}
	}
}

void MainInstruments::MouseUp(const IPoint& pnt) {
	Panel::MouseUp(pnt);
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->MouseUp(pnt);
	}
}