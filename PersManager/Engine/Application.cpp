#include "Application.h"

namespace Core {

	Application::Application() {

	}

	void Application::OnStart() {

	};

	void Application::UpdateGL(int value) {
		int cTime = glutGet(GLUT_ELAPSED_TIME);

		static int lastTime = 0;
		int dt = cTime - lastTime;	//Реальное время, которой прошло с момента последнего апдейта
		lastTime = cTime;
		Update((dt * 1.f) / screen.OneSecond());
		Draw();
	};

	void Application::InitOpenGlContex(int argc, char **argv) {
		glutInit(&argc, argv);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
		
		InitWindow();

		InitGlView(screen.Width(), screen.Height(), screen.GLWidth(), screen.GLHeight());
		glewInit();	
	};

	void Application::InitWindow() {
		glutInitWindowPosition(ScreenSize().x / 2 - screen.Width() / 2, ScreenSize().y / 2 - screen.Height() / 2);
		glutInitWindowSize(screen.Width(), screen.Height());
		glutCreateWindow("Core");
	}

	void Application::InitWindowSize(int width, int height) {
		glutReshapeWindow(width, height);
	}

	void Application::InitGlView(int width, int height, int glWidth, int glHeight) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		
		gluOrtho2D(0.f, glWidth, 0.f, glHeight);
		glMatrixMode(GL_MODELVIEW);
	}

	void Application::KeyPressGL(unsigned char key, int x, int y) {
		KeyPress(key);
	}
	
	void Application::MouseMoveGL(int x, int y) {
		float xx = (x * 1.f) / screen.Width() * screen.GLWidth();
		float yy = screen.GLHeight() - (y * 1.f) / screen.Height() * screen.GLHeight();
		
		MouseMove(IPoint(xx, yy));
	}

	void Application::MouseWheelGL(int button, int dir, int x, int y) {
		float xx = (x * 1.f) / screen.Width() * screen.GLWidth();
		float yy = screen.GLHeight() - (y * 1.f) / screen.Height() * screen.GLHeight();
		if (dir != 0) {
			MouseWheel(dir, IPoint(xx, yy));
		}
	}

	void Application::MouseWheel(int dir, const IPoint& mousePos) {
		for (int i = 0; i < int(_widgets.size()); ++i) {
			_widgets[i]->MouseWheel(dir, mousePos);
		}
	}

	void Application::MouseGL(int button, int state, int x, int y) {
		IPoint mousePos(
			(x * 1.f) / screen.Width() * screen.GLWidth(),
			screen.GLHeight() - (y * 1.f) / screen.Height() * screen.GLHeight()
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

	void Application::Draw() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 1.0);

		for (int i = 0; i < int(_widgets.size()); ++i) {
			_widgets[i]->Draw();
		}

		glutSwapBuffers();
	};
	
	void Application::Update(float dt) {
		for (int i = 0; i < int(_widgets.size()); ++i) {
			_widgets[i]->Update(dt);
		}
	};

	void Application::OnResize(int width, int height) {
		screen.OnResize(width, height);
		OnResize();
	}

	void Application::OnResize() {
		InitWindowSize(screen.Width(), screen.Height());
		InitGlView(screen.Width(), screen.Height(), screen.GLWidth(), screen.GLHeight());
	}

	void Application::KeyPress(unsigned char key) {
		for (int i = 0; i < int(_widgets.size()); ++i) {
			_widgets[i]->KeyPress(key);
		}
	}

	void Application::MouseMove(const IPoint& mousePos) {
		for (int i = 0; i < int(_widgets.size()); ++i) {
			_widgets[i]->MouseMove(mousePos);
		}
	}

	void Application::MouseDown(const IPoint& mousePos) {
		for (int i = 0; i < int(_widgets.size()); ++i) {
			_widgets[i]->MouseDown(mousePos);
		}
	}

	void Application::MouseUp(const IPoint& mousePos) {
		for (int i = 0; i < int(_widgets.size()); ++i) {
			_widgets[i]->MouseUp(mousePos);
		}
	}

	void Application::AddWidget(Widget *widget) {
		_widgets.push_back(widget);
	}

	IPoint Application::ScreenSize() {
		return IPoint(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
	};

	void Application::SetWindowPos(IPoint pos) {
	}

	void Application::SwitchFullScreen() {
		OnResize(ScreenSize().x, ScreenSize().y);
		glutFullScreen();
	}
};