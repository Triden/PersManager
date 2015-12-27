#ifndef ENGINE_APPLICATION
#define ENGINE_APPLICATION

#include "Screen.h"
#include "Math.h"
#include "Widget.h"

#include "..\..\Dependencies\glew\glew.h"
#include "..\..\Dependencies\freeglut\freeglut.h"

namespace Core {
	class Application {
	private:
		std::vector<Widget *> _widgets;
	public:
		Application();
		void UpdateGL(int value);
		void OnStart();
		void InitOpenGlContex(int argc, char **argv);
		void InitWindow();
		void Draw();
		void Update(float dt);
		void InitWindowSize(int width, int height);
		void InitGlView(int width, int height, int glWidth, int glHeight);
		void OnResize();
		void OnResize(int width, int height);
		void KeyPress(unsigned char key);
		void KeyPressGL(unsigned char key, int x, int y);
		void MouseMoveGL(int x, int y);
		void MouseMove(const IPoint& mousePos);
		void MouseGL(int button, int state, int x, int y);
		void MouseDown(const IPoint& mousePos);
		void MouseUp(const IPoint& mousePos);
		void AddWidget(Widget *widget);
		IPoint ScreenSize();	//Реальный размер экрана
		void SetWindowPos(IPoint pos);
		void SwitchFullScreen();
	};
	extern Application application;
};

#endif