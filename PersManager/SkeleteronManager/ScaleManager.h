#ifndef SKELETON_SCALE_MANAGER
#define SKELETON_SCALE_MANAGER

#include "../Engine/Include.h"

class ScaleManager {
private:
	float _scale;
	float _speed;	//�������� � ������� ���������� �������
	FPoint _basePos;
	FPoint _prevStartPos;
	std::vector<FPoint> _points;
	bool _pressed;
	IPoint _mouseDown;
public:
	ScaleManager(float initScale, float speed);
	void MouseWheel(int dir, const IPoint& pnt);
	void Update(float dt);
	float GetScale();
	const FPoint& GetMove();
	void MouseDown(const IPoint& pnt);
	void MouseMove(const IPoint& pnt);
	void MouseUp(const IPoint& pnt);
	void Draw();
	FPoint GetPointScaled(const FPoint& point);	//���������� ����� � ����������� ����� ���������
	FPoint GetPointField(const FPoint& point);	//���������� ����� � ����������� ������
	IRect GetScaledRect();	//���������� ���������� ������ � ����������� ����
};

#endif
