#include "game.hpp"

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

	// Create local player.
	Player* localPlayer = new Player({ screenSize.x / 2.f, screenSize.y / 2.f });
	entityList.push_back(localPlayer);
}

void Game::Update()
{
	for (Entity* entity : entityList) {
		if (!entity)
			continue;

		entity->Update();
	}
}

void Game::Render()
{
	BeginDrawing();

	// Clear back buffer.
	ClearBackground(BLACK);

	// All draw calls in here.
	DrawText(windowTitle, 5, 5, 30, RAYWHITE);

	for (Entity* entity : entityList) {
		if (!entity)
			continue;

		entity->Render();
	}

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
