#include "Field.h"
#include "SkeletonManager.h"

Field::Field() :
	_grid(20)
{
}

Field::~Field() {
}

void Field::Draw() {
	//Получим все данные из scale manager'а
	FPoint move(0.f, 0.f);
	float scale(1.f);
	IRect scaledRect;
	SkeletonManager * manager = SkeletonManager::Instance();
	ScaleManager* scaleManager = NULL;
	if (manager != NULL) {
		scaleManager = manager->GetScaleManager();
		if (scaleManager != NULL) {
			move = scaleManager->GetMove();
			scale = scaleManager->GetScale();
			scaledRect = scaleManager->GetScaledRect();
		}
	}
	//Сетка
	Core::render.PushMatrix();
	Core::render.MatrixMove(move);
	Core::render.MatrixScale(scale);
	_grid.Draw(scaledRect);

	//Текущая создаваемая кость
	Core::render.DrawBone(_data.GetActiveBone());
	Bone test;
	test.p = FPoint(100.f, 100.f);
	test.l = 30.f;
	static float angle = 0.f;
	test.a = angle;
	angle += 0.05f;
	Core::render.DrawBone(&test);

	Bone test2 = Bone::PointsToBone(FPoint(100.f, 100.f), FPoint(120.f, 120.f));
	Core::render.DrawBone(&test2);

	for (int i = 0; i < _data.GetBones().size(); ++i) {
		Core::render.DrawBone(&_data.GetBones()[i]);
	}
	
	Core::render.PopMatrix();
}

void Field::Update(float dt) {
	//Просчитаем нашу кость, если есть активная и мы в нужном состоянии
	SkeletonInstruments* instruments = SkeletonInstruments::Instance();
	SkeletonState state = NONE;
	if (instruments != NULL) {
		state = instruments->GetState();
	}
	if (state == BONE_TO_ADD_POINT_2) {
		Bone* bone = _data.GetActiveBone();
		if (bone != NULL) {
			SkeletonManager * manager = SkeletonManager::Instance();
			ScaleManager* scaleManager = NULL;
			if (manager != NULL) {
				scaleManager = manager->GetScaleManager();
				if (scaleManager == NULL) {
					return;
				}
			}
			FPoint mousePos = scaleManager->GetPointScaled(Core::screen.GetMousePos());
			//scaleManager->GetPointScaled(mousePos);

			//Теперь переводим нашу точку в bone
			Bone boneMouse = Bone::PointsToBone(bone->p, mousePos);
			bone->l = boneMouse.l;
			bone->a = boneMouse.a;
		} else {
			Assert(false);
		}
	}
}

bool Field::MouseDown(const IPoint& pnt) {
	SkeletonInstruments* instruments = SkeletonInstruments::Instance();
	SkeletonManager * manager = SkeletonManager::Instance();
	ScaleManager* scaleManager = NULL;
	if (manager != NULL) {
		scaleManager = manager->GetScaleManager();
	}
	if (scaleManager == NULL) {	//Как это у нас нет его?
		Assert(false);
		return false;
	}
	if (instruments != NULL) {
		SkeletonState state = instruments->GetState();
		//Обрабатываем в зависимости от состояния
		if (state == BONE_TO_ADD_POINT_1) {
			
			_data.MakeBone(scaleManager->GetPointScaled(pnt));
			instruments->SetState(BONE_TO_ADD_POINT_2);
			return true;
		} else if (state == BONE_TO_ADD_POINT_2) {
			_data.AddActiveBone();
			_data.ResetActiveBone();
			instruments->SetState(NONE);
			return true;
		}
	}
	return false;
}

void Field::MouseMove(const IPoint& pnt) {

}

void Field::MouseUp(const IPoint& pnt) {

}
