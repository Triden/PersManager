#include "SkeletonInstruments.h"

#include "..\Engine\Assertion.h"

SkeletonInstruments* SkeletonInstruments::_instance = NULL;

SkeletonInstruments::SkeletonInstruments()
{
	Assert(_instance == NULL);
	_instance = this;
	_instruments.push_back(new InstrumentsPanel());
	_instruments.back()->Init();
	_instruments.back()->SetActive();
}

void SkeletonInstruments::SetState(SkeletonState state) {
	//Отлавливаем ошибки
	if (state == BONE_TO_ADD_POINT_1) {
		Assert(_state == NONE);
	} else if (state == BONE_TO_ADD_POINT_2) {
		Assert(_state == BONE_TO_ADD_POINT_1);
	} else if (state == NONE) {
		for (int i = 0; i < _instruments.size(); ++i) {
			_instruments[i]->ResetButtons();
		}
	}

	_state = state;
}

SkeletonInstruments::~SkeletonInstruments() {
	std::vector<InstrumentsPanel *>::iterator it;
	for (it = _instruments.begin(); it != _instruments.end(); ) {
		delete *it;
		it = _instruments.erase(it);
	}
}

void SkeletonInstruments::Draw() {
	for (int i = 0; i < (int)_instruments.size(); ++i) {
		_instruments[i]->Draw();
	}
}

void SkeletonInstruments::Update(float dt) {
	for (int i = 0; i < (int)_instruments.size(); ++i) {
		_instruments[i]->Update(dt);
	}
}

bool SkeletonInstruments::MouseDown(const IPoint& pnt) {
	for (int i = (int)_instruments.size() - 1; i >= 0 ; --i) {	//Проверяем в обратном порядке, потому что рисуются они в обычном
		if (_instruments[i]->MouseDown(pnt)) {
			//Ресетим все панели
			for (int j = 0; j < (int)_instruments.size(); ++j) {
				_instruments[j]->ResetActive();
			}
			//Меняем местами панели для отрисовки
			std::swap(_instruments[i], _instruments[(int)_instruments.size() - 1]);
			_instruments[(int)_instruments.size() - 1]->SetActive();
			return true;
		}
	}
	return false;
}

void SkeletonInstruments::MouseMove(const IPoint& pnt) {
	for (int i = 0; i < (int)_instruments.size(); ++i) {
		_instruments[i]->MouseMove(pnt);
	}
}

void SkeletonInstruments::MouseUp(const IPoint& pnt) {
	for (int i = 0; i < (int)_instruments.size(); ++i) {
		_instruments[i]->MouseUp(pnt);
	}
}