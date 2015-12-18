#pragma once
#include "Core.h"
#include "Math.h"
#include "Widget.h"

class GameField : public Core::Widget {
public:
	GameField();
	virtual ~GameField();
	virtual void Draw();
	virtual void Update(float dt);
	virtual void MouseDown(const IPoint& mousePos);
	virtual void MouseMove(const IPoint& mousePos);
	virtual void MouseUp(const IPoint& mousePos);
	virtual void KeyPress(unsigned char key);

	void SetWindowParams();
	void Save();
	void Load();
};