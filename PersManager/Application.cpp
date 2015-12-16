#include "Application.h"

Application::Application() {
	Core::GetScreen()->SetFixed(false);
}

Application::~Application() {

}

void Application::Draw() {
	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(100, 100, 0);
	glVertex3f(150, 100, 0);
	glEnd();
}

void Application::Update(float dt) {
}

void Application::MouseDown(const IPoint& mousePos) {
	std::cout << mousePos.x << " " << mousePos.y << '\n';
}

void Application::MouseMove(const IPoint& mousePos) {

}

void Application::MouseUp(const IPoint& mousePos) {

}

void Application::KeyPress(unsigned char key) {

}