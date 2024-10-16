#pragma once
#include "entity.hpp"
#include "../animations/actor_animation.hpp"

class Goblin : public Entity {
public:
	Goblin(Vector2D _position) : Entity(_position) {
		std::unordered_map<AnimationActivity, int> animMapping = {
		{DOWN_MOVE, 0},
		{RIGHT_MOVE, 1},
		{UP_MOVE, 2},
		{LEFT_MOVE, 3},
		{IDLE, 0}
		};
		SpriteSheet* spriteSheet =
			new SpriteSheet(4, 6, 64, SPRITE_FILE_PATH, animMapping);

		anim = new ActorAnimation(spriteSheet);
	}
	~Goblin() {
		Entity::~Entity();
	}

	virtual void Update() override;
	virtual void Render() override;

private:
	const char* SPRITE_FILE_PATH = "goblin/goblin.png";
};