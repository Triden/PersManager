#include "Field.h"
#include "SkeletonManager.h"

Field* Field::_instance = NULL;

const float CircleInstrument::DEFAULT_RADIUS = 5.f;

Field::Field() :
	_grid(20),
	_mouseDown(false),
	_mousePos(0.f, 0.f),
	_rotateCI(),
	_scaleCI(),
	_circleInstrumentsVisible(false)
{
	Assert(_instance == NULL);
	_instance = this;
}

Field::~Field() {
}

bool Field::CircleInstrumentsVisible() {
	return _circleInstrumentsVisible;
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

	if (CircleInstrumentsVisible()) {
		_rotateCI.Draw();
		_scaleCI.Draw();
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
	if (state == NONE) {
		UpdateCInstrumentsPos();
	} else if (state == BONE_TO_ADD_POINT_2) {
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

			//Теперь переводим нашу точку в bone
			Bone boneMouse = Bone::PointsToBone(bone->p, mousePos);
			bone->l = boneMouse.l;
			bone->a = boneMouse.a;
		} else {
			Assert(false);
		}
	}
}

void Field::UpdateCInstrumentsPos() {
	Bone* bone = _data.GetActiveBone();
	if (bone != NULL) {
		const float ADD_W = 2.f;
		FPoint rCenter = bone->p;
		FPoint sCenter = bone->p;

		rCenter += FPoint((bone->l + ADD_W) * cosf(bone->a),
						  (bone->l + ADD_W) * sinf(bone->a));
		sCenter += FPoint((bone->l + _rotateCI.GetRadius() * 2.f + ADD_W * 2.f) * cosf(bone->a),
						  (bone->l + _rotateCI.GetRadius() * 2.f + ADD_W * 2.f) * sinf(bone->a));

		_rotateCI.SetCenter(rCenter);
		_scaleCI.SetCenter(sCenter);
	}
}

bool Field::MouseDown(const IPoint& pnt) {
	_mouseDown = false;

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

	_mouseDown = true;
	_mousePos = scaleManager->GetPointScaled(pnt);

	if (instruments != NULL) {
		SkeletonState state = instruments->GetState();
		//Обрабатываем в зависимости от состояния
		if (state == NONE) {	//Обычное состояние
			//Выделяем кости
			Bone* activeBone = _data.GetActiveBone();
			bool pressed = false;

			if (!pressed) {
				//Проверяем попали ли мы по круглым шняжкам
				if (CircleInstrumentsVisible()) {
					if (_rotateCI.MouseDown(_mousePos) ||
						_scaleCI.MouseDown(_mousePos))
					{
						pressed = true;
					}
				}
			}
			
			if (!pressed && activeBone != NULL) {
				pressed = Bone::BoneToPolygon(*activeBone).Contain(_mousePos);
			}
			
			if (!pressed) {
				std::vector<Bone>& bones = _data.GetBones();
				for (int i = (int)bones.size() - 1; i >= 0; --i) {
					if (Bone::BoneToPolygon(bones[i]).Contain(_mousePos)) {		//Какую-то из костей выбрали, проинициализируем инструменты
						Bone* bone = &bones[i];
						pressed = true;
						_data.SetActiveBone(bone);
						_circleInstrumentsVisible = true;
						UpdateCInstrumentsPos();
						break;
					}
				}
			}
			
			if (pressed) {
				return true;
			} else {
				_circleInstrumentsVisible = false;
				_data.ResetActiveBone();
			}
		} else if (state == BONE_TO_ADD_POINT_1) {
			//Состояние добавления первой точки для кости
			_data.MakeNewBone(_mousePos);
			_data.SetActiveBone(_data.GetNewBone());
			instruments->SetState(BONE_TO_ADD_POINT_2);

			//Сбрасываем все остальные состояния 
			_circleInstrumentsVisible = false;
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
	SkeletonInstruments* instruments = SkeletonInstruments::Instance();
	SkeletonManager * manager = SkeletonManager::Instance();
	ScaleManager* scaleManager = NULL;
	if (manager != NULL) {
		scaleManager = manager->GetScaleManager();
	}
	if (scaleManager == NULL) {	//Как это у нас нет его?
		Assert(false);
		return;
	}

	FPoint mouseMovePos = scaleManager->GetPointScaled(pnt);

	_rotateCI.MouseMove(mouseMovePos);
	_scaleCI.MouseMove(mouseMovePos);

	if (_rotateCI.Pressed()) {	//Крутим кость
		Bone * bone = _data.GetActiveBone();
		if (bone != NULL) {
			Bone boneV = Bone::PointsToBone(bone->p, mouseMovePos);
			bone->a = boneV.a;
		}
	} else if (_scaleCI.Pressed())  {	//Масштабируем кость
		Bone * bone = _data.GetActiveBone();
		if (bone != NULL) {
			Bone boneV = Bone::PointsToBone(bone->p, mouseMovePos);
			bone->l = boneV.l - _rotateCI.GetRadius() * 2.f;	//как будто всегда попадаем в центр
		}
	} else {	//Никакой инструмент не выбран
		if (instruments != NULL && _mouseDown) {
			SkeletonState state = instruments->GetState();
			Bone* bone = _data.GetActiveBone();
			if (state == NONE && bone != NULL) {	//Двигаем косточку
				bone->p += (-_mousePos + mouseMovePos);
				_mousePos = mouseMovePos;
			}
		}
	}
}

void Field::MouseUp(const IPoint& pnt) {
	_rotateCI.MouseUp(_mousePos);
	_scaleCI.MouseUp(_mousePos);
	_mouseDown = false;
}
