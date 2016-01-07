#ifndef SKELETON_DATA
#define SKELETON_DATA

#include "..\Engine\Include.h"

//����� �������� ��� ������ � �������
class SkeletonData {
private:
	std::vector<Bone> _bones;
	Bone* _activeBone;	//�������� � ������� �� ��������
public:
	SkeletonData();
	~SkeletonData();
	void Save();
	void Load();
	void MakeBone(FPoint pnt);	//����� � ������� ��� ����������
	Bone* GetActiveBone() { return _activeBone; }
	void ResetActiveBone();
	void AddActiveBone();
	std::vector<Bone>& GetBones() { return _bones; }
};

#endif
