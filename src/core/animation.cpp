#include "animation.hpp"

Rectangle Animation::GetCurrentAnimSpriteRect()
{
	const int spriteSize = spriteSheet->GetSpriteSize();

	Rectangle rect = Rectangle();
	rect.x = currFrame * spriteSize;
	rect.y = currRow * spriteSize;
	rect.width = rect.height = spriteSize;

	return rect;
}

void Animation::Update(Vector2D velocity) {
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