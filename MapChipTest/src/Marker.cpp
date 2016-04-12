#include "Marker.h"

Marker::Marker()
{
	position = Vec2i(0, 0);

	movingValue = Vec2i(0, 0);
}

void Marker::Update(AppEnv& env)
{
	position.x() = (movingValue.x() * 105) - Window::widthFit;
	position.y() = movingValue.y() * 105 - Window::heightFit;

	if (movingValue.x() < 4 && env.isPushKey(GLFW_KEY_RIGHT)) {
		movingValue.x() += 1;
	}
	else if (movingValue.x() > 0 && env.isPushKey(GLFW_KEY_LEFT)) {
		movingValue.x() -= 1;
	}
	else if (movingValue.y() < 4 && env.isPushKey(GLFW_KEY_DOWN)) {
		movingValue.y() += 1;
	}
	else if (movingValue.y() > 0 && env.isPushKey(GLFW_KEY_UP)) {
		movingValue.y() -= 1;
	}
}

void Marker::Draw()
{
	drawBox(position.x(), -position.y(), 100, 100, 3, Color::red);
}

Vec2i Marker::GetMovingValue()
{
	return movingValue;
}