#pragma once
#include "Core.h"

class Application : public Widget {
public:
	Application();
	virtual ~Application();
	virtual void Draw();
	virtual void Update(float dt);
	virtual void MouseDown(const IPoint& mousePos);
	virtual void MouseMove(const IPoint& mousePos);
	virtual void MouseUp(const IPoint& mousePos);
	virtual void KeyPress(unsigned char key);
};