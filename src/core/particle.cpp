#include "particle.hpp"

void Particle::Update()
{
	timeToDecay -= GetFrameTime();

	if (timeToDecay <= 0.f) {
		Destroy();
	}
	anim->Update(velocity);
}

void Particle::Render() {
	DrawTextureRec(
		anim->GetSpriteSheet()->GetTexture(),
		anim->GetCurrentAnimSpriteRect(),
		{ position.x, position.y },
		WHITE
	);
}

void Particle::Destroy()
{
	Entity::Destroy();
}
