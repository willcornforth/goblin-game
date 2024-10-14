#include "entity.hpp"

void Entity::Destroy() {
	isDestroyed = true;
	anim->~Animation();
}