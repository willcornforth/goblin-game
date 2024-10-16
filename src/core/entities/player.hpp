#pragma once
#include "actor.hpp"
#include "../animations/actor_animation.hpp"

class Player : public Actor {
private:
	static constexpr char* SPRITE_FILE_PATH = "player/soldier.png";

public:
	Player(Vector2D _position) : Actor(_position, new SpriteSheet(4, 6, 64, SPRITE_FILE_PATH, {
		{DOWN_MOVE, 0},
		{UP_MOVE, 1},
		{RIGHT_MOVE, 2},
		{LEFT_MOVE, 3},
		{IDLE, 0}
	})) {
		// Player init here.
	}
	~Player() {
		Destroy();
		Actor::~Actor();
	}

	virtual void Update() override;

private:
	float maxSpeed = 200.0f;
	float accelerationRate = 500.0f;
	float decelerationRate = 1000.0f;
};