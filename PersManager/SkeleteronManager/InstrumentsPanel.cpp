#include "InstrumentsPanel.h"
#include "SkeletonInstruments.h"

#define SKELETON_INSTRUMENTS_W 60
#define SKELETON_INSTRUMENTS_H 120

const int InstrumentsPanel::BUTTONS_IN_THE_ROW = 2;
const int InstrumentsPanel::B_WIDTH = 20;

InstrumentsButton::InstrumentsButton(SkeletonState state) :
	ActiveButton(),
	_state(state)
{
}

InstrumentsPanel::InstrumentsPanel() :
	Core::Panel(
		IRect(Core::screen.GLWidth() - SKELETON_INSTRUMENTS_W,
			Core::screen.GLHeight() - SKELETON_INSTRUMENTS_H,
			SKELETON_INSTRUMENTS_W,
			SKELETON_INSTRUMENTS_H), 5),
	_makeBone(BONE_TO_ADD_POINT_1)
{
	MoveTo(IPoint(GetRect().x, GetRect().y - GetCaptionRect().height));

	//Init buttons
	_makeBone.Create(IRect(0, 0, B_WIDTH, B_WIDTH));
	_makeBone.SetIcon(Core::resourceManager.GetPoly("bone"));
}

void InstrumentsPanel::Init() {
	_buttons.clear();
	_buttons.push_back(&_makeBone);

	MoveButtons();
}

InstrumentsPanel::~InstrumentsPanel() {
}

void InstrumentsPanel::MoveButtons() {
	float x = GetBorderedRect().x;
	float y = GetBorderedRect().y;
	int bSize = _buttons.size();
	for (int i = 0; i < bSize; ++i) {
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

void InstrumentsPanel::Draw() {
	Panel::Draw();
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->Draw();
	}
}

void InstrumentsPanel::Update(float dt) {
	Panel::Update(dt);
	MoveButtons();
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->Update(dt);
	}
}

bool InstrumentsPanel::MouseDown(const IPoint& pnt) {
	bool res = Panel::MouseDown(pnt);
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		if (_buttons[i]->MouseDown(pnt)) {
			SkeletonInstruments::Instance()->SetState(_buttons[i]->GetState());
			_buttons[i]->SetEnable(false);
			return res;
		}
	}
	return res;
}

void InstrumentsPanel::MouseMove(const IPoint& pnt) {
	Panel::MouseMove(pnt);
	int bSize = _buttons.size();
	for (int i = 0; i < bSize; ++i) {
		if (_buttons[i] != NULL) {
			_buttons[i]->MouseMove(pnt);
		}
	}
}

void InstrumentsPanel::MouseUp(const IPoint& pnt) {
	Panel::MouseUp(pnt);
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->MouseUp(pnt);
	}
}

void InstrumentsPanel::ResetButtons() {
	for (int i = 0; i < (int)_buttons.size(); ++i) {
		_buttons[i]->SetChecked(false);
		_buttons[i]->SetEnable(true);
	}
}