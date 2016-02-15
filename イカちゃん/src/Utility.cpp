#include "Utility.h"

float EasingElasticOut(float t, float b, float e)
{
	if (t == 0) return b;
	if (t == 1) return e;

	float p = 0.3;
	float a = e - b;
	float s = p / 4;
	return (a * std::pow(2, -10 * t) * std::sin((t - s) * (2 * M_PI) / p) + a + b);
}

float EasingExpoOut(float t, float b, float e)
{
	return (t == 1) ? e : (e - b) * (-std::pow(2, -10 * t) + 1) + b;
}

bool MouseToRect(Vec2f mousePos, Vec2f rectPos, Vec2f rectSize)
{
	if (mousePos.x() > rectPos.x() &&
		mousePos.x() < rectPos.x() + rectSize.x() &&
		mousePos.y() > rectPos.y() &&
		mousePos.y() < rectPos.y() + rectSize.y()){
		return true;
	}

	return false;
}