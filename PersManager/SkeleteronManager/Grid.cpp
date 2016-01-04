#include "Grid.h"

Grid::Grid(int interval) :
	_interval(interval)
{
}

void Grid::Draw(IRect rect) {
	Core::render.SetColor(Color::DARK_RED);
	FPoint dPos(-int(rect.x) % _interval - _interval,
				-int(rect.y) % _interval - _interval);
	for (int i = rect.x + dPos.x; i < rect.width; i += _interval) {
		Core::render.DrawLine(IPoint(i, rect.y), IPoint(i, rect.height));
	}
	for (int i = rect.y + dPos.y; i < rect.height; i += _interval) {
		Core::render.DrawLine(IPoint(rect.x, i), IPoint(rect.width, i));
	}
	Core::render.ResetColor();
}

void Grid::Update(float dt) {

}