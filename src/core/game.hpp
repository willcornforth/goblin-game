#pragma once
#include <vector>
#include <string>

#include "raylib.h"
#include "resource_dir.h"
#include "./entities/entity.hpp"
#include "world.hpp"

class Game {
public:
	Game(Vector2D screenSize, char* windowTitle) {
		this->screenSize = screenSize;
		this->windowTitle = windowTitle;
		this->world = new World(screenSize.x, screenSize.y);
		Init();
	}
	~Game() {
		delete world;
	}

	void Run();
private:

	void Init();
	void Update();
	void Render();
	void Destroy();

	World* world;
	std::vector<Entity*> entityList;
	char* windowTitle;
	Vector2D screenSize;
};