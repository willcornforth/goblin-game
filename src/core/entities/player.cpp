#include "player.hpp"
#include <math.h>

void Player::Update()
{
	Vector2D accel = { 0.f, 0.f };

	if (IsKeyDown(KEY_UP)) {
		accel.y -= 1.f;
	}

	if (IsKeyDown(KEY_DOWN)) {
		accel.y += 1.f;
	}

	if (IsKeyDown(KEY_LEFT)) {
		accel.x -= 1.f;
	}

	if (IsKeyDown(KEY_RIGHT)) {
		accel.x += 1.f;
	}

	const float frameTime = GetFrameTime();
	if (accel.x != 0.0f || accel.y != 0.0f) {
		// Normalise acceleration vector.
		const float len = accel.Length();
		accel.x /= len; accel.y /= len;

		// Apply acceleration.
		velocity.x += accel.x * accelerationRate * frameTime;
		velocity.y += accel.y * accelerationRate * frameTime;
	}
	else {
		// When player is NOT moving, linearly decay velocity to 0...

		if (velocity.x > 0) {
			velocity.x -= decelerationRate * frameTime;
			if (velocity.x < 0) velocity.x = 0;
		}
		else if (velocity.x < 0) {
			velocity.x += decelerationRate * frameTime;
			if (velocity.x > 0) velocity.x = 0;
		}

		if (velocity.y > 0) {
			velocity.y -= decelerationRate * frameTime;
			if (velocity.y < 0) velocity.y = 0;
		}
		else if (velocity.y < 0) {
			velocity.y += decelerationRate * frameTime;
			if (velocity.y > 0) velocity.y = 0;
		}
	}

	if (velocity.Length() > maxSpeed) {
		const float len = velocity.Length();
		velocity = (velocity / len) * maxSpeed;
	}

	position += (velocity * frameTime);

	anim->Update(velocity);
}

void Player::Render()
{
	DrawTextureRec(
		anim->GetSpriteSheet()->GetTexture(),
		anim->GetCurrentAnimSpriteRect(),
		{position.x, position.y},
		WHITE
	);
}
