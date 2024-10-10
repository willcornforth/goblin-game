#pragma once
#include <cfloat>
#include <math.h>

class Vector2D {
public:
	Vector2D() {
		x = -FLT_MAX;
		y = -FLT_MAX;
	}
	Vector2D(float _x, float _y) {
		x = _x;
		y = _y;
	}

	inline float Length() {
		return sqrt(x * x + y * y);
	}

	Vector2D operator/(const float val);
	Vector2D operator*(float val);
	Vector2D& operator=(Vector2D other);
	Vector2D& operator+=(Vector2D other);

	float x, y;
};