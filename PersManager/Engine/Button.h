#ifndef ENGINE_BUTTON
#define ENGINE_BUTTON

#include "Math.h"

namespace Core {
	class Button {
	private:
		bool _pressed;
		bool _mouseDown;
		bool _mouseMove;
		IRect _rect;
	public:
		Button();
		virtual ~Button();
		virtual void Draw();
		virtual void Update(float dt);
		virtual void MouseDown(const IPoint& mousePos);
		virtual void MouseMove(const IPoint& mousePos);
		virtual void MouseUp(const IPoint& mousePos);
		virtual void Create(const IRect& rect);
	};
};
#endif