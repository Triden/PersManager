#include "Instruments.h"
#include "Instruments.h"

#define SKELETON_INSTRUMENTS_W 60
#define SKELETON_INSTRUMENTS_H 120

SkeletonInstrumentsPanel::SkeletonInstrumentsPanel() :
	Core::Panel(
		IRect(Core::screen.GLWidth() - SKELETON_INSTRUMENTS_W,
			Core::screen.GLHeight() - SKELETON_INSTRUMENTS_H,
			SKELETON_INSTRUMENTS_W,
			SKELETON_INSTRUMENTS_H), 5)
{
	MoveTo(IPoint(GetRect().x, GetRect().y - GetCaptionRect().height));
	//Init buttons
	_makeBone.Create(IRect(0, 0, B_WIDTH, B_WIDTH));
	_buttons.push_back(&_makeBone);

	MoveButtons();
}

SkeletonInstrumentsPanel::~SkeletonInstrumentsPanel() {

}

void SkeletonInstrumentsPanel::MoveButtons() {
	float x = GetBorderedRect().x;
	float y = GetBorderedRect().y;
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		if (i % 2 == 0 && i != 0) {
			x += B_WIDTH;
		} else {
			x = GetBorderedRect().x;
		}

		if (i % 2 == 0 && i != 0) {
			y -= B_WIDTH;
		}

		_buttons[i]->MoveTo(IPoint(x, y));
	}
}

void SkeletonInstrumentsPanel::Draw() {
	Panel::Draw();
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->Draw();
	}
}

void SkeletonInstrumentsPanel::Update(float dt) {
	Panel::Update(dt);
	MoveButtons();
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->Update(dt);
	}
}

bool SkeletonInstrumentsPanel::MouseDown(const IPoint& pnt) {
	bool res = Panel::MouseDown(pnt);
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->MouseDown(pnt);
	}
	return res;
}

void SkeletonInstrumentsPanel::MouseMove(const IPoint& pnt) {
	Panel::MouseMove(pnt);
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->MouseMove(pnt);
	}
}

void SkeletonInstrumentsPanel::MouseUp(const IPoint& pnt) {
	Panel::MouseUp(pnt);
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->MouseUp(pnt);
	}
}