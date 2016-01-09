#include "SkeletonData.h"

SkeletonData::SkeletonData() :
	_activeBone(NULL),
	_newBone()
{
	_bones.clear();
}

SkeletonData::~SkeletonData() {
}

void SkeletonData::Save() {
}

void SkeletonData::Load() {
}

void SkeletonData::SetActiveBone(Bone* bone) {
	_activeBone = bone;
}

void SkeletonData::ResetActiveBone() {
	_activeBone = NULL;
}

void SkeletonData::AddBone(Bone* bone) {
	_bones.push_back(*bone);
}

void SkeletonData::MakeNewBone(FPoint pnt) {
	_newBone = Bone::PointsToBone(pnt, pnt);
}

Bone* SkeletonData::GetNewBone() {
	return &_newBone;
}

void SkeletonData::RemoveBone(Bone* bone) {
	if (bone == NULL) {
		Assert(false);
		return;
	}
	for (int i = 0; i < (int)_bones.size(); ++i) {
		if (_bones[i] == *bone) {	//С учетом, что у нас одна такая кость
			_bones.erase(_bones.begin() + i);
			return;
		}
	}
}
