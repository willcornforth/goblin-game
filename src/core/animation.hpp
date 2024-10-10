#pragma once
#include "sprite_sheet.hpp"
#include "entity.hpp"

enum AnimationType {
	NONE,
	IDLE,
	LEFT_MOVE,
	RIGHT_MOVE,
	UP_MOVE,
	DOWN_MOVE,
	ATTACK,
	DIE
};

class Animation {
public:
	Animation() {
		spriteSheet = new SpriteSheet();
		frameTime = 0.f;
		frameCounter = 0.f;
		currFrame = 0;
		currRow = 0;
	}
	Animation(SpriteSheet* _spriteSheet, float _frameTime = 0.25f) {
		spriteSheet = _spriteSheet;
		frameTime = _frameTime;

		frameCounter = 0;
		currFrame = 0;
		currRow = 0;
	}

	void Update(Vector2D velocity);
	Rectangle GetCurrentAnimSpriteRect();
	SpriteSheet* Animation::GetSpriteSheet() { return spriteSheet; };

	~Animation() {
		spriteSheet->~SpriteSheet();
	}

private:
	SpriteSheet* spriteSheet;

	int currFrame;
	int currRow;
	float frameTime; // Time each frame is shown.
	float frameCounter; // Accumlate time till next anim.
};