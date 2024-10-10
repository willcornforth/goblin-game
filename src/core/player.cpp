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

	if (accel.x != 0.0f || accel.y != 0.0f) {
		// Normalise acceleration vector.
		const float len = accel.Length();
		accel.x /= len; accel.y /= len;

		// Apply acceleration.
		const float frameTime = GetFrameTime();
		velocity.x += accel.x * accelerationRate * frameTime;
		velocity.y += accel.y * accelerationRate * frameTime;
	}
	else {
		// When player is NOT moving, linearly decay velocity to 0...

		if (velocity.x > 0) {
			velocity.x -= decelerationRate * GetFrameTime();
			if (velocity.x < 0) velocity.x = 0;
		}
		else if (velocity.x < 0) {
			velocity.x += decelerationRate * GetFrameTime();
			if (velocity.x > 0) velocity.x = 0;
		}

		if (velocity.y > 0) {
			velocity.y -= decelerationRate * GetFrameTime();
			if (velocity.y < 0) velocity.y = 0;
		}
		else if (velocity.y < 0) {
			velocity.y += decelerationRate * GetFrameTime();
			if (velocity.y > 0) velocity.y = 0;
		}
	}

	if (velocity.Length() > maxSpeed) {
		const float len = velocity.Length();
		velocity = (velocity / len) * maxSpeed;
	}

	position += (velocity * GetFrameTime());


	// Determine which direction takes precedence.
	if (fabs(velocity.x) > fabs(velocity.y)) {
		// Handle anim states
		if (velocity.x < 0.f) {
			animation.currentRow = 3;
		}
		else if (velocity.x > 0.f) {
			animation.currentRow = 2;
		}
	}
	else {
		if (velocity.y < 0.f) {
			animation.currentRow = 1;
		}
		else if (velocity.y > 0.f) {
			animation.currentRow = 0;
		}
	}

	// Entity standing still.
	if(velocity.x == 0.f && velocity.y == 0.f) {
		animation.currentFrame = 0;
		animation.currentRow = 0;
		animation.frameCounter = 0; // Keep resetting to prevent anims.
	}

	// Animations, this NEEDS encapsulating into it's own module...
	if (animation.frameCounter > animation.frameTime) {
		animation.frameCounter = 0;

		// Next animation.
		animation.currentFrame++;

		if (animation.currentFrame > animation.sheetColumns) {
			animation.currentFrame = 0;
		}
	}
	else {
		animation.frameCounter += GetFrameTime();
	}
}

void Player::Render()
{
	Rectangle currentSpriteRect = {
		animation.currentFrame * animation.spriteSize,
		animation.currentRow * animation.spriteSize,
		animation.spriteSize,
		animation.spriteSize
	};
	DrawTextureRec(spriteSheet, currentSpriteRect, { position.x, position.y }, WHITE);

}

void Player::Destroy()
{
	UnloadTexture(spriteSheet);
}
