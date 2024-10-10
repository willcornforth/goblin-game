#pragma once
#include "entity.hpp"

class Player : public Entity {
public:
	Player(Vector2 position) {
		SetPosition(position);
		Init();
	}

	void Init();
	void Update();
	void Render();
	void Destroy();
};