#pragma once
#include "raylib.h"

class SpriteSheet {
public:
	SpriteSheet() {
		rows = 0;
		columns = 0;
		spriteSize = 0;
		texture = Texture2D();
	}
	SpriteSheet(int _rows, int _columns, int _spriteSize, const char* spriteSheetFilePath) {
		rows = _rows;
		columns = _columns;
		spriteSize = _spriteSize;
		texture = LoadTexture(spriteSheetFilePath);
	}
	~SpriteSheet() {
		UnloadTexture(texture);
	}

	int GetRows() { return rows; };
	int GetColumns() { return columns; };
	int GetSpriteSize() { return spriteSize; };
	Texture2D GetTexture() { return texture; };
private:
	Texture2D texture;
	int rows, columns;
	int spriteSize;
};