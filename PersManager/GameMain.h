#ifndef GAMEFIELD
#define GAMEFIELD

#include "Engine\Include.h"
#include "SkeleteronManager\SkeletonManager.h"

class GameMain : public Core::Widget {
private:
	SkeletonManager _skeletonManager;
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