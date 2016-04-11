#include "Map.h"

Map::Map()
{
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
			ground[i][j] = 0;
		}
	}

	ground[2][2] = 2;

	position = Vec2i(0, 0);
}

void Map::Update(AppEnv& env)
{
	if (ground[marker.GetMovingValue().x()][marker.GetMovingValue().y()] == 0 &&
		env.isPushKey(GLFW_KEY_A)){
		ground[marker.GetMovingValue().x()][marker.GetMovingValue().y()] = 1;
	}
	else if (ground[marker.GetMovingValue().x()][marker.GetMovingValue().y()] == 1 &&
		env.isPushKey(GLFW_KEY_A)){
		ground[marker.GetMovingValue().x()][marker.GetMovingValue().y()] = 0;
	}

	marker.Update(env);
}

void Map::Draw()
{
	for (int i = 0; i < column; ++i) {
		for (int j = 0; j < row; ++j) {

			position.x() = (j * 105) - 100;
			position.y() = i * 105;

			if (ground[j][i] == 0){
				drawFillBox(position.x(), -position.y(), 100, 100, Color::blue);
			}
			else if (ground[j][i] == 1){
				drawFillBox(position.x(), -position.y(), 100, 100, Color::cyan);
			}
			else if (ground[j][i] == 2){
				drawFillBox(position.x(), -position.y(), 100, 100, Color::red);
			}

		}
	}

	marker.Draw();
}