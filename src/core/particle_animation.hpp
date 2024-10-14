#pragma once
#include "animation.hpp"
#include "util/vector2d.hpp"

class ParticleAnimation : public Animation {
public:
	ParticleAnimation(
		SpriteSheet* _spriteSheet
	) : Animation(_spriteSheet) {};

	void Update(Vector2D velocity);
};