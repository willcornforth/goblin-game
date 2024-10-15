#pragma once
#include "entity.hpp"
#include "actor_animation.hpp"

class Player : public Entity {
public:
	Player(Vector2D _position) : Entity(_position) {
		std::unordered_map<AnimationActivity, int> animMapping = {
			{DOWN_MOVE, 0},
			{UP_MOVE, 1},
			{RIGHT_MOVE, 2},
			{LEFT_MOVE, 3},
			{IDLE, 0}
		};
		SpriteSheet* spriteSheet = 
			new SpriteSheet(4, 6, 64, SPRITE_FILE_PATH, animMapping);

		anim = new ActorAnimation(spriteSheet);
	}
	~Player() {
		Destroy();
		Entity::~Entity();
	}

	virtual void Update() override;
	virtual void Render();

private:
	const char* SPRITE_FILE_PATH = "player/soldier.png";

	float maxSpeed = 200.0f;
	float accelerationRate = 500.0f;
	float decelerationRate = 1000.0f;
};