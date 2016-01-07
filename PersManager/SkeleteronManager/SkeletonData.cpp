#include "SkeletonData.h"

SkeletonData::SkeletonData() :
	_activeBone(NULL)
{
	_bones.clear();
}

SkeletonData::~SkeletonData() {
}

void SkeletonData::Save() {
}

void SkeletonData::Load() {
}

void SkeletonData::MakeBone(FPoint pnt) {
	if (_activeBone != NULL) {	//Создаем еще одну кость не удалив предыдущую
		Assert(false);
	} else {
		_activeBone = new Bone();
		_activeBone->p = pnt;
	}
}

void SkeletonData::ResetActiveBone() {
	delete _activeBone;
	_activeBone = NULL;
}

void SkeletonData::AddActiveBone() {
	_bones.push_back(*_activeBone);
}
