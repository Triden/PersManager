#ifndef SKELETON_MAIN_INSTRUMENTS
#define SKELETON_MAIN_INSTRUMENTS

#include "..\Engine\Include.h"
#include "States.h"
//Основная панель с инструментами

class InstrumentsButton : public Core::ActiveButton {
	private:
		SkeletonState _state;	//Состояние, которая она устанавливает менеджеру инструментов
	public:
		InstrumentsButton(SkeletonState state);
		SkeletonState GetState() { return _state; }
};

class InstrumentsPanel : public Core::Panel {
private:
	static const int BUTTONS_IN_THE_ROW;
	static const int B_WIDTH;

	InstrumentsButton _makeBone;
	std::vector<InstrumentsButton *> _buttons;
public:
	InstrumentsPanel();
	~InstrumentsPanel();
	virtual void Draw();
	virtual void Update(float dt);
	virtual bool MouseDown(const IPoint& pnt);
	virtual void MouseMove(const IPoint& pnt);
	virtual void MouseUp(const IPoint& pnt);
	virtual void MoveButtons();
	void Init();
	void ResetButtons();
};
#endif