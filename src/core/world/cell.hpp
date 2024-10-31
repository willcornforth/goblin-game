#pragma once
#include <vector>
#include <core/entities/entity.hpp>

class Cell {
public:
	Cell() {};

private:
	std::vector<Entity*> entities;
};