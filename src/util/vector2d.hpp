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
		return sqrtf(x * x + y * y);
	}

	inline Vector2D Normalise() {
		const float magnitude = Length();

		if (magnitude == 0.f) {
			return { 0.f, 0.f };
		}
		return { x / magnitude, y / magnitude };
	}

	Vector2D operator/(const float val);
	Vector2D operator*(float val);

	Vector2D operator-(Vector2D& other);
	Vector2D& operator=(Vector2D other);
	Vector2D& operator+=(Vector2D other);

	float x, y;
};