#pragma once
#include "entity.hpp"
#include "particle_animation.hpp"

class Particle : public Entity {
public:
	Particle(float _timeToDecay, Vector2D _position) : Entity(_position) {
		timeToDecay = _timeToDecay;

		std::unordered_map<AnimationActivity, int> animMapping = {
		{LOOP, 0}
		};

		SpriteSheet* spriteSheet =
			new SpriteSheet(8, 8, 100, SPRITE_FILE_PATH, animMapping);

		anim = new ParticleAnimation(spriteSheet);
	}

	virtual void Render();
	virtual void Update();
	virtual void Destroy();

protected:
	ParticleAnimation* anim;
	float timeToDecay;

private:
	const char* SPRITE_FILE_PATH = "particle/fancy_ring_blue.png";
};