#pragma once
#include "entity.hpp"
#include "sprite_sheet.hpp"
#include "animation.hpp"

//struct Sprite_t {
//	Sprite_t(char* _spriteSheetFilePath, int _rows, int _columns, int _spriteSize, float _frameTime) {
//		filePath = _spriteSheetFilePath;
//		rows = _rows;
//		columns = _columns;
//		spriteSize = _spriteSize;
//		frameTime = _frameTime;
//	}
//	char* filePath;
//	int rows, columns, spriteSize;
//	float frameTime;
//};
//
//struct Animation_t {
//	Animation_t() {
//		sheetRows = 1;
//		sheetColumns = 1;
//
//		currentFrame = 0;
//		currentRow = 0;
//
//		frameCounter = 0;
//		frameTime = 1.f;
//	}
//	Animation_t(int rows, int columns, int _spriteSize, float _frameTime) {
//		sheetRows = rows;
//		sheetColumns = columns;
//
//		currentFrame = 0;
//		currentRow = 0;
//		spriteSize = _spriteSize;
//
//		frameTime = _frameTime;
//		frameCounter = 0;
//	}
//
//	int currentFrame;	// Current frame in sheet.
//	int currentRow;		// Current active row in the sheet.
//	int sheetRows;		// Num rows in sheet.
//	int sheetColumns;	// Num cols in sheet.
//	int spriteSize;
//
//	float frameTime;	// Time to show each frame.
//	float frameCounter; // Accumulates time.
//};

class Player : public Entity {
public:
	Player(Vector2 position, SpriteSheet* spriteSheet) {
		SetPosition(position);
		SetVelocity({ 0.f, 0.f });

		anim = new Animation(spriteSheet, 0.25f);
	}
	~Player() {
		Destroy();
	}

	void Update();
	void Render();
	void Destroy();

private:
	Animation* anim;

	float maxSpeed = 200.0f;
	float accelerationRate = 300.0f;
	float decelerationRate = 500.0f;
};