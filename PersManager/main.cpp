#include "Core.h"
#include "GameField.h"

extern GameField gamefield;

void UpdateGL(int value) {
	Core::application.UpdateGL(value);
	glutTimerFunc(Core::screen.UpdateRate(), UpdateGL, value); // Вызываем следующий таймер
}

void MouseGL(int button, int state, int x, int y) {
	Core::application.MouseGL(button, state, x, y);
}

void MouseMoveGL(int x, int y) {
	Core::application.MouseMoveGL(x, y);
}

void KeyPressGL(unsigned char key, int x, int y) {
	Core::application.KeyPressGL(key, x, y);
}

void OnReshape(GLint newWidth, GLint newHeight) {
	static bool inited = false;	//Костыль для предотвращения изменения размера после запуска приложения
	if (!inited) {
		inited = true;
	} else {
		Core::application.OnResize(newWidth, newHeight);
	}
}

void Empty() {
}

int main(int argc, char **argv)
{
	Core::application.OnStart();
	Core::application.InitOpenGlContex(argc, argv);
	Core::application.AddWidget(new GameField());
	
	// register callbacks
	glutDisplayFunc(Empty);
	glutKeyboardFunc(KeyPressGL);
	glutMouseFunc(MouseGL);
	glutPassiveMotionFunc(MouseMoveGL);
	glutReshapeFunc(OnReshape);
	glutTimerFunc(Core::screen.UpdateRate(), UpdateGL, 0);	//UpdateGL callback

	glutMainLoop();

	return 0;
}