#include "actor_animation.hpp"

void ActorAnimation::Update(Vector2D velocity)
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

	Animation::Update();
}
