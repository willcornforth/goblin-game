#pragma once
#include <vector>
#include "cell.hpp"
#include <iostream>

class Grid {
public:
	Grid(int screenWidth, int screenHeight) {
		// Cells are a rect so sides are equal.
		gridLength = sqrt(MAX_CELLS);
		cellSize = { (float)(screenWidth / gridLength), (float)(screenHeight / gridLength) };

		// Create a row for each 
		for (int i = 0; i < gridLength; i++) {
			std::vector<Cell*> row;
			for (int j = 0; j < gridLength; j++) {
				row.push_back(new Cell());
			}
			rows.push_back(row);
		}

		std::cout << "Grid Length X/Y: " << gridLength << "\n";
	};
	~Grid() {
		for(std::vector<Cell*>&row : rows) {
			row.clear();
		}
		rows.clear();
	}

	// This function needs to update all entities positions within the grid.
	void Update();

private:
	static constexpr int MAX_CELLS = 25;

	Vector2D cellSize = { 0.f, 0.f };
	int gridLength = 0;

	std::vector<std::vector<Cell*>> rows;
};