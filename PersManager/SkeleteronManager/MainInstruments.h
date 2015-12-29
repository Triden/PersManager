#ifndef SKELETON_MAIN_INSTRUMENTS
#define SKELETON_MAIN_INSTRUMENTS

#include "..\Engine\Include.h"

//Основная панель с инструментами

class MainInstruments : public Core::Panel {
private:
	static const int BUTTONS_IN_THE_ROW;
	static const int B_WIDTH;

	Core::ActiveButton _makeBone;
	std::vector<Core::ActiveButton *> _buttons;
public:
public:
	MainInstruments();
	~MainInstruments();
	virtual void Draw();
	virtual void Update(float dt);
	virtual bool MouseDown(const IPoint& pnt);
	virtual void MouseMove(const IPoint& pnt);
	virtual void MouseUp(const IPoint& pnt);
	virtual void MoveButtons();
	void Init();
};
#endif