#include "particle_animation.hpp"

void ParticleAnimation::Update(Vector2D velocity) {
	if (frameCounter > frameTime) {
		frameCounter = 0;

		// Next 
		currFrame++;

		if (currFrame > spriteSheet->GetColumns()) {
			currFrame = 0;
			currRow++;
		}

		if (currRow > spriteSheet->GetRows()) {
			currRow = 0;
		}
	}
	else {
		frameCounter += GetFrameTime();
	}
}