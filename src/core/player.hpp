#pragma once
#include "entity.hpp"

class Player : public Entity {
public:
	Player(Vector2D position) {
		std::unordered_map<AnimationActivity, int> animMapping = {
			{DOWN_MOVE, 0},
			{UP_MOVE, 1},
			{RIGHT_MOVE, 2},
			{LEFT_MOVE, 3},
			{IDLE, 0}
		};
		SpriteSheet* spriteSheet = new SpriteSheet(4, 6, 64, SPRITE_FILE_PATH, animMapping);

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
	const char* SPRITE_FILE_PATH = "player/soldier.png";

	float maxSpeed = 200.0f;
	float accelerationRate = 300.0f;
	float decelerationRate = 500.0f;
};