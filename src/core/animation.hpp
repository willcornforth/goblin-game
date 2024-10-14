#pragma once
#include "util/vector2d.hpp"
#include "sprite_sheet.hpp"

class Animation {
public:
	Animation() {
		spriteSheet = new SpriteSheet();
		frameTime = 0.f;
		frameCounter = 0.f;
		currFrame = 0;
		currRow = 0;
	}
	Animation(
		SpriteSheet* _spriteSheet,
		float _frameTime = GetFrameTime()
	) {
		spriteSheet = _spriteSheet;

		frameTime = _frameTime;
		frameCounter = 0;
		currFrame = 0;
		currRow = 0;
	}

	virtual void Update(Vector2D velocity) = 0;

	Rectangle GetCurrentAnimSpriteRect();
	SpriteSheet* Animation::GetSpriteSheet() { return spriteSheet; };

	~Animation() {
		spriteSheet->~SpriteSheet();
	}
protected:
	SpriteSheet* spriteSheet;

	int currFrame;
	int currRow;
	float frameTime; // Time each frame is shown.
	float frameCounter; // Accumlate time till next anim.
};