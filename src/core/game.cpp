#include "game.hpp"

#include "./entities/player.hpp"
#include "./entities/particle.hpp"
#include "./entities/goblin.hpp"

void Game::Run()
{
	// Main game loop.
	while (!WindowShouldClose())
	{
		Update();
		Render();
	}
	Destroy();
}

void Game::Init()
{
	// Tell the window to use vysnc and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(screenSize.x, screenSize.y, windowTitle);

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	Particle* fireBall = new Particle(500.f, { screenSize.x / 2.f, screenSize.y / 2.f }, 0.1f);
	entityList.push_back(fireBall);

	Player* localPlayer = new Player({ screenSize.x / 2.f, screenSize.y / 2.f });
	entityList.push_back(localPlayer);

	Goblin* testGoblin = new Goblin({ 0.f, 0.f }, localPlayer);
	entityList.push_back(testGoblin);

}

void Game::Update()
{
	for (auto it = entityList.begin(); it != entityList.end(); ) {
		Entity* entity = *it;

		if (!entity || entity->IsDestroyed()) {
			it = entityList.erase(it);
			continue;
		}

		entity->Update();
		++it;
	}
}

void Game::Render()
{
	BeginDrawing();

	// Clear back buffer.
	ClearBackground({20, 20, 55, 255});

	// All draw calls in here.
	for (Entity* entity : entityList) {
		if (!entity)
			continue;

		entity->Render();
	}
	DrawText(windowTitle, 5, 5, 20, LIGHTGRAY);

	EndDrawing();
}

void Game::Destroy()
{
	// Destroy/dealloc assets here.
	for (Entity* entity : entityList) {
		if (!entity)
			continue;

		entity->Destroy();
	}

	CloseWindow();
}
