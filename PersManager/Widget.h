#ifndef ENGINE_WIDGET
#define ENFINE_WIDGET

#pragma once
#include "Math.h"

namespace Core {
	class Widget {
	public:
		Widget();
		virtual ~Widget();
		virtual void Draw() = 0;
		virtual void Update(float dt) = 0;
		virtual void MouseDown(const IPoint& mousePos) = 0;
		virtual void MouseMove(const IPoint& mousePos) = 0;
		virtual void MouseUp(const IPoint& mousePos) = 0;
		virtual void KeyPress(unsigned char key) = 0;
	};
}
#endif