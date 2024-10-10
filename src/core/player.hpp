#pragma once
#include "entity.hpp"

class Player : public Entity {
public:
	Player(
		Vector2 position,
		SpriteSheet* spriteSheet
	) {
		SetPosition(position);
		SetVelocity({ 0.f, 0.f });

		anim = new Animation(spriteSheet, 0.25f);
	}
	~Player() {
		Destroy();
	}

	void Update();
	void Render();
	void Destroy();

private:
	float maxSpeed = 200.0f;
	float accelerationRate = 300.0f;
	float decelerationRate = 500.0f;
};