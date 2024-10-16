#pragma once
#include "util/vector2d.hpp"
#include "../sprite_sheet.hpp"

// Basic looping animation class.
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

	// Velocity passed as 0,0 as currently we don't use this in the base class...
	// May be a better way to do this?
	virtual void Update(Vector2D velocity = { 0.f, 0.f });

	Rectangle GetCurrentAnimSpriteRect();
	SpriteSheet* Animation::GetSpriteSheet() { return spriteSheet; };

	~Animation() {
		delete spriteSheet;
	}
protected:
	SpriteSheet* spriteSheet;

	int currFrame;
	int currRow;
	float frameTime; // Time each frame is shown.
	float frameCounter; // Accumlate time till next anim.
};