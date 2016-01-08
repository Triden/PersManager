#include "Field.h"
#include "SkeletonManager.h"

Field* Field::_instance = NULL;

Field::Field() :
	_grid(20)
{
	Assert(_instance == NULL);
	_instance = this;
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

	Bone* activeBone = _data.GetActiveBone();

	//Все кости которые у нас сейчас имеются
	for (int i = 0; i < (int)_data.GetBones().size(); ++i) {
		Bone *bone = &_data.GetBones()[i];
		if (bone == NULL) {
			continue;
		}
		if (bone == activeBone) {
			continue;
		}
		Core::render.DrawBone(*bone);
	}

	//Текущая создаваемая кость
	if (activeBone != NULL) {
		Core::render.SetColor(Color::BLUE);
		Core::render.DrawBone(*activeBone);
		Core::render.ResetColor();
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

	FPoint scaledPnt = scaleManager->GetPointScaled(pnt);
	if (instruments != NULL) {
		SkeletonState state = instruments->GetState();
		//Обрабатываем в зависимости от состояния
		if (state == NONE) {	//Обычное состояние
			//Выделяем кости
			Bone* activeBone = _data.GetActiveBone();
			bool pressed = false;
			if (activeBone != NULL) {
				pressed = Bone::BoneToPolygon(*activeBone).Contain(scaledPnt);
			}
			if (!pressed) {
				std::vector<Bone>& bones = _data.GetBones();
				for (int i = (int)bones.size() - 1; i >= 0; --i) {
					if (Bone::BoneToPolygon(bones[i]).Contain(scaledPnt)) {
						pressed = true;
						_data.SetActiveBone(&bones[i]);
						break;
					}
				}
			}
			if (!pressed) {
				_data.ResetActiveBone();
			}
		} else if (state == BONE_TO_ADD_POINT_1) {
			//Состояние добавления первой точки для кости
			_data.MakeNewBone(scaledPnt);
			_data.SetActiveBone(_data.GetNewBone());
			instruments->SetState(BONE_TO_ADD_POINT_2);
			return true;
		} else if (state == BONE_TO_ADD_POINT_2) {
			//Состояние добавления воторой точки для кости
			_data.AddBone(_data.GetActiveBone());
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
