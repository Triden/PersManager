//#pragma once
//
//class DebugInfo {
//private:
//	float _lastSecondTime = 0.f;
//	int _currentFps = 0;
//	int _drawedFrames = 0;
//public:
//	DebugInfo() : _currentFps(0), _lastSecondTime(0.f) {}
//	void Draw() {
//		++_drawedFrames;
//	}
//
//	void Update(float dt) {
//		PrintInfo(dt);
//	}
//
//	void PrintInfo(float dt) {
//
//
////		float cTime = glutGet(GLUT_ELAPSED_TIME);
//		//float elapsedTime = cTime / ONE_SECOND - _lastSecondTime;
////
//		//if (elapsedTime > 1.f) {
////			system("CLS");
//			//std::cout << "wait fps = " << WAIT_FPS << '\n';
//			//std::cout << "fps by update = " << 1.f / dt << '\n';
//
//			//float currentFps = _drawedFrames / elapsedTime;
//			//_lastSecondTime = cTime / ONE_SECOND;
//			//_drawedFrames = 0;
//
//			//std::cout << "fps by draw = " << currentFps << '\n';
//		//}
//	}
//};