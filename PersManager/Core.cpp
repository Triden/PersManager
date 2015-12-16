#include "Core.h"

Widget::Widgets Widget::_widgets;
Screen Core::_screen;

Widget::Widget(bool addToList) :
	_addToList(addToList)
{
	if (addToList) {
		_widgets.push_back(this);
	}
}

Widget::~Widget() {
	bool have = false;
	for (Widgets::iterator i = _widgets.begin(); i != _widgets.end(); ++i) {
		if ((*i) == this) {
			_widgets.erase(i);
			have = true;
			break;
		}
	}
	if (!have && _addToList) {
		//Assert
	}
}

Core::Core(int fps, int screenWidth, int screenHeight, int glWidth, int glHeight):
	Widget(false)
{
	_screen.SetFPS(fps);
	_screen.SetSize(screenWidth, screenHeight);
	_screen.SetGlSize(glWidth, glHeight);
	_widgets.clear();
}

void Core::Empty() {

}

void Core::InitGlView(int width, int height, int glWidth, int glHeight) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0.f, glWidth, 0.f, glHeight);
	glMatrixMode(GL_MODELVIEW);
}

void Core::InitOpenGlContex() {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	const IPoint screenSize(
		glutGet(GLUT_SCREEN_WIDTH),
		glutGet(GLUT_SCREEN_HEIGHT)
		);

	glutInitWindowPosition(screenSize.x / 2 - _screen.Width() / 2, screenSize.y / 2 - _screen.Height() / 2);
	glutInitWindowSize(_screen.Width(), _screen.Height());
	glutCreateWindow("Core");

	InitGlView(_screen.Width(), _screen.Height(), _screen.GLWidth(), _screen.GLHeight());
	glewInit();
}

void Core::UpdateGL(int value) {
	int cTime = glutGet(GLUT_ELAPSED_TIME);

	static int lastTime = 0;
	int dt = cTime - lastTime;	//Реальное время, которой прошло с момента последнего апдейта
	lastTime = cTime;
	Update((dt * 1.f) / _screen.OneSecond());
	Draw();
}

void Core::OnStart() {

}

void Core::OnResize(int width, int height) {
	_screen.OnResize(width, height);
}

Core::~Core() {

}

void Core::Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.3, 0.3, 1.0);

	for (int i = 0; i < int(_widgets.size()); ++i) {
		_widgets[i]->Draw();
	}

	glutSwapBuffers();
}

void Core::Update(float dt) {
	for (int i = 0; i < int(_widgets.size()); ++i) {
		_widgets[i]->Update(dt);
	}
}

void Core::MouseGL(int button, int state, int x, int y) {
	IPoint mousePos(
		(x * 1.f) / _screen.Width() * _screen.GLWidth(),
		_screen.GLHeight() - (y * 1.f) / _screen.Height() * _screen.GLHeight()
		);

	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			MouseDown(mousePos);
		}
		else if (state == GLUT_UP) {
			MouseUp(mousePos);
		}
	}
}

void Core::MouseDown(const IPoint& mousePos) {
	for (int i = 0; i < int(_widgets.size()); ++i) {
		_widgets[i]->MouseDown(mousePos);
	}
}

void Core::MouseMoveGL(int x, int y) {
	float xx = (x * 1.f) / _screen.Width() * _screen.GLWidth();
	float yy = _screen.GLHeight() - (y * 1.f) / _screen.Height() * _screen.GLHeight();

	MouseMove(IPoint(xx, yy));
}

void Core::MouseMove(const IPoint& mousePos) {
	for (int i = 0; i < int(_widgets.size()); ++i) {
		_widgets[i]->MouseMove(mousePos);
	}
}

void Core::MouseUp(const IPoint& mousePos) {
	for (int i = 0; i < int(_widgets.size()); ++i) {
		_widgets[i]->MouseUp(mousePos);
	}
}

void Core::KeyPressGL(unsigned char key, int x, int y) {
	KeyPress(key);
}

void Core::KeyPress(unsigned char key) {
	for (int i = 0; i < int(_widgets.size()); ++i) {
		_widgets[i]->KeyPress(key);
	}
}