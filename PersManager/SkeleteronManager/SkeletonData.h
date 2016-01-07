#ifndef SKELETON_DATA
#define SKELETON_DATA

#include "..\Engine\Include.h"

//Здесь хранятся все данные о скелете
class SkeletonData {
private:
	std::vector<Bone> _bones;
	Bone* _activeBone;	//Косточка с которой мы работаем
public:
	SkeletonData();
	~SkeletonData();
	void Save();
	void Load();
	void MakeBone(FPoint pnt);	//Точка в которой она начинается
	Bone* GetActiveBone() { return _activeBone; }
	void ResetActiveBone();
	void AddActiveBone();
	std::vector<Bone>& GetBones() { return _bones; }
};

#endif
