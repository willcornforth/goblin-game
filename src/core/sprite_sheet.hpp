#pragma once
#include <unordered_map>
#include "raylib.h"
#include <variant>

enum EntityAnimationActivity: unsigned char {
	NONE,
	IDLE,
	LEFT_MOVE,
	RIGHT_MOVE,
	UP_MOVE,
	DOWN_MOVE,
	ATTACK,
	DIE
};
using AnimationActivity = std::variant<EntityAnimationActivity>;

class SpriteSheet {
public:
	SpriteSheet() {
		rows = 0;
		columns = 0;
		spriteSize = 0;
		texture = Texture2D();
		animMapping = std::unordered_map<AnimationActivity, int>();
	}
	SpriteSheet(
		int _rows,
		int _columns,
		int _spriteSize,
		const char* spriteSheetFilePath, 
		std::unordered_map<AnimationActivity, int> _animMapping = std::unordered_map<AnimationActivity, int>()
	) {
		rows = _rows;
		columns = _columns;
		spriteSize = _spriteSize;
		texture = LoadTexture(spriteSheetFilePath);
		animMapping = _animMapping;
	}
	~SpriteSheet() {
		UnloadTexture(texture);
	}

	int GetRows() { return rows - 1; };
	int GetColumns() { return columns - 1; };
	int GetSpriteSize() { return spriteSize; };
	Texture2D GetTexture() { return texture; };

	int GetRowForAnimActivity(AnimationActivity act);

private:
	std::unordered_map<AnimationActivity, int> animMapping;
	Texture2D texture;

	int rows, columns;
	int spriteSize;
};