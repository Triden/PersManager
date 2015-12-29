#ifndef ENGINE_BUTTON
#define ENGINE_BUTTON

#include "Math.h"
#include "PolyObject.h"

namespace Core {
	class Button {
	public:
		bool _mouseDown;
		bool _mouseMove;
		IRect _rect;
		PolyObject* _icon;
		virtual void DrawIcon();
	public:
		Button();
		virtual ~Button();
		virtual void Draw();
		virtual void Update(float dt);
		virtual bool MouseDown(const IPoint& mousePos);
		virtual void MouseMove(const IPoint& mousePos);
		virtual void MouseUp(const IPoint& mousePos);
		virtual void Create(const IRect& rect);
		virtual void MoveTo(const IPoint& pos);
		virtual void SetIcon(PolyObject* icon);
	};

	//Кнопка флажок
	class ActiveButton : public Button {
	private:
		bool _check;
	public:
		ActiveButton();
		virtual ~ActiveButton();
		virtual void Draw();
		virtual bool MouseDown(const IPoint& mousePos);
		virtual void MouseMove(const IPoint& mousePos);
		virtual void MouseUp(const IPoint& mousePos);
		bool Checked() { return _check; }
		void SetChecked(bool check) { _check = check; }
	};
};
#endif