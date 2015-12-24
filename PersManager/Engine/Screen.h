#ifndef ENGINE_SCREEN
#define ENGINE_SCREEN

#include "Math.h"

namespace Core {
	class Screen {
	private:
		int _width;
		int _height;
		float _glWidth;
		float _glHeight;
		int _fps;
		bool _fixed;
		float _ONE_SECOND;
	public:
		Screen();
		Screen(int fps, int screenWidth, int screenHeight, int glWidth, int glHeight);
		void SetSize(int width, int height);
		void SetGlSize(float glWidth, float glHeight);
		void SetFPS(int fps);
		void SetFixed(bool fixed);
		int Width();
		int Height();
		float GLWidth();
		float GLHeight();
		int FPS();
		bool Fixed();
		float OneSecond();
		void SetOneSecond(float oneSecond);
		int UpdateRate();
		void OnResize(int width, int height);	//Изменение размера окна
	};
	extern Screen screen;
};
#endif