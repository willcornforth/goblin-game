#pragma once
#include "entity.hpp"

class Particle : public Entity {
public:
	Particle(float _timeToDecay, Vector2D _position) : Entity(_position) {
		timeToDecay = _timeToDecay;

		std::unordered_map<AnimationActivity, int> animMapping = {
		{LOOP, 0}
		};

		SpriteSheet* spriteSheet =
			new SpriteSheet(8, 8, 100, SPRITE_FILE_PATH, animMapping);

		anim = new Animation(spriteSheet);
	}

	virtual void Render();
	virtual void Update();
	virtual void Destroy();

protected:
	Animation* anim;
	float timeToDecay;

private:
	const char* SPRITE_FILE_PATH = "particle/fancy_ring_blue.png";
};