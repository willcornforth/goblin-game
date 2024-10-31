#pragma once
#include "./world/grid.hpp"

class World {
public:
	World(int screenWidth, int screenHeight) : grid(new Grid(screenWidth, screenHeight)) {};

private:
	Grid* grid;
};