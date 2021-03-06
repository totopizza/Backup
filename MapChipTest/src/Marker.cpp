#include "Marker.h"

Marker::Marker()
{
	dir = Down_;

	position = Vec2i(0, 0);

	positionInfront = Vec2i(0, 0);

	movingValue = Vec2i(0, 0);

	movingValueInfront = Vec2i(0, 1);
}

void Marker::Update(AppEnv& env)
{
	position.x() = (movingValue.x() * (ChipData::size + ChipData::gap)) - Window::widthFit;
	position.y() = movingValue.y() * (ChipData::size + ChipData::gap) - Window::heightFit;

	positionInfront.x() = (movingValueInfront.x() * (ChipData::size + ChipData::gap)) - Window::widthFit;
	positionInfront.y() = movingValueInfront.y() * (ChipData::size + ChipData::gap) - Window::heightFit;

	if (movingValue.x() < ChipData::row - 1 && env.isPushKey(GLFW_KEY_RIGHT)) {
		movingValue.x() += 1;
		movingValueInfront = Vec2i(movingValue.x() + 1, movingValue.y());
		dir = Right_;
	}
	else if (movingValue.x() > 0 && env.isPushKey(GLFW_KEY_LEFT)) {
		movingValue.x() -= 1;
		movingValueInfront = Vec2i(movingValue.x() - 1, movingValue.y());
		dir = Left_;
	}
	else if (movingValue.y() < ChipData::column - 1 && env.isPushKey(GLFW_KEY_DOWN)) {
		movingValue.y() += 1;
		movingValueInfront = Vec2i(movingValue.x(), movingValue.y() + 1);
		dir = Down_;
	}
	else if (movingValue.y() > 0 && env.isPushKey(GLFW_KEY_UP)) {
		movingValue.y() -= 1;
		movingValueInfront = Vec2i(movingValue.x(), movingValue.y() - 1);
		dir = Up_;
	}
}

void Marker::Draw()
{
	drawFillBox(position.x(), -position.y(), ChipData::size, ChipData::size, Color::magenta);
	drawBox(positionInfront.x(), -positionInfront.y(), ChipData::size, ChipData::size, 3, Color::yellow);
}

Vec2i Marker::GetMovingValue()
{
	return movingValue;
}

Vec2i Marker::GetMovingValueInFront()
{
	return movingValueInfront;
}