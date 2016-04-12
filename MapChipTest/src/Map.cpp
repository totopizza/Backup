#include "Map.h"

Map::Map()
{
	ground = std::vector<std::vector<int>>(ChipData::row, std::vector<int>(ChipData::column));
	ground_2 = std::vector<std::vector<int>>(ChipData::row, std::vector<int>(ChipData::column));

	position = Vec2i(0, 0);
}

void Map::Update(AppEnv& env)
{
	ground_2[2][2] = 2;

	if (ground[marker.GetMovingValueInFront().x()][marker.GetMovingValueInFront().y()] == 0 &&
		env.isPushKey(GLFW_KEY_A)){
		ground[marker.GetMovingValueInFront().x()][marker.GetMovingValueInFront().y()] = 1;
	}
	else if (ground[marker.GetMovingValueInFront().x()][marker.GetMovingValueInFront().y()] == 1 &&
		env.isPushKey(GLFW_KEY_A)){
		ground[marker.GetMovingValueInFront().x()][marker.GetMovingValueInFront().y()] = 0;
	}

	marker.Update(env);
}

void Map::Draw()
{
	for (int i = 0; i < ChipData::column; ++i) {
		for (int j = 0; j < ChipData::row; ++j) {

			position.x() = j * (ChipData::size + ChipData::gap) - Window::widthFit;
			position.y() = i * (ChipData::size + ChipData::gap) - Window::heightFit;

			if (ground[j][i] == 0) {
				drawFillBox(position.x(), -position.y(), ChipData::size, ChipData::size, Color::blue);
			}
			else if (ground[j][i] == 1) {
				drawFillBox(position.x(), -position.y(), ChipData::size, ChipData::size, Color::cyan);
			}

			if (ground_2[j][i] == 2) {
				drawFillBox(position.x(), -position.y(), ChipData::size, ChipData::size, Color::red);
			}

		}
	}

	marker.Draw();
}