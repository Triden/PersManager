#ifndef SKELETON_DATA
#define SKELETON_DATA

#include "..\Engine\Include.h"

//Здесь хранятся все данные о скелете
class SkeletonData {
private:
	std::vector<Bone> _bones;
	Bone* _activeBone;	//Косточка с которой мы работаем
	Bone _newBone;
public:
	SkeletonData();
	~SkeletonData();
	void Save();
	void Load();
	void SetActiveBone(Bone* bone);	
	Bone* GetActiveBone() { return _activeBone; }
	void ResetActiveBone();
	void AddBone(Bone* bone);
	std::vector<Bone>& GetBones() { return _bones; }
	void RemoveBone(Bone* bone);
	void MakeNewBone(FPoint pnt);	//Создаем новую кость
	Bone* GetNewBone();
};

#endif
