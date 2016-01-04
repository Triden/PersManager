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
	for (int i = (int)_instruments.size() - 1; i >= 0 ; --i) {	//ѕровер€ем в обратном пор€дке, потому что рисуютс€ они в обычном
		if (_instruments[i]->MouseDown(pnt)) {
			//–есетим все панели
			for (int j = 0; j < (int)_instruments.size(); ++j) {
				_instruments[j]->ResetActive();
			}
			//ћен€ем местами панели дл€ отрисовки
			std::swap(_instruments[i], _instruments[(int)_instruments.size() - 1]);
			_instruments[(int)_instruments.size() - 1]->SetActive();
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