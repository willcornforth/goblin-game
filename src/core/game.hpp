#pragma once
#include <vector>

#include "raylib.h"
#include "resource_dir.h"

#include "player.hpp"
#include <string>

class Game {
public:
	Game(Vector2D screenSize, char* windowTitle) {
		this->screenSize = screenSize;
		this->windowTitle = windowTitle;

		Init();
	}

	void Run();
private:

	void Init();
	void Update();
	void Render();
	void Destroy();

	std::vector<Entity*> entityList;
	char* windowTitle;
	Vector2D screenSize;
};