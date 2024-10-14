#pragma once
#include "animation.hpp"
#include "util/vector2d.hpp"

class ActorAnimation : public Animation {
public:
	ActorAnimation(
		SpriteSheet* _spriteSheet
	) : Animation(_spriteSheet, 0.25f) {};

	void Update(Vector2D velocity);
};