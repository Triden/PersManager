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
		float _border;	//Внутрення граница относительно которой должны выравниваться объекты
		bool _active;	//Активна ли данная панель
	public:
		Panel(IRect rect, float border);
		virtual bool MouseDown(const IPoint& mousePos);
		virtual void MouseMove(const IPoint& mousePos);
		virtual void MouseUp(const IPoint& mousePos);
		virtual void KeyPress(unsigned char key);
		virtual void Draw();
		virtual void Update(float dt);
		IRect GetRect();
		IRect GetBorderedRect();
		void MoveTo(IPoint pnt);
		IRect GetCaptionRect();
		void ResetActive();
		void SetActive() { _active = true; }
		bool Active() { return _active; }
	};
};
#endif