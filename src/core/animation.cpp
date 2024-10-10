#include "animation.hpp"

void Animation::Update(Vector2D velocity)
{
	// Determine which direction takes precedence.
	if (fabs(velocity.x) > fabs(velocity.y)) {
		// Handle anim states
		if (velocity.x < 0.f) {
			currRow = 3;
		}
		else if (velocity.x > 0.f) {
			currRow = 2;
		}
	}
	else {
		if (velocity.y < 0.f) {
			currRow = 1;
		}
		else if (velocity.y > 0.f) {
			currRow = 0;
		}
	}

	// Entity standing still.
	if (velocity.x == 0.f && velocity.y == 0.f) {
		currFrame = 0;
		currRow = 0;
		frameCounter = 0; // Keep resetting to prevent anims.
	}

	if (frameCounter > frameTime) {
		frameCounter = 0;

		// Next 
		currFrame++;

		if (currFrame > spriteSheet->GetColumns()) {
			currFrame = 0;
		}
	}
	else {
		frameCounter += GetFrameTime();
	}
}

Rectangle Animation::GetCurrentAnimSpriteRect()
{
	const int spriteSize = spriteSheet->GetSpriteSize();

	Rectangle rect = Rectangle();
	rect.x = currFrame * spriteSize;
	rect.y = currRow * spriteSize;
	rect.width = rect.height = spriteSize;

	return rect;
}