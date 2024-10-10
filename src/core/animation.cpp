#include "animation.hpp"

void Animation::Update(Vector2D velocity)
{
	// Determine which direction takes precedence.
	if (fabs(velocity.x) > fabs(velocity.y)) {
		// Handle anim states
		if (velocity.x < 0.f) {
			currRow = spriteSheet->GetRowForAnimActivity(LEFT_MOVE);
		}
		else if (velocity.x > 0.f) {
			currRow = spriteSheet->GetRowForAnimActivity(RIGHT_MOVE);
		}
	}
	else {
		if (velocity.y < 0.f) {
			currRow = spriteSheet->GetRowForAnimActivity(UP_MOVE);
		}
		else if (velocity.y > 0.f) {
			currRow = spriteSheet->GetRowForAnimActivity(DOWN_MOVE);
		}
	}

	// Entity standing still.
	if (velocity.x == 0.f && velocity.y == 0.f) {
		currFrame = 0;
		currRow = spriteSheet->GetRowForAnimActivity(IDLE);
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