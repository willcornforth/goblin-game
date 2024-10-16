#pragma once
#include "actor.hpp"
#include "../animations/actor_animation.hpp"

class Goblin : public Actor {
private:
	static constexpr char* SPRITE_FILE_PATH = "goblin/goblin.png";
public:
	Goblin(Vector2D _position) : Actor(_position, new SpriteSheet(4, 8, 64, SPRITE_FILE_PATH, {
		{DOWN_MOVE, 0},
		{RIGHT_MOVE, 1},
		{UP_MOVE, 2},
		{LEFT_MOVE, 3},
		{IDLE, 0}
	})) {
	}
	~Goblin() {
		Actor::~Actor();
	}

	virtual void Update() override;
};