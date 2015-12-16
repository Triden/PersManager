//#include "debuginfo.h"
//
//void debuginfo::draw() {
//	++_drawedframes;
//}
//
//void debuginfo::update(float dt) {
//	printinfo(dt);
//}
//
//void debuginfo::printinfo(float dt) {
//	float ctime = glutget(glut_elapsed_time);
//	float elapsedtime = ctime / one_second - _lastsecondtime;
//
//	if (elapsedtime > 1.f) {
//		system("cls");
//		std::cout << "wait fps = " << wait_fps << '\n';
//		std::cout << "fps by update = " << 1.f / dt << '\n';
//
//		float currentfps = _drawedframes / elapsedtime;
//		_lastsecondtime = ctime / one_second;
//		_drawedframes = 0;
//
//		std::cout << "fps by draw = " << currentfps << '\n';
//	}
//}