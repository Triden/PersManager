#ifndef GAMEFIELD
#define GAMEFIELD


#include "Engine/Core.h"
#include "Engine/Math.h"
#include "Engine/Widget.h"

class GameMain : public Core::Widget {
private:
	Core::Button _button;
public:
	GameMain();
	virtual ~GameMain();
	virtual void Draw();
	virtual void Update(float dt);
	virtual void MouseDown(const IPoint& mousePos);
	virtual void MouseMove(const IPoint& mousePos);
	virtual void MouseUp(const IPoint& mousePos);
	virtual void KeyPress(unsigned char key);

	void SetWindowParams();
	void Save();
	void Load();
};

#endif