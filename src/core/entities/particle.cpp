#include "particle.hpp"
#include <string>

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
	
	// Debug decay.
	//std::string temp = "Decay: " + std::to_string(timeToDecay);
	//DrawText(temp.data(), position.x, position.y - 5, 12, RAYWHITE);
}

void Particle::Destroy()
{
	Entity::Destroy();
}
