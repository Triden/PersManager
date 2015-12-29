#include "Instruments.h"
#include "Instruments.h"

#include "..\Engine\Assertion.h"

SkeletonInstrumentsPanel::SkeletonInstrumentsPanel()
{
	_instruments.push_back(new MainInstruments());
	_instruments.back()->Init();
	_instruments.push_back(new MainInstruments());
	_instruments.back()->Init();
	_instruments.back()->SetActive();
}

SkeletonInstrumentsPanel::~SkeletonInstrumentsPanel() {
	std::vector<MainInstruments *>::iterator it;
	for (it = _instruments.begin(); it != _instruments.end(); ) {
		delete *it;
		it = _instruments.erase(it);
	}
}

void SkeletonInstrumentsPanel::Draw() {
	for (int i = 0; i < (int)_instruments.size(); ++i) {
		_instruments[i]->Draw();
	}
}

void SkeletonInstrumentsPanel::Update(float dt) {
	for (int i = 0; i < (int)_instruments.size(); ++i) {
		_instruments[i]->Update(dt);
	}
}

bool SkeletonInstrumentsPanel::MouseDown(const IPoint& pnt) {
	MainInstruments *mInstr = NULL;
	for (int i = 0; i < (int)_instruments.size(); ++i) {
		if (_instruments[i]->Active()) {
			mInstr = _instruments[i];
		}
	}

	if (mInstr != NULL && mInstr->MouseDown(pnt)) {
		return true;
	}

	for (int i = (int)_instruments.size() - 1; i >= 0 ; --i) {	//Проверяем в обратном порядке, потому что рисуются они в обычном
		if (_instruments[i]->MouseDown(pnt)) {
			for (int j = 0; j < (int)_instruments.size(); ++j) {
				if (_instruments[j] != _instruments[i]) {
					_instruments[j]->ResetActive();
				}
			}

			return true;
		}
	}
	return false;
}

void SkeletonInstrumentsPanel::MouseMove(const IPoint& pnt) {
	for (int i = 0; i < (int)_instruments.size(); ++i) {
		_instruments[i]->MouseMove(pnt);
	}
}

void SkeletonInstrumentsPanel::MouseUp(const IPoint& pnt) {
	for (int i = 0; i < (int)_instruments.size(); ++i) {
		_instruments[i]->MouseUp(pnt);
	}
}