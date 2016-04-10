#include "Map.h"

Map::Map()
{
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			ground[i][j] = 0;
		}
	}

	position = Vec2i(0, 0);
}

void Map::Update()
{

}

void Map::Draw()
{
	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 5; ++x) {

			position.x() = (x * 105) - 100;
			position.y() = y * 105;

			if (ground[x][y] == 0){
				drawFillBox(position.x(), -position.y(), 100, 100, Color::blue);
			}
			else if (ground[x][y] == 1){
				drawFillBox(position.x(), -position.y(), 100, 100, Color::cyan);
			}

		}
	}
}