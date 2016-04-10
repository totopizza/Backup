#include "Map.h"

Map::Map()
{
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
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
	for (int i = 0; i < column; ++i) {
		for (int j = 0; j < row; ++j) {

			position.x() = (j * 105) - 100;
			position.y() = i * 105;

			if (ground[i][j] == 0){
				drawFillBox(position.x(), -position.y(), 100, 100, Color::blue);
			}
			else if (ground[i][j] == 1){
				drawFillBox(position.x(), -position.y(), 100, 100, Color::cyan);
			}

		}
	}
}