#pragma once
#include "Engine.h"

class Widget {
private:
	bool _addToList;
protected:
	typedef std::vector <Widget *> Widgets;
	static Widgets _widgets;
public:
	Widget(bool addToList = true);
	virtual ~Widget();
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void MouseDown(const IPoint& mousePos) = 0;
	virtual void MouseMove(const IPoint& mousePos) = 0;
	virtual void MouseUp(const IPoint& mousePos) = 0;
	virtual void KeyPress(unsigned char key) = 0;
};

class Core : public Widget {
private:
	static Screen _screen;
public:
	Core(int fps, int screenWidth, int screenHeight, int glWidth, int glHeight);
	~Core();

	void OnStart();
	static void Empty();
	void InitOpenGlContex();
	void InitGlView(int width, int height, int glWidth, int glheight);

	void Draw();

	void UpdateGL(int value);
	void Update(float dt);

	void MouseGL(int button, int state, int x, int y);
	void MouseDown(const IPoint& mousePos);
	void MouseUp(const IPoint& mousePos);

	void MouseMoveGL(int x, int y);
	void MouseMove(const IPoint& mousePos);

	void KeyPressGL(unsigned char key, int x, int y);
	void KeyPress(unsigned char key);

	void OnResize(int width, int height);

	static Screen* GetScreen() { return &_screen; }
};