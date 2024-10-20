#pragma once
#include "entity.hpp"

class Particle : public Entity {
public:
	Particle(float _timeToDecay, Vector2D _position, float _frameTime = GetFrameTime())
		: Entity(_position) {
		timeToDecay = _timeToDecay;

		//SpriteSheet* spriteSheet =
		//	new SpriteSheet(8, 8, 100, SPRITE_FILE_PATH, animMapping);
		SpriteSheet* spriteSheet =
			new SpriteSheet(1, 5, 64, SPRITE_FILE_PATH);

		anim = new Animation(spriteSheet, _frameTime);
	}
	~Particle() {
		Entity::~Entity();
	}

	virtual void Render();
	virtual void Update();
	virtual void Destroy();

protected:
	float timeToDecay;

private:
	const char* SPRITE_FILE_PATH = "particle/fire_ball.png";
};