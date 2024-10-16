#include "goblin.hpp"

void Goblin::Update() {


	anim->Update(velocity);
}

void Goblin::Render() {
	DrawTextureRec(
		anim->GetSpriteSheet()->GetTexture(),
		anim->GetCurrentAnimSpriteRect(),
		{ position.x, position.y },
		WHITE
	);
}