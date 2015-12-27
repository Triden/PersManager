#ifndef ENGINE_PANEL
#define ENGINE_PANEL

#include "Math.h"

namespace Core {
	class Panel {
	private:
		static const float CAPTION_H;
		bool _mouseDown;
		IPoint _prevPos;
		IPoint _mousePress;
		IRect _rect;
		float _border;
	public:
		Panel(IRect rect, float border);
		virtual void MouseDown(const IPoint& mousePos);
		virtual void MouseMove(const IPoint& mousePos);
		virtual void MouseUp(const IPoint& mousePos);
		virtual void KeyPress(unsigned char key);
		virtual void Draw();
		virtual void Update(float dt);
		IRect GetRect();
		IRect GetBorderedRect();
		void MoveTo(IPoint pnt);
		IRect GetCaptionRect();
	};
};
#endif