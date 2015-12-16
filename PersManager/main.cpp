#include "Core.h"
#include "Application.h"

Core _core(30, 100, 100, 200, 200);
Application _app;

void UpdateGL(int value) {
	_core.UpdateGL(value);
	glutTimerFunc(_core.GetScreen()->UpdateRate(), UpdateGL, value); // Вызываем следующий таймер
}

void MouseDownGL(int button, int state, int x, int y) {
	_core.MouseDownGL(button, state, x, y);
}

void MouseMoveGL(int x, int y) {
	_core.MouseMoveGL(x, y);
}

void KeyPressGL(unsigned char key, int x, int y) {
	_core.KeyPressGL(key, x, y);
}

void Empty() {
}

int main(int argc, char **argv)
{
	_core.Start(argc, argv);

	glutInit(&argc, argv);
	_core.InitOpenGlContex();

	// register callbacks
	glutDisplayFunc(Empty);
	glutKeyboardFunc(KeyPressGL);
	glutMouseFunc(MouseDownGL);
	glutPassiveMotionFunc(MouseMoveGL);
	glutTimerFunc(_core.GetScreen()->UpdateRate(), UpdateGL, 0);	//UpdateGL callback
	glutMainLoop();

	return 0;
}