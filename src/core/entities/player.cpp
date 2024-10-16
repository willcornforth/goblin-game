#include "player.hpp"
#include <math.h>

void Player::Update()
{
	if (IsKeyDown(KEY_UP)) {
		acceleration.y -= 1.f;
	}

	if (IsKeyDown(KEY_DOWN)) {
		acceleration.y += 1.f;
	}

	if (IsKeyDown(KEY_LEFT)) {
		acceleration.x -= 1.f;
	}

	if (IsKeyDown(KEY_RIGHT)) {
		acceleration.x += 1.f;
	}

	Actor::Update();
}
