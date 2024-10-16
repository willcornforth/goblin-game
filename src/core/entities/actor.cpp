#include "actor.hpp"

void Actor::Update()
{
	const float frameTime = GetFrameTime();

	if (acceleration.x != 0.0f || acceleration.y != 0.0f) {
		// Normalise acceleration vector.
		const float len = acceleration.Length();
		acceleration.x /= len; acceleration.y /= len;

		// Apply acceleration.
		velocity.x += acceleration.x * accelerationRate * frameTime;
		velocity.y += acceleration.y * accelerationRate * frameTime;
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

	// Clear this frame's acceleration.
	acceleration = { 0.f, 0.f };

	anim->Update(velocity);
}

void Actor::Render()
{
	DrawTextureRec(
		anim->GetSpriteSheet()->GetTexture(),
		anim->GetCurrentAnimSpriteRect(),
		{ position.x, position.y },
		WHITE
	);
}
